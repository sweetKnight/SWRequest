//
//  SWBaseRequestModel.m
//  SWNetwork
//
//  Created by fengjianfeng on 2023/9/9.
//

#import "SWBaseRequestModel.h"
#import <objc/message.h>

@implementation SWBaseRequestModel

-(void)requestCompleteFilter{
    
    self.status = [[self.responseObject objectForKey:@"status"] integerValue];
    self.data = [self.responseObject objectForKey:@"data"];
    
    id data = self.data;
    if (self.status == 1) {//接口正常的情况
        if ([data isKindOfClass:[NSDictionary class]]){
            _modelHasData = [self yy_modelSetWithJSON:data];
        }else if([data isKindOfClass:[NSArray class]]){
            if (self.arrayItemClassName.length) {
                Class class = NSClassFromString(self.arrayItemClassName);
                _baseDataArray = [NSArray yy_modelArrayWithClass:class json:data];
            }else{
                _baseDataArray = [NSArray yy_modelArrayWithClass:self.class json:data];
            }
            _modelHasData = (_baseDataArray.count > 0);
        }else{
            _modelHasData = [self yy_modelSetWithJSON:data];//正常应该没有这种数据，
        }
    }else{
        SWErrorModel * errorM = [[SWErrorModel alloc]initWithDictionary:self.responseObject];
        errorM.errorState = SWErrorType_businessError;
        self.errorModel = errorM;
    }
}

-(void)requestFailureFilter{
    SWErrorModel * errorM = [[SWErrorModel alloc]initWithError:self.error];
    errorM.errorState = SWErrorType_businessError;
    self.errorModel = errorM;
}

//把SWBaseRequest所有属性都加到黑名单里。
+(NSArray<NSString *> *)modelPropertyBlacklist{
    NSMutableArray * backList = [[NSMutableArray alloc]init];
    
    unsigned int count = 0;
    Ivar *ivars = class_copyIvarList([SWBaseRequestModel class], &count);
    for (int i = 0; i < count; i ++) {
        Ivar ivar = ivars[i];
        const char *name = ivar_getName(ivar);
        NSString *nameStr = [NSString stringWithCString:name encoding:NSUTF8StringEncoding];
        [backList addObject:nameStr];
    }
    
    ivars = class_copyIvarList([SWBaseRequest class], &count);
    for (int i = 0; i < count; i ++) {
        Ivar ivar = ivars[i];
        const char *name = ivar_getName(ivar);
        NSString *nameStr = [NSString stringWithCString:name encoding:NSUTF8StringEncoding];
        [backList addObject:nameStr];
    }    
    free(ivars);
    return backList;
}

@end
