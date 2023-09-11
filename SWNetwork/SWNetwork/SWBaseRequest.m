//
//  SWBaseRequst.m
//  SWNetwork
//
//  Created by fengjianfeng on 2023/5/8.
//

#import "SWBaseRequest.h"
#import "SWNetworkAgent.h"

@implementation SWBaseRequest

- (void)start {
    if([_lifeCycleDelegate respondsToSelector:@selector(requestWillStart:)]){
        [_lifeCycleDelegate requestWillStart:self];
    }
    [[SWNetworkAgent sharedAgent] addRequest:self];
}

- (void)stop {
    if([_lifeCycleDelegate respondsToSelector:@selector(requestWillStop:)]){
        [_lifeCycleDelegate requestWillStop:self];
    }
    self.delegate = nil;
    [[SWNetworkAgent sharedAgent] cancelRequest:self];
    if([_lifeCycleDelegate respondsToSelector:@selector(requestDidStop:)]){
        [_lifeCycleDelegate requestDidStop:self];
    }
}

- (NSURLRequest *)currentRequest {
    return self.requestTask.currentRequest;
}

- (NSHTTPURLResponse *)response {
    return (NSHTTPURLResponse *)self.requestTask.response;
}

- (NSString *)requestUrl {
    return @"";
}

- (NSString *)cdnUrl {
    return @"";
}

- (NSString *)baseUrl {
    return @"";
}

- (NSTimeInterval)requestTimeoutInterval {
    return 60;
}

- (id)requestArgument {
    return nil;
}

- (SWRequestMethod)requestMethod {
    return SWRequestMethodPOST;
}

- (SWRequestSerializerType)requestSerializerType {
    return SWRequestSerializerTypeHTTP;
}

- (NSDictionary *)requestHeaderFieldValueDictionary {
    return nil;
}

#pragma mark - NSObject

- (NSString *)description {
    return [NSString stringWithFormat:@"<%@: %p>{ URL: %@ } { method: %@ } { arguments: %@ }", NSStringFromClass([self class]), self, self.currentRequest.URL, self.currentRequest.HTTPMethod, self.requestArgument];
}


@end
