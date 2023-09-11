//
//  SWBaseRequestModel.h
//  SWNetwork
//
//  Created by fengjianfeng on 2023/9/9.
//

#import "SWBaseRequest.h"
#import "NSObject+YYModel.h"
#import "SWErrorModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SWBaseRequestModel : SWBaseRequest<YYModel>

/** 状态码 */
@property (nonatomic, assign) NSInteger status;
/** 数据原型 */
@property (nonatomic, strong) id data;
/** 是否接收过数据 */
@property (nonatomic, assign) BOOL modelHasData;
/** 当data是数组的时候,已自身为数组里的类型，解出的集合 */
@property (nonatomic, strong) NSArray * baseDataArray;
/** 当data是数组的时候,可以通过外面传数组里对象的类 */
@property (nonatomic, copy) NSString * arrayItemClassName;
/** 接口错误信息 */
@property (nonatomic, strong) SWErrorModel * errorModel;

+(NSArray<NSString *> *)modelPropertyBlacklist;

@end

NS_ASSUME_NONNULL_END
