//
//  SWErrorModel.h
//  SWNetwork
//
//  Created by fengjianfeng on 2023/9/11.
//

#import <Foundation/Foundation.h>
#import "NSObject+YYModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, SWErrorType){
    SWErrorType_noNet,//用户网络本身有问题
    SWErrorType_serverError,//用户网络没问题，服务器有问题
    SWErrorType_businessError//接口通了state不为1，业务错误
};

@interface SWErrorModel : NSObject<YYModel>

/** 报错的类型 */
@property (nonatomic, assign) SWErrorType errorState;
/** 业务状态码*/
@property (nonatomic, copy) NSString * errType;
/** 报错信息 */
@property (nonatomic, copy) NSString * message;

/** 业务错误时的原始数据 */
@property (nonatomic, strong) NSDictionary * originalData;

-(instancetype)initWithDictionary:(NSDictionary *)dic;
-(instancetype)initWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
