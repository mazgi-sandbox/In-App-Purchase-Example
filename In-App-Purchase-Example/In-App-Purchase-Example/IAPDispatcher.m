//
//  IAPDispatcher.m
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/4/13.
//
//

#import "IAPDispatcher.h"
#import <StoreKit/StoreKit.h>

enum IAPDispatcherErrorCode {
    IAPDispatcherErrorCodeNoError = 0,
    IAPDispatcherErrorCodeCanNotMakePayments,
};

static NSString * const kIAPDispatcherErrorDomain = @"IAPDispatcherError";
static NSString * const kIAPDispatcherErrorUserInfoKeyReason = @"kIAPDispatcherStatusKeyPrepared";
static NSString * const kIAPDispatcherStatusAndReasonKeyPrepared = @"kIAPDispatcherStatusKeyPrepared";
@interface IAPDispatcher()
@property (strong, nonatomic) NSMutableDictionary *statuses;
@property (strong, nonatomic) NSMutableDictionary *reasons;
@end

@implementation IAPDispatcher

- (id)init
{
    self = [super init];
    if (self) {
        self.statuses = [NSMutableDictionary dictionary];
        self.reasons = [NSMutableDictionary dictionary];
    }
    return self;
}

- (void)prepare
{
    // can make payments?
    BOOL canMakePayments = [SKPaymentQueue canMakePayments];
    // reset status and push new status.
    [self.statuses setObject:[NSNumber numberWithBool:canMakePayments]
                      forKey:kIAPDispatcherStatusAndReasonKeyPrepared];
    if (!canMakePayments) {
        NSDictionary *userInfo = [NSDictionary dictionaryWithObject:@"Can not make payments."
                                                             forKey:kIAPDispatcherErrorUserInfoKeyReason];
        NSError *err = [NSError errorWithDomain:kIAPDispatcherErrorDomain
                                           code:IAPDispatcherErrorCodeCanNotMakePayments
                                       userInfo:userInfo];
        // reset reason and push error.
        [self.reasons setObject:[NSMutableArray arrayWithObject:err]
                         forKey:kIAPDispatcherStatusAndReasonKeyPrepared];
        if ([self.delegate respondsToSelector:@selector(dispatcher:didFailPrepare:withErrors:)]) {
            [self.delegate performSelector:@selector(dispatcher:didFailPrepare:withErrors:)
                                withObject:self
                                withObject:[self.reasons objectForKey:kIAPDispatcherStatusAndReasonKeyPrepared]];
        }
        return;
    }
}
@end
