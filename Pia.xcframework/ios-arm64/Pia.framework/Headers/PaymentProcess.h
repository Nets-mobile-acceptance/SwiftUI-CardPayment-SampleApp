//
//  PaymentProcess.h
//  Pia
//
//  Created by Luke on 14.9.2020.
//  Copyright © 2020 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaymentRegistration.h"
#import "NPITokenCardInfo.h"
#import "CardScheme.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark MerchantDetails

/// An object containing Netaxept provided merchant ID for test/production environment.
@interface MerchantDetails : NSObject
@property(nonatomic) NSString *merchantID;
@property(nonatomic) BOOL isTest;

- (instancetype)init NS_UNAVAILABLE;
+ (MerchantDetails *)merchantWithID:(NSString *)merchantID inTest:(BOOL)isTest;

@end

#pragma mark PaymentProcess (Abstract)

/// A namespace containing factories used to construct parameter list
/// required to initiate a given payment process.
@interface PaymentProcess : NSObject
@end

@protocol PaymentRegistering <NSObject>
@required
@property(nonatomic) id registrationCallback;
@end



#pragma mark CardPaymentProcess (Abstract)

/// An abstract superclass for `CardStorage` and `CardPayment` processes.
@interface CardPaymentProcess : PaymentProcess<PaymentRegistering>
@property(nonatomic) MerchantDetails *merchant;
@property(nonatomic) id registrationCallback;
@end

#pragma mark CardStorage

/// An object containing parameter list for card-storage process.
@interface CardStorage : CardPaymentProcess
- (instancetype)init NS_UNAVAILABLE;

- (CardStorage *)sBusiness;
@end

#pragma mark CardPayment

typedef NSString * Currency; // TODO: Check if this can be pre-defined list

/// An object containing parameter list for card-payment process.
@interface CardPayment : CardPaymentProcess
@property(nonatomic) NSUInteger amount;
@property(nonatomic) Currency currency;

- (instancetype)init NS_UNAVAILABLE;

- (CardPayment *)sBusiness;
@end

BOOL isSBusinessInitiated(CardPaymentProcess * cardProcess);

#pragma mark Tokenized Card Payment

#pragma - Card Confirmation Type

@interface TokenizedCardPrompt : NSObject
- (BOOL)shouldPromptCVC;
@end

@interface TokenizedCardPromptNone : TokenizedCardPrompt
@end

@interface TokenizedCardPromptConfirmation : TokenizedCardPrompt
@property(nonatomic) NSUInteger amount;
@property(nonatomic) Currency currency;
@property(nonatomic) BOOL shouldPromptCVC;

- (instancetype)init NS_UNAVAILABLE;
@end

@interface TokenizedCardPrompt ()
@property(nonatomic, readonly, class) TokenizedCardPromptNone * none;

+ (TokenizedCardPromptConfirmation *)forAmount:(NSUInteger)amount
                                      currency:(Currency)currency
                               shouldPromptCVC:(BOOL)shouldPromptCVC;
@end

#pragma - Tokenized Card

/// An object containing parameter list for tokenized-card-payment process.
@interface TokenizedCardPayment : CardPaymentProcess
@property(nonatomic) NSString * token;
@property(nonatomic) CardDisplay * cardDisplay;
@property(nonatomic) NSString * expiryDate;
@property(nonatomic) TokenizedCardPrompt * confirmatioPrompt;

- (instancetype)init NS_UNAVAILABLE;
@end

#pragma - TokenizedCardExpressCheckout

/// An object containing parameter list for tokenized-card-payment process.
@interface TokenizedCardExpressCheckout : PaymentProcess
@property(nonatomic) UIViewController * sender;
@property(nonatomic) MerchantDetails *merchant;
@property(nonatomic) TransactionID transactionID;
@property(nonatomic) NSURL * redirectURL;

- (instancetype)init NS_UNAVAILABLE;
@end

#pragma mark WalletPaymentProcess

typedef NS_CLOSED_ENUM(NSUInteger, Wallet) {
    WalletSwish,
    WalletVipps, WalletVippsTest,
    WalletMobilePay, WalletMobilePayTest
};

@interface WalletPaymentProcess : PaymentProcess
@property(nonatomic) Wallet wallet;
@property(nonatomic) BOOL showActivityIndicator;

- (instancetype)init NS_UNAVAILABLE;
@end


/// An object containing parameter list for paypal-payment process.
@interface PayPalPaymentProcess : PaymentProcess<PaymentRegistering>
@property(nonatomic) MerchantDetails *merchant;
- (instancetype)init NS_UNAVAILABLE;
@end

/// An object containing parameter list for paytrail-payment process.
@interface PaytrailPaymentProcess : PaymentProcess<PaymentRegistering>
@property(nonatomic) MerchantDetails * merchant;
- (instancetype)init NS_UNAVAILABLE;
@end

#pragma mark PaymentProcess + Factories

@interface PaymentProcess ()
/// Returns object containing required parameter list for card-storage process.
/// @param merchant The merchant details obtained from Netaxept
+ (CardStorage *)cardStorageWithMerchant:(MerchantDetails *)merchant;
/// Returns object containing required parameter list for card-storage process.
/// @param merchant The merchant details obtained from Netaxept
+ (CardStorage *)cardStorageWithMerchant:(MerchantDetails *)merchant
                    registrationCallback:(CardRegistrationCallback)registrationCallback;

/// Returns object containing required parameter list for card-storage process.
/// @param merchant The merchant details obtained from Netaxept
/// @param excludedCardSchemeSet Set of card schemes that should not be supported
+ (CardStorage *)cardStorageWithMerchant:(MerchantDetails *)merchant
                   excludedCardSchemeSet:(CardScheme)excludedCardSchemeSet;
/// Returns object containing required parameter list for card-storage process.
/// @param merchant The merchant details obtained from Netaxept
/// @param excludedCardSchemeSet Set of card schemes that should not be supported
+ (CardStorage *)cardStorageWithMerchant:(MerchantDetails *)merchant
                   excludedCardSchemeSet:(CardScheme)excludedCardSchemeSet
                    registrationCallback:(CardRegistrationCallback)registrationCallback;

/// Returns object containing required parameter list for card-payment process.
/// @param merchant The merchant details obtained from Netaxept
/// @param amount Amount of payment in cents
/// @param currency Currency code following iSO 4217
+ (CardPayment *)cardPaymentWithMerchant:(MerchantDetails *)merchant
                                  amount:(NSUInteger)amount
                                currency:(Currency)currency;

/// Returns object containing required parameter list for card-payment process.
/// @param merchant The merchant details obtained from Netaxept
/// @param excludedCardSchemeSet Set of card schemes that should not be supported
/// @param amount Amount of payment in cents
/// @param currency Currency code following iSO 4217
+ (CardPayment *)cardPaymentWithMerchant:(MerchantDetails *)merchant
                   excludedCardSchemeSet:(CardScheme)excludedCardSchemeSet
                                  amount:(NSUInteger)amount
                                currency:(Currency)currency;
/// Returns object containing required parameter list for card-payment process.
/// @param merchant The merchant details obtained from Netaxept
/// @param excludedCardSchemeSet Set of card schemes that should not be supported
/// @param amount Amount of payment in cents
/// @param currency Currency code following iSO 4217
+ (CardPayment *)cardPaymentWithMerchant:(MerchantDetails *)merchant
                   excludedCardSchemeSet:(CardScheme)excludedCardSchemeSet
                                  amount:(NSUInteger)amount
                                currency:(Currency)currency
                    registrationCallback:(TokenizableCardRegistrationCallback)registrationCallback;
/// Returns object containing required parameter list for card-payment process.
/// @param merchant The merchant details obtained from Netaxept
/// @param amount Amount of payment in cents
/// @param currency Currency code following iSO 4217
+ (CardPayment *)cardPaymentWithMerchant:(MerchantDetails *)merchant
                                  amount:(NSUInteger)amount
                                currency:(Currency)currency
                    registrationCallback:(TokenizableCardRegistrationCallback)registrationCallback;


+ (TokenizedCardPayment *)tokenizedCardPaymentWithMerchant:(MerchantDetails *)merchant
                                                     token:(NSString *)token
                                                expiryDate:(NSString *)expiryDate
                                               cardDisplay:(CardDisplay *)cardDisplay
                                        confirmationPrompt:(TokenizedCardPrompt *)confirmationPrompt
                                      registrationCallback:(CardRegistrationCallback)registrationCallback;

+ (TokenizedCardExpressCheckout *)tokenizedCardExpressCheckoutFrom:(UIViewController *)sender
                                                          merchant:(MerchantDetails *)merchant
                                                     transactionID:(TransactionID)transactionID
                                                       redirectURL:(NSURL *)redirectURL;


/// Returns object containing required parameter list for wallet-payment process.
/// @param wallet A supported wallet by the SDK
+ (WalletPaymentProcess *)walletPaymentForWallet:(Wallet)wallet;

/// Returns object containing required parameter list for wallet-payment process.
/// @param wallet A supported wallet by the SDK
/// @param showActivityIndicator Pass `true` to show SDK standard activity indicator during the process.
+ (WalletPaymentProcess *)walletPaymentForWallet:(Wallet)wallet
                           showActivityIndicator:(BOOL)showActivityIndicator;

/// Returns object containing required parameter list for paypal payment process.
/// @param merchant The merchant details obtained from Netaxept
+ (PayPalPaymentProcess *)payPalPaymentWithMerchant:(MerchantDetails *)merchant;
/// Returns object containing required parameter list for paypal payment process.
/// @param merchant The merchant details obtained from Netaxept
+ (PayPalPaymentProcess *)payPalPaymentWithMerchant:(MerchantDetails *)merchant
                               registrationCallback:(PayPalRegistrationCallback)registrationCallback;

/// Returns object containing required parameter list for paytrail payment process.
/// @param merchant The merchant details obtained from Netaxept
+ (PaytrailPaymentProcess *)paytrailPaymentWithMerchant:(MerchantDetails *)merchant;
/// Returns object containing required parameter list for paytrail payment process.
/// @param merchant The merchant details obtained from Netaxept
+ (PaytrailPaymentProcess *)paytrailPaymentWithMerchant:(MerchantDetails *)merchant
                                   registrationCallback:(PaytrailRegistrationCallback)registrationCallback;

// TODO: Factories for other payments

@end

NS_ASSUME_NONNULL_END
