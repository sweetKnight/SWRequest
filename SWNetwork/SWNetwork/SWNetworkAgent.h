//
//  SWNetworkAgent.h
//  SWNetwork
//
//  Created by fengjianfeng on 2023/5/8.
//  实际发起请求的类

#import <Foundation/Foundation.h>
#import "SWBaseRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface SWNetworkAgent : NSObject

+(SWNetworkAgent *)sharedAgent;
-(void)addRequest:(SWBaseRequest *)request;
-(void)cancelRequest:(SWBaseRequest *)request;
-(void)cancelAllRequests;

@end

NS_ASSUME_NONNULL_END
