//
//  PiaSDK.h
//  Pia
//
//  Created by Luke on 07/08/2019.
//  Copyright © 2019 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NPIError.h"
#import "PiaSDKController.h"
#import "PiaSDKTheme.h"
#import "PaymentProcess.h"
#import "PaymentRegistration.h"
#import "CardScheme.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - PiaSDK API

@interface PiaSDK : NSObject

#pragma mark Theme

/// Excludes given set of card schemes from supported card scheme set.
/// @param excludeOptionSet list of card schemes to exclude.
+ (void)excludeCardSchemeOptionSet:(CardScheme)excludeOptionSet;

/// Set a `theme` for a given `interfaceStyle`.
+ (void)setTheme:(id<PiaSDKTheme> _Nonnull)theme
forInterfaceStyle:(UIUserInterfaceStyle)interfaceStyle API_AVAILABLE(ios(13.0));

/// Set a `theme`.
+ (void)setTheme:(id<PiaSDKTheme> _Nonnull)theme;

/// Returns the Nets standard theme for given `interfaceStyle`.
+ (id<PiaSDKTheme>)netsThemeCopyForInterfaceStyle:(UIUserInterfaceStyle)interfaceStyle API_AVAILABLE(ios(12.0));

/// Returns the Nets standard theme.
+ (id<PiaSDKTheme>)netsThemeCopy;

#pragma mark Payment

/// Attempts to initiate a wallet payment and returns `true` if wallet app is installed.
/// @param walletPaymentProcess An object representing SDK supported wallet
/// @param walletURLCallback Callback with `walletURL` following registration with merchant backend
/// @param redirectWithoutInterruption Invoked when wallet-app redirects or user manually returns to app
/// @param failure Invoked if wallet-payment fails with error
+ (BOOL)launchWalletAppForWalletPaymentProcess:(WalletPaymentProcess *)walletPaymentProcess
                             walletURLCallback:(WalletURLCallback)walletURLCallback
                   redirectWithoutInterruption:(WalletRedirectWithoutInterruption)redirectWithoutInterruption
                                       failure:(WalletFailureWithError)failure;

/// Returns SDK controller that presents the payment process to user
/// @param paymentProcess An object that identifies the payment process type
/// @param isCVCRequired Return according to configuration with Netaxept
/// @param transactionCallback Callback with result following registration with merchant backend
/// @param success Invoked if payment was completed with success. Commit payment following this.
/// @param cancellation Invoked if user cancelled the payment. Rollback payment following this.
/// @param failure Invoked if payment failed with an error. Rollback payment following this.
+ (UIViewController *)controllerForCardPaymentProcess:(CardPaymentProcess *)paymentProcess
                                        isCVCRequired:(BOOL)isCVCRequired
                                  transactionCallback:(TransactionCallback)transactionCallback
                                              success:(CompletionCallback)success
                                         cancellation:(CompletionCallback)cancellation
                                              failure:(FailureCompletionCallback)failure
__deprecated_msg("Use `PiaSDK.controller(for:success:cancellation:failure)` instead");


// NOTE: The API below should replace all card related payment APIs.
//          We don't need separate APIs, thats why we have the PaymentProcess object.

/// Returns SDK controller that presents the payment process to user
/// @param paymentProcess An object that identifies the payment process type
/// @param success Invoked if payment was completed with success. Commit payment following this.
/// @param cancellation Invoked if user cancelled the payment. Rollback payment following this.
/// @param failure Invoked if payment failed with an error. Rollback payment following this.
+ (UIViewController *)controllerForPaymentProcess:(PaymentProcess<PaymentRegistering> *)paymentProcess
                                          success:(PaymentProcessCompletion)success
                                     cancellation:(PaymentProcessCompletion)cancellation
                                          failure:(PaymentProcessFailure)failure;

/// Returns SDK controller that presents the payment process to user
/// @param paymentProcess An object that identifies the payment process type
/// @param isCVCRequired Return according to configuration with Netaxept
/// @param transactionCallback Callback with result following registration with merchant backend
/// @param success Invoked if payment was completed with success. Commit payment following this.
/// @param cancellation Invoked if user cancelled the payment. Rollback payment following this.
/// @param failure Invoked if payment failed with an error. Rollback payment following this.
+ (UIViewController *)controllerForSBusinessCardPaymentProcess:(CardPaymentProcess *)paymentProcess
                                                 isCVCRequired:(BOOL)isCVCRequired
                                           transactionCallback:(TransactionCallback)transactionCallback
                                                       success:(CompletionCallback)success
                                                  cancellation:(CompletionCallback)cancellation
                                                       failure:(FailureCompletionCallback)failure
__deprecated_msg("Use `PiaSDK.controller(for:success:cancellation:failure)` instead. Card payment and tokenization process can be set s-business initiated using the the `PaymentProcess` instance method `sBusiness()`. e.g. let cardProcess = CardPayment/CardStorage(…).sBusiness()");

/// Initiate payment with a stored card. If the payment requires 3DS authentication,
/// a webpage will be presented on the sender view controller.
///
/// It is recommended to show an activity indicator by passing `true` for `showsActivityIndicator`.
/// The same activity indicator can be presented using the API `showActivityIndicator(in:)`
/// while obtaining transaction ID from customer's merchant backend. The activity indicator will be
/// removed by the SDK before executing any of the completion blocks.
///
/// @param sender The `viewController` in which 3DS authentication is presented (if necessary)
/// @param isTestMode Is transaction to Netaxept test backend
/// @param showsActivityIndicator Show PiaSDK's standard activity indicator
/// @param merchantID Netaxept provided merchant ID
/// @param redirectURL Redirect URL used by 3DS to redirect user to the app
/// @param transactionID Transaction ID
/// @param success Success handler
/// @param cancellation Cancellation handler
/// @param failure Failure handler
///
+ (void)initiateTokenizedCardPayFrom:(UIViewController *)sender
                            testMode:(BOOL)isTestMode
              showsActivityIndicator:(BOOL)showsActivityIndicator
                          merchantID:(NSString *)merchantID
                         redirectURL:(NSString *)redirectURL
                       transactionID:(NSString *)transactionID
                             success:(void(^)(void))success
                        cancellation:(void(^)(void))cancellation
                             failure:(void(^)(NPIError * _Nonnull))failure
__deprecated_msg("Use `PiaSDK.initiateCardPayment(with:success:cancellation:failure)` instead");

/// Initiate payment with a stored card. If the payment requires 3DS authentication,
/// a webpage will be presented on the sender view controller.
///
/// @param tokenizedCardPayment Tokenized card payment process
/// @param success Success handler
/// @param cancellation Cancellation handler
/// @param failure Failure handler
///
+ (void)initiateCardPaymentWithTokenizedCardExpressCheckout:(TokenizedCardExpressCheckout *)tokenizedCardPayment
                                                    success:(PaymentProcessCompletion)success
                                               cancellation:(PaymentProcessCompletion)cancellation
                                                    failure:(PaymentProcessFailure)failure;

/// Returns SDK controller that presents the payment process to user
/// @param paymentProcess An object that identifies the payment process type
/// @param payPalRegistrationCallback Callback with result following registration with merchant backend
/// @param success Invoked if payment was completed with success. Commit payment following this.
/// @param cancellation Invoked if user cancelled the payment. Rollback payment following this.
/// @param failure Invoked if payment failed with an error. Rollback payment following this.
+ (UIViewController *)controllerForPayPalPaymentProcess:(PayPalPaymentProcess *)paymentProcess
                             payPalRegistrationCallback:(PayPalRegistrationCallback)payPalRegistrationCallback
                                                success:(CompletionCallback)success
                                           cancellation:(CompletionCallback)cancellation
                                                failure:(FailureCompletionCallback)failure
__deprecated_msg("Use `PiaSDK.controller(for:success:cancellation:failure)` instead");

/// Returns SDK controller that presents the payment process to user
/// @param paymentProcess An object that identifies the payment process type
/// @param paytrailRegistrationCallback Callback with result following registration with merchant backend
/// @param success Invoked if payment was completed with success. Commit payment following this.
/// @param cancellation Invoked if user cancelled the payment. Rollback payment following this.
/// @param failure Invoked if payment failed with an error. Rollback payment following this.
+ (UIViewController *)controllerForPaytrailPaymentProcess:(PaytrailPaymentProcess *)paymentProcess
                             paytrailRegistrationCallback:(PaytrailRegistrationCallback)paytrailRegistrationCallback
                                                  success:(CompletionCallback)success
                                             cancellation:(CompletionCallback)cancellation
                                                  failure:(FailureCompletionCallback)failure
__deprecated_msg("Use `PiaSDK.controller(for:success:cancellation:failure)` instead");

#pragma - mark Redirect From Wallet App

/// Notify SDK that app is opened from wallet app redirect.
/// @param redirectURL The redirect url received in `UIApplication:open url:options:`
/// @param options The options dictionary received in `UIApplication:open url:options:`
/// @return True if a redirect observer is registered with the SDK for the given `redirectURL`.
///     Returns `false` if URL query "wallet" in `redirectURL` does not match expected wallet name.
///
+ (BOOL)willHandleRedirectWith:(NSURL *)redirectURL andOptions:(NSDictionary *)options;

/// Show PiaSDK's standard transition view. User interaction within the bounds of
/// the transition view is absorbed.
/// Pass `UIApplication.shared.keyWindow.rootViewController` in order to block user-
/// interaction even in navigation bar button items.
/// @param viewController The view controller where transition view is added
///
+ (void)showActivityIndicatorIn:(UIViewController *)viewController
__deprecated_msg("Use `addTransitionViewIn:` instead");

/// Remove PiaSDK's standard activity indicator. User interaction in the
/// given `viewController` will be enabled and the activity indicator removed
///
+ (void)removeActivityIndicatorFrom:(UIViewController * _Nullable)viewController
__deprecated_msg("Use `removeTransitionView` instead");

/// Show PiaSDK's standard transition view. User interaction within the bounds of
/// the transition view is absorbed.
/// Pass `UIApplication.shared.keyWindow.rootViewController` in order to block user-
/// interaction even in navigation bar button items.
/// @param superView Super view for SDK's standard transition view with activity indicator.
///
+ (void)addTransitionViewIn:(UIView *)superView;

/// Removes PiaSDK's standard transition view (if found).
+ (void)removeTransitionView;

@end

NS_ASSUME_NONNULL_END

