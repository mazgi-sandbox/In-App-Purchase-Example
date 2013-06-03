//
//  IAPProductType.h
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/4/13.
//
//

#import <Foundation/Foundation.h>

extern NSString * const IAPProductTypeKeyConsumable;
extern NSString * const IAPProductTypeKeyNonConsumable;
extern NSString * const IAPProductTypeKeyAutoRenewableSubscriptions;
extern NSString * const IAPProductTypeKeyFreeSubscription;
extern NSString * const IAPProductTypeKeyNonRenewingSubscription;

@interface IAPProductType : NSObject

@end
