//
//  PaymentRegistration.h
//  Pia
//
//  Created by Luke on 14.9.2020.
//  Copyright © 2020 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NPIError.h"
#import "NSError+Wallets.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSURL * WalletURL;
typedef NSString * TransactionID;
typedef NSString * RedirectURL;

typedef NPIError * CardError; // TODO:

#pragma mark RegistrationResponse (Abstract)

@interface RegistrationResponse : NSObject
@property(nonatomic, nullable) NSError * error;
- (instancetype)init NS_UNAVAILABLE;
@end

#pragma mark WalletRegistrationResponse

@interface WalletRegistrationResponse : RegistrationResponse
@property(nonatomic) WalletURL walletURL;

- (instancetype)copy;

/// Return object containing response following successful registration with merchant backend.
+ (WalletRegistrationResponse *)successWithWalletURL:(WalletURL)walletURL;

/// Return object containing `error` following unsuccessful registration with merchant backend.
+ (WalletRegistrationResponse *)failure:(NSError * _Nullable)error;
@end

#pragma mark CardRegistrationResponse


@protocol PaymentRegistrationResult <NSObject>
@required
@property(nonatomic, nullable) TransactionID transactionID;
@property(nonatomic, nullable) RedirectURL redirectURL;

/// Return object containing response following successful registration with merchant backend.
+ (instancetype)successWithTransactionID:(TransactionID)transactionID
                             redirectURL:(RedirectURL)redirectURL;

/// Return object containing `error` following unsuccessful registration with merchant backend.
+ (instancetype)failure:(NSError *)error;
@end

@interface CardRegistrationResponse : RegistrationResponse<PaymentRegistrationResult>
@property(nonatomic, nullable) TransactionID transactionID;
@property(nonatomic, nullable) RedirectURL redirectURL;

/// Return object containing response following successful registration with merchant backend.
+ (CardRegistrationResponse *)successWithTransactionID:(TransactionID)transactionID
                                           redirectURL:(RedirectURL)redirectURL;

/// Return object containing `error` following unsuccessful registration with merchant backend.
+ (CardRegistrationResponse *)failure:(NSError *)error;
@end

#pragma mark PayPalRegistrationResponse

@interface PayPalRegistrationResponse : RegistrationResponse<PaymentRegistrationResult>
@property(nonatomic, nullable) TransactionID transactionID;
@property(nonatomic, nullable) RedirectURL redirectURL;

/// Return object containing response following successful registration with merchant backend.
+ (PayPalRegistrationResponse *)successWithTransactionID:(TransactionID)transactionID
                                             redirectURL:(RedirectURL)redirectURL;

/// Return object containing `error` following unsuccessful registration with merchant backend.
+ (PayPalRegistrationResponse *)failure:(NSError *)error;
@end

#pragma mark PaytrailRegistrationResponse

@interface PaytrailRegistrationResponse : RegistrationResponse<PaymentRegistrationResult>
@property(nonatomic, nullable) TransactionID transactionID;
@property(nonatomic, nullable) RedirectURL redirectURL;

/// Return object containing response following successful registration with merchant backend.
+ (PaytrailRegistrationResponse *)successWithTransactionID:(TransactionID)transactionID
                                               redirectURL:(RedirectURL)redirectURL;

/// Return object containing `error` following unsuccessful registration with merchant backend.
+ (PaytrailRegistrationResponse *)failure:(NSError *)error;
@end

#pragma mark Callback Blocks

#define Escaping (^)

/// True if user has chosen to tokenize the card for subsequent payments
typedef BOOL TokenizeCardForLaterUse;

typedef void(^TokenizableCardRegistrationCallback)(TokenizeCardForLaterUse,
                                                   void Escaping (CardRegistrationResponse *));

/// Register payment and callback with the registration response using the `callback` parameter.
typedef void(^CardRegistrationCallback)(void Escaping (CardRegistrationResponse *));

/// Register payment and callback with the registration response using the `callback` parameter.
typedef void(^PayPalRegistrationCallback)(void Escaping (PayPalRegistrationResponse *));

/// Register payment and callback with the registration response using the `callback` parameter.
typedef void(^PaytrailRegistrationCallback)(void Escaping (PaytrailRegistrationResponse *));

/// Register payment and callback with the registration response using the `callback` parameter.
typedef void(^WalletURLCallback)(void Escaping (WalletRegistrationResponse *));
typedef void(^WalletRedirectWithoutInterruption)(BOOL);
typedef void(^WalletFailureWithError)(WalletError);

// TODO: Remove after deprecation
typedef void(^CompletionCallback)(UIViewController *);
typedef void(^PaymentProcessCompletion)(UIViewController *, _Nullable TransactionID);

// TODO: Remove after deprecation
typedef void(^FailureCompletionCallback)(UIViewController *, CardError);
typedef void(^PaymentProcessFailure)(UIViewController *, NSError *);


// Backward compatibility (renamed)

typedef TokenizableCardRegistrationCallback TransactionCallback;
typedef PaymentProcessCompletion TransactionCompletion;

NS_ASSUME_NONNULL_END
