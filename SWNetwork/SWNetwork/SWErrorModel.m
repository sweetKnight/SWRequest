//
//  SWErrorModel.m
//  SWNetwork
//
//  Created by fengjianfeng on 2023/9/11.
//

#import "SWErrorModel.h"

@implementation SWErrorModel

-(instancetype)initWithDictionary:(NSDictionary *)dic{
    self = [super init];
    if (self) {
        [self yy_modelSetWithDictionary:dic];
        _originalData = dic;
    }
    return self;
}

-(instancetype)initWithError:(NSError *)error{
    self = [super init];
    if (self) {
        if (error.code > 0) {
            _errorState = SWErrorType_serverError;
            _message = @"服务器失联了，我们正在抓紧恢复中";
        }else{
            _errorState = SWErrorType_noNet;
            _message = @"网络加载失败，请检查网络";
        }
    }
    return self;
}

@end
