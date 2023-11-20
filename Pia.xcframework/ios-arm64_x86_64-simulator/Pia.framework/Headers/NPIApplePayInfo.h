//
//  NPIApplePayInfo.h
//  Pia
//
//  Created by Triet Le on 30/08/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NPIApplePayShippingInfo.h"

/**
 Class used to encapsulate Apple Pay information
 */
__deprecated
@interface NPIApplePayInfo : NSObject

/** Currency Code to be used for Apple Pay Info , NOTE: your supported currency code with Netaxept */
@property (strong, readonly, nonatomic) NSString *_Nonnull currencyCode;

/** Apple Pay Merchant ID */
@property (strong, readonly, nonatomic) NSString *_Nonnull applePayMerchantID;

/** The name of item will be displayed in Apple Pay view */
@property (strong, readonly, nonatomic) NSString *_Nonnull applePayItemDisplayName;

/** The name of Merchant will be displayed in Total section */
@property (strong, readonly, nonatomic) NSString *_Nonnull applePayMerchantDisplayName;

/** The cost of the item will be displayed in Apple Pay view */
@property (strong, readonly, nonatomic) NSDecimalNumber *_Nonnull applePayItemCost;

/** The shipping cost of the item will be displayed in Apple Pay view */
@property (strong, readonly, nonatomic) NSDecimalNumber *_Nonnull applePayItemShippingCost;

/** The shipping information of user */
@property (strong, readonly, nonatomic) NPIApplePayShippingInfo *_Nullable applePayShippingInfo;

/** Use Express or Normal way of Apple Pay */
@property (nonatomic, assign) BOOL usingExpressCheckout;

/** The payment networks supported by the merchant  */
@property (strong, readonly, nonatomic) NSArray<PKPaymentNetwork> *_Nonnull supportedPaymentNetworks;

/**
 @param applePayMerchantID Apple Pay Merchant ID
 @param applePayItemDisplayName The name of item will be displayed in Apple Pay view
 @param applePayMerchantDisplayName The name of Merchant will be displayed in Total section
 @param applePayItemCost The cost of the item will be displayed in Apple Pay view
 @param applePayItemShippingCost The shipping cost of the item will be displayed in Apple Pay view
 @param currencyCode Currency Code to be used for Apple Pay Info, If null, will use NSLocale information instead
 @param usingExpressCheckout Use Express or Normal way of Apple Pay
 @param supportedPaymentNetworks The payment networks supported by the merchant
 */
- (instancetype _Nonnull)initWithApplePayMerchantID:(NSString *_Nonnull)applePayMerchantID
                                                    applePayItemDisplayName:(NSString *_Nonnull)applePayItemDisplayName
                                                    applePayMerchantDisplayName:(NSString *_Nonnull)applePayMerchantDisplayName
                                                    applePayItemCost:(NSDecimalNumber *_Nonnull)applePayItemCost
                                                    applePayItemShippingCost:(NSDecimalNumber *_Nonnull)applePayItemShippingCost
                                                    currencyCode:(NSString *_Nonnull)currencyCode
                                                    applePayShippingInfo:(NPIApplePayShippingInfo *_Nullable)applePayShippingInfo
                                                    usingExpressCheckout:(BOOL)usingExpressCheckout
                                                    supportedPaymentNetworks:(NSArray<PKPaymentNetwork> *_Nonnull)supportedPaymentNetworks
__deprecated_msg("Deprecated! Present PKPaymentAuthorizationViewController and use PiaSDK helpers");

@end
