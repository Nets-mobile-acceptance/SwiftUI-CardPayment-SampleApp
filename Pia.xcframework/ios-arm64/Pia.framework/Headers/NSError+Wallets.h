//
//  NSError+Wallets.h
//  Pia
//
//  Created by Luke on 5.10.2020.
//  Copyright © 2020 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSError * WalletError;

typedef NS_CLOSED_ENUM (NSInteger, WalletErrorCode) {
    WalletErrorCodeRegistrationFailure,
    WalletErrorCodeNoNetwork,
    WalletErrorCodeWalletAppNotFound
};

@interface NSError (Wallets)
+ (WalletError)walletErrorWith:(WalletErrorCode)errorCode underlyingError:(NSObject *)underlyingError;
@end

NS_ASSUME_NONNULL_END
