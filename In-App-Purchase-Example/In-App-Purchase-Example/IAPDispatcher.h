/*!
 @header
 @abstract In-App Purchase Dispatcher
 @copyright Hidenori MATSUKI
 @author Hidenori MATSUKI
 @updated 2013-06-04
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
 @abstract IAPデリゲート
 @discussion IAPDispatcherからの通知を規定する.
 @dependency IAPDispatcher
 */
@protocol IAPDispatcherDelegate <NSObject>

@optional

#pragma mark - Prepare

/*!
 @methodgroup Prepare
 */

/*!
 @abstract 事前処理終了通知(成功)
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishPrepare:(NSArray *)productList;

/*!
 @method
 @abstract 事前処理終了通知(失敗)
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailPrepare:(NSArray *)productList withErrors:(NSArray *)errors;

#pragma mark - Load products

/*!
 @methodgroup Load products
 */

/*!
 @method
 @abstract 商品一覧取得開始前通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcherWillStartLoadingProductList:(IAPDispatcher *)dispatcher;

/*!
 @method
 @abstract 商品一覧取得開始後通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcherDidStartLoadingProductList:(IAPDispatcher *)dispatcher;
/*!
 @method
 @abstract 商品一覧取得終了前通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcherWillFinishLoadingProductList:(IAPDispatcher *)dispatcher;
/*!
 @method
 @abstract 商品一覧取得終了通知(成功)
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishLoadingProductList:(NSArray *)productList;
/*!
 @method
 @abstract 商品一覧取得終了通知(失敗)
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFailLoadingProductList:(NSArray *)productList withErrors:(NSArray *)errors;

#pragma mark - Purchase products

/*!
 @methodgroup Purchase products
 */

/*!
 @method
 @abstract 商品購入開始前通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcherWillStartPurchase:(IAPDispatcher *)dispatcher;
/*!
 @method
 @abstract 商品購入開始後通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcherDidStartPurchase:(IAPDispatcher *)dispatcher;
/*!
 @method
 @abstract 商品購入開始後通知
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher willStartPurchaseWithProductIdentifier:(NSString *)productIdentifier;
/*!
 @method
 @abstract 商品購入終了通知(成功)
 @param dispatcher IAP実行クラス
 */
- (void)dispatcher:(IAPDispatcher *)dispatcher didFinishPurchaseProduct:(NSArray *)productList;
/*!
 @method
 @abstract 商品購入終了通知(失敗)
 @param dispatcher IAP実行クラス
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

/*!
 @method
 @abstract 商品IDを追加する
 @param productIdentifier 追加する商品ID
 */
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
 @param productList 商品ID一覧
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
