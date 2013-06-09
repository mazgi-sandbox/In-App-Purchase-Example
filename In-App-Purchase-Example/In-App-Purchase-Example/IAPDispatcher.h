//
//  IAPDispatcher.h
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/4/13.
//
//

#import <Foundation/Foundation.h>

@class IAPDispatcher;

@protocol IAPDispatcherDelegate <NSObject>

@optional

// load products
/*!
 @method
 @param dispatcher 
 */
- (void)dispatcherWillStartLoadingProductList:(IAPDispatcher *)dispatcher;
- (void)dispatcherDidStartLoadingProductList:(IAPDispatcher *)dispatcher;
- (void)dispatcherWillFinishLoadingProductList:(IAPDispatcher *)dispatcher;
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishLoadingProductList:(NSArray *)productList;
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailLoadingProductList:(NSArray *)productList withErrors:(NSError *)errors;

// purchase
- (void)dispatcherWillStartPurchase:(IAPDispatcher *)dispatcher;

- (void)dispatcher:(IAPDispatcher *)dispatcher willStartPurchaseWithProductIdentifier:(NSString *)dispatcher;
- (void)dispatcherDidStartLoadingProductList:(IAPDispatcher *)dispatcher;
- (void)dispatcherWillFinishLoadingProductList:(IAPDispatcher *)dispatcher;
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishLoadingProductList:(NSArray *)productList;
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailLoadingProductList:(NSArray *)productList withErrors:(NSError *)errors;

// send receipt

@end

@interface IAPDispatcher : NSObject
- (void)prepare;
- (void)loadProducts;
- (void)purchaseProduct;
@property (weak, nonatomic) id<IAPDispatcherDelegate> delegate;
@end
