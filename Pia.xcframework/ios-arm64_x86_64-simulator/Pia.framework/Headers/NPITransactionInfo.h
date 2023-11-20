//
//  NPITransactionInfo.h
//  Pia
//
//  Created by Triet Le on 24/04/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Class that encapsulates transaction data. Used to pass registration information around.
 */
__deprecated
@interface NPITransactionInfo : NSObject
/**Transaction id returned by merchant backend*/
@property (strong, readonly, nonatomic) NSString * _Nonnull transactionID;
/**Redirect URL for successful payment.*/
@property (strong, readonly, nonatomic) NSString * _Nonnull redirectUrl;
/**Redirect URL for cancelled payment.*/
@property (strong, readonly, nonatomic) NSString * _Nonnull cancelRedirectUrl;
/**Wallet URL for App switching.*/
@property (strong, readonly, nonatomic) NSString * _Nonnull walletUrl;

/**
 @param transactionId     Transaction id.
 @param okRedirectUrl     Redirect URL for successful payment.
 @param cancelRedirectUrl Redirect URL for cancelled payment.
 *Deprecated : Use the constructor with two parameters containing transactionId and redirectUrl only
 */
- (instancetype _Nonnull) initWithTransactionID:(NSString * _Nonnull)transactionId okRedirectUrl:(NSString * _Nonnull) okRedirectUrl cancelRedirectUrl:(NSString * _Nonnull) cancelRedirectUrl
__deprecated_msg("Use init(transactionID:redirectUrl:)");

/**
 @param transactionId     Transaction id.
 @param okRedirectUrl     Redirect URL for successful payment.
 */
- (instancetype _Nonnull) initWithTransactionID:(NSString * _Nonnull)transactionId okRedirectUrl:(NSString * _Nonnull) okRedirectUrl
__deprecated_msg("Use init(transactionID:redirectUrl:");

/**
 @param transactionId     Transaction id.
 @param redirectUrl     Redirect URL for successful payment.
 */
- (instancetype _Nonnull) initWithTransactionID:(NSString * _Nonnull)transactionId redirectUrl:(NSString * _Nonnull) redirectUrl;

/**
 @param walletUrl     Wallet URL to open the mobile wallet application.
 */
- (instancetype _Nonnull) initWithWalletUrl:(NSString * _Nonnull) walletUrl;

/**
 @param transactionId     Transaction id.
 @param walletUrl         Wallet URL to open the mobile wallet application.
 */
- (instancetype _Nonnull) initWithTransactionID:(NSString * _Nonnull)transactionId walletUrl:(NSString * _Nonnull) walletUrl;

@end
