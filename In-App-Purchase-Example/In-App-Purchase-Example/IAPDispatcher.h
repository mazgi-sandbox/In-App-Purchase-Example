/*!
 @header
 @abstract IAPDispatcher class header
 */

//
//  IAPDispatcher.h
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/4/13.
//
//

#import <Foundation/Foundation.h>

@class IAPDispatcher;

/*!
 @protocol
 @abstract IAPデリゲート
 @discussion IAPDispatcherからの通知を規定する.
 @dependency IAPDispatcher
 */
@protocol IAPDispatcherDelegate <NSObject>

@optional

/*!
 @functiongroup Prepare
 @method
 @abstract 事前処理終了通知(成功)
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishPrepare:(NSArray *)productList;
/*!
 @functiongroup Prepare
 @method
 @abstract 事前処理終了通知(失敗)
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailPrepare:(NSArray *)productList withErrors:(NSArray *)errors;

/*!
 @functiongroup Load products
 @method
 @abstract 商品一覧取得開始前通知
 @param dispatcher
 */
- (void)dispatcherWillStartLoadingProductList:(IAPDispatcher *)dispatcher;
/*!
 @functiongroup Load products
 @method
 @abstract 商品一覧取得開始後通知
 @param dispatcher
 */
- (void)dispatcherDidStartLoadingProductList:(IAPDispatcher *)dispatcher;
/*!
 @functiongroup Load products
 @method
 @abstract 商品一覧取得終了前通知
 @param dispatcher
 */
- (void)dispatcherWillFinishLoadingProductList:(IAPDispatcher *)dispatcher;
/*!
 @functiongroup Load products
 @method
 @abstract 商品一覧取得終了通知(成功)
 @param dispatcher
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishLoadingProductList:(NSArray *)productList;
/*!
 @functiongroup Load products
 @method
 @abstract 商品一覧取得終了通知(失敗)
 @param dispatcher
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailLoadingProductList:(NSArray *)productList withErrors:(NSArray *)errors;

/*!
 @functiongroup Purchase products
 @method
 @abstract 商品購入開始前通知
 @param dispatcher
 */
- (void)dispatcherWillStartPurchase:(IAPDispatcher *)dispatcher;
/*!
 @functiongroup Purchase products
 @method
 @abstract 商品購入開始後通知
 @param dispatcher
 */
- (void)dispatcherDidStartPurchase:(IAPDispatcher *)dispatcher;
/*!
 @functiongroup Purchase products
 @method
 @abstract 商品購入開始後通知
 @param dispatcher
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher willStartPurchaseWithProductIdentifier:(NSString *)productIdentifier;
/*!
 @functiongroup Purchase products
 @method
 @abstract 商品購入終了通知(成功)
 @param dispatcher
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishPurchaseProduct:(NSArray *)productList;
/*!
 @functiongroup Purchase products
 @method
 @abstract 商品購入終了通知(失敗)
 @param dispatcher
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailPurchaseProduct:(NSArray *)productList withErrors:(NSArray *)errors;

@end

/*!
 @class
 @abstract IAP実行クラス
 @discussion
 <dl>
 <dt>ライフサイクル／寿命</dt>
 <dd>決済画面遷移時に生成され、決済後または他画面に遷移後破棄されることを想定する.<dd>
 <dt>行うこと</dt>
 <dd>与えられた商品IDによる決済</dd>
 <dt>行わないこと</dt>
 <dd>描画</dd>
 <dd>StoreKitに含まれない通信</dd>
 </dl>
 */
@interface IAPDispatcher : NSObject
{
    BOOL inProgress;
}

- (BOOL)addProductIdentifier:(NSString *)productIdentifier;

/*!
 @method
 @abstract 前処理
 @discussion
 <dl>
    <dt>行うこと</dt>
    <dd>決済可能か検証する(iOS端末の設定で決済が許可されているか)</dd>
    <dt>行わないこと</dt>
    <dd>商品の取得</dd>
    <dd>決済</dd>
 </dl>
 */
- (void)prepare;
/*!
 @method
 @abstract 商品一覧を取得する
 @discussion
 <dl>
    <dt>行うこと</dt>
    <dd>商品の取得</dd>
    <dt>行わないこと</dt>
    <dd>決済</dd>
 </dl>
 */
- (void)loadProducts:(NSArray *)productList;
/*!
 @method
 @abstract 決済を行う
 @discussion
 <dl>
    <dt>行うこと</dt>
    <dd>決済</dd>
    <dt>行わないこと</dt>
    <dd>商品の取得</dd>
 </dl>
 */
- (void)purchaseProduct;
@property (weak, nonatomic) id<IAPDispatcherDelegate> delegate;
@property (readonly, nonatomic) NSArray *validProducts;
@property (readonly, nonatomic) NSArray *invalidProducts;
@end
