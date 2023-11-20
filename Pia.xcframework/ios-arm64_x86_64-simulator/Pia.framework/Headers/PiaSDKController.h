//
//  PiaSDK.h
//  Pia
//
//  Created by Triet Le on 21/06/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NPIMerchantInfo.h"
#import "NPITransactionInfo.h"
#import "NPIError.h"
#import "NPIOrderInfo.h"
#import "NPITokenCardInfo.h"
#import "NPIApplePayInfo.h"
#import <PassKit/PassKit.h>

@class PiaSDKController;

/**
 The PiaSDK protocol provides a mechanism for your application to take
 action on events that occur in both payment and saving card processes. You can make
 use of these calls by assigning an object to the PiaSDK' delegate property directly.
 */
__deprecated_msg("Migrate to declarative APIs in PiaSDK namespace")
@protocol PiaSDKDelegate <UINavigationControllerDelegate>

@required
/**
 Before the actual payment, the app should register the payment in it's own backend. This method will get called when the sdk needs the app to do that.
 @param storeCard Boolean value determines if card should be saved for later uses (chosen by user). Note: this value will always be TRUE if process is saving card
 */
- (void)doInitialAPICall:(PiaSDKController *_Nonnull)piaSDKController storeCard:(BOOL)storeCard withCompletion:(void (^_Nonnull)(NPITransactionInfo *_Nullable transactionInfo))completionHandler;

/**
 This method will get called if the chosen payment type will be PayPal.
 */
- (void)registerPaymentWithPayPal:(PiaSDKController *_Nonnull)piaSDKController withCompletion:(void (^_Nonnull)(NPITransactionInfo *_Nullable transactionInfo))completionHandler;

/**
 This method will get called if the chosen payment type will be Finnish bank payment.
 */
- (void)registerPaymentWithPaytrail:(PiaSDKController * _Nonnull)piaSDKController
                     withCompletion:(void (^ _Nonnull)(NPITransactionInfo * _Nullable))completionHandler;

/**
 Will get called if, for whatever reason, the payment process fails. Check the error code to see what went wrong (both saving card and payment).
 */
- (void)PiaSDK:(PiaSDKController *_Nonnull)piaSDKController didFailWithError:(NPIError *_Nonnull)error;
/**
 Will get called if payment process goes well.
 */
- (void)PiaSDKDidCompleteWithSuccess:(PiaSDKController *_Nonnull)piaSDKController;
/**
 Will get called if saving card process goes well.
 */
- (void)PiaSDKDidCompleteSaveCardWithSuccess:(PiaSDKController *_Nonnull)piaSDKController;
/**
 Will get called if user decides to cancel the process (both saving card and payment)
 */
- (void)PiaSDKDidCancel:(PiaSDKController *_Nonnull)piaSDKController;

@optional
/**
 Will get called if user decides to change the shipping contact inside Apple Pay process
 @param contact PKContact object returned by Apple Pay after user changed the shipping contact
 */
- (void)PiaSDK:(PiaSDKController *_Nonnull)piaSDKController didChangeApplePayShippingContact:(PKContact *_Nonnull)contact withCompletion:(void (^_Nonnull)(BOOL result, NSDecimalNumber *_Nullable newApplePayItemShippingCost))completionHandler;
@end

/**
 @class Controller that handles both payment and saving card process
 */
__deprecated_msg("Migrate to declarative APIs in PiaSDK namespace")
@interface PiaSDKController : UINavigationController

@property (nonatomic, weak) id<PiaSDKDelegate> _Nullable piaDelegate;
@property (nonatomic, strong) id<PiaSDKDelegate> _Nullable strongPiaDelegate;


/**
 @param merchantInfo (Nullable) Data that uniquely identifies the merchant
 @param orderInfo (Nullable) Object that describes the amount to be paid - Set this object to nil if the process is saving card.
 @param tokenCardInfo (Nullable) Object that provides SDK information about Saved/Registered cards - Set this object if process is Easy payment
 @param applePayInfo Do not use this initialiser for Apple Pay. This object is deprecated!
 @param performingPayPalPurchase Object that says if the payment is going to happen through PayPal or not
 */
- (instancetype _Nonnull)init:(NPIMerchantInfo *_Nullable)merchantInfo
                    orderInfo:(NPIOrderInfo *_Nullable)orderInfo
                tokenCardInfo:(NPITokenCardInfo *_Nullable)tokenCardInfo
                 applePayInfo:(NPIApplePayInfo *_Nullable)applePayInfo
     performingPayPalPurchase:(BOOL)performingPayPalPurchase;

/**
 @param merchantInfo (Nullable) Data that uniquely identifies the merchant
 @param orderInfo (Nullable) Object that describes the amount to be paid - Set this object to nil if the process is saving card.
 @param tokenCardInfo (Nullable) Object that provides SDK information about Saved/Registered cards - Set this object if process is Easy payment
 */
- (instancetype _Nonnull)initWithMerchantInfo:(NPIMerchantInfo *_Nullable)merchantInfo
                                    orderInfo:(NPIOrderInfo *_Nullable)orderInfo
                                tokenCardInfo:(NPITokenCardInfo *_Nullable)tokenCardInfo;

/**
 @param merchantInfo (Nullable) Data that uniquely identifies the merchant
 @param orderInfo (Nullable) Object that describes the amount to be paid - Set this object to nil if the process is saving card.
 @param tokenCardInfo (Nullable) Object that provides SDK information about Saved/Registered cards - Set this object if process is Easy payment
 */
- (instancetype _Nonnull)initWithTokenCardInfo:(NPITokenCardInfo *_Nonnull)tokenCardInfo
                                  merchantInfo:(NPIMerchantInfo *_Nonnull)merchantInfo
                                     orderInfo:(NPIOrderInfo *_Nonnull)orderInfo;

/// Initiate payment with a stored card
/// @param testMode Should transaction be towards Netaxept test environment
/// @param tokenCardInfo Object containing stored card details
/// @param merchantID Netaxept provided merchant ID
/// @param orderInfo Order details
/// @param requireCardConfirmation Should user confirm the card (Note: this value
/// is overridden to true if CVC is required)
///
- (instancetype _Nonnull)initWithTestMode:(BOOL)testMode
                            tokenCardInfo:(NPITokenCardInfo * _Nonnull)tokenCardInfo
                               merchantID:(NSString * _Nonnull)merchantID
                                orderInfo:(NPIOrderInfo * _Nonnull)orderInfo
                  requireCardConfirmation:(BOOL)requireCardConfirmation;

/**
 @param merchantInfo (NonNull) Data that uniquely identifies the merchant
 @param orderInfo (Nullable) Object that describes the amount to be paid - Set this object to nil if the process is saving card.
 */
- (instancetype _Nonnull)initWithOrderInfo:(NPIOrderInfo *_Nullable)orderInfo merchantInfo:(NPIMerchantInfo *_Nonnull)merchantInfo;

/**
@param merchantInfo (Nullable) Data that uniquely identifies the merchant
 */
- (instancetype _Nonnull)initForPayPalPurchaseWithMerchantInfo:(NPIMerchantInfo *_Nonnull)merchantInfo;

/**
 @param merchantInfo (Nullable) Data that uniquely identifies the merchant
 @param payWithPayPal Whether to use PayPal flow or not
 */
- (instancetype _Nonnull)initWithMerchantInfo:(NPIMerchantInfo *_Nonnull)merchantInfo payWithPayPal:(BOOL)payWithPayPal;

/**
 @param applePayInfo (Nullable) Object that provides SDK information about Apple Pay
 */
- (instancetype _Nonnull)initWithApplePayInfo:(NPIApplePayInfo *_Nonnull)applePayInfo;

/**
 @param merchantInfo (Nullable) Data that uniquely identifies the merchant
 */
- (instancetype _Nonnull)initWithMerchantInfo:(NPIMerchantInfo *_Nonnull)merchantInfo;

/**
 @param merchantID String that uniquely identifies the merchant
 @param transactionInfo (Nullable) Data which gives detail for transaction
 @param testMode Bool that specifies test/prod environment
 */
- (instancetype _Nonnull)initPaytrailBankPaymentWithMerchantID:(NSString *_Nonnull)merchantID transactionInfo:(NPITransactionInfo *_Nonnull)transactionInfo testMode:(BOOL)testMode;

/**
 @param merchantInfo (NonNull) Data that uniquely identifies the merchant
 */
- (instancetype _Nonnull)initPaytrailBankPaymentWithMerchantInfo:(NPIMerchantInfo * _Nonnull)merchantInfo;

/**
 @param merchantInfo (NonNull) Data that uniquely identifies the merchant
 */
- (instancetype _Nonnull)initSBusinessCardPaymentWithMerchantInfo:(NPIMerchantInfo * _Nonnull)merchantInfo orderInfo:(NPIOrderInfo *_Nullable)orderInfo;

@end
