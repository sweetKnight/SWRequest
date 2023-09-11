//
//  SWBaseRequst.h
//  SWNetwork
//
//  Created by fengjianfeng on 2023/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//请求方式
typedef NS_ENUM(NSInteger, SWRequestMethod) {
    SWRequestMethodGET = 0,
    SWRequestMethodPOST,
    SWRequestMethodHEAD,
    SWRequestMethodPUT,
    SWRequestMethodDELETE,
    SWRequestMethodPATCH,
};

//请求参数格式
typedef NS_ENUM(NSInteger, SWRequestSerializerType) {
    SWRequestSerializerTypeHTTP = 0,
    SWRequestSerializerTypeJSON,
};

//AF关于上传文件相关的代码
@protocol AFMultipartFormData;
typedef void (^AFConstructingBlock)(id<AFMultipartFormData> formData);
typedef void (^AFURLSessionTaskProgressBlock)(NSProgress *);

//接口完成回调代理
@protocol SWRequestDelegate;
//接口生命周期代理
@protocol SWRequestLifeCycleDelegate;

@interface SWBaseRequest : NSObject


#pragma mark - Request and Response Information
/** 请求任务 */
@property (nonatomic, strong) NSURLSessionTask *requestTask;
/** 当前请求 */
@property (nonatomic, strong, readonly) NSURLRequest *currentRequest;
 /** 返回值 */
@property (nonatomic, strong, readonly) NSHTTPURLResponse *response;
 /** 接口返回的参数 */
@property (nonatomic, strong, nullable) id responseObject;
 /** 接口报错信息 */
@property (nonatomic, strong, nullable) NSError *error;
 /** tag标识 */
@property (nonatomic) NSInteger tag;
 /** 接口回调代理 */
@property (nonatomic, weak, nullable) id<SWRequestDelegate> delegate;
 /** 生命周期代理 */
@property (nonatomic, weak, nullable) id<SWRequestLifeCycleDelegate> lifeCycleDelegate;
 /** 上传文件 */
@property (nonatomic, copy, nullable) AFConstructingBlock uploadBodyBlock;
/** 上传进度 */
@property (nonatomic, copy, nullable) AFURLSessionTaskProgressBlock uploadProgressBlock;
/** 下载文件路径 */
@property (nonatomic, strong, nullable) NSString *downloadPath;
 /** 下载进度 */
@property (nonatomic, copy, nullable) AFURLSessionTaskProgressBlock downloadProgressBlock;

#pragma mark - 外部调用
//开始
- (void)start;
//停止
- (void)stop;

#pragma mark - 子类重写，设置request
//url不变的部分，一般写入host
- (NSString *)baseUrl;

//回合baseUrl拼接一下
- (NSString *)requestUrl;

//超时时间设置，默认60s
- (NSTimeInterval)requestTimeoutInterval;

//请求参数
- (nullable id)requestArgument;

//请求类型
- (SWRequestMethod)requestMethod;

//请求参数类型
- (SWRequestSerializerType)requestSerializerType;

//请求头
- (nullable NSDictionary<NSString *, NSString *> *)requestHeaderFieldValueDictionary;

//接口成功，未调用回调的时候
- (void)requestCompleteFilter;
//接口失败，未调用回调的时候
- (void)requestFailureFilter;

@end

@protocol SWRequestDelegate <NSObject>
@optional
//接口成功回调
-(void)requestFinished:(__kindof SWBaseRequest *)request;
//接口失败回调
-(void)requestFailed:(__kindof SWBaseRequest *)request;
@end

@protocol SWRequestLifeCycleDelegate <NSObject>
@optional
//将要开始
-(void)requestWillStart:(id)request;
//将要结束
-(void)requestWillStop:(id)request;
//已经结束
-(void)requestDidStop:(id)request;

@end

NS_ASSUME_NONNULL_END
