//
//  PiaSDK+ApplePay.h
//  Pia
//
//  Created by Luke on 17/01/2020.
//  Copyright © 2020 Nets. All rights reserved.
//


#import <Pia/Pia.h>
#import <PassKit/PassKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PiaSDK (ApplePay)

/// Returns a `PKPaymentRequest` with all the obligatory fields set from the arguments.
/// This helper ensures the request contains all the necessary fields.
/// Mutate the request to add custom requirements (e.g. shipping contact) if necessary.
///
+ (PKPaymentRequest *)makeApplePayPaymentRequestFor:(NSArray<PKPaymentNetwork> *)networks
                                        countryCode:(NSString *)countryCode
                                 applePayMerchantID:(NSString *)applePayMerchantID
                               merchantCapabilities:(PKMerchantCapability)merchantCapabilities
                                       currencyCode:(NSString *)currencyCode
                                       summeryItems:(NSArray<PKPaymentSummaryItem *> *)summeryItems;

/// Returns UTF-8 encoded string of `self` that's formatted to fit in Netaxept's (SOAP) Apple Pay API.
/// The value can be passed in the payment-data field to Netaxept directly without further manipulation.
///
/// @param token PKPaymentToken generated in `PassKit` payment authorisation delegate
///
+ (NSString *)netaxeptSOAPPaymentDataFrom:(PKPaymentToken *)token;

@end

NS_ASSUME_NONNULL_END
