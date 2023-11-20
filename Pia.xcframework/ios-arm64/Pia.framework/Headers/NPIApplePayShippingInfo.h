//
//  NPIApplePayShippingInfo.h
//  Pia
//
//  Created by Triet Le on 06/09/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassKit/PassKit.h>

/**
 Class used to encapsulate Apple Pay Shipping Infomation
 */
__deprecated
@interface NPIApplePayShippingInfo : NSObject

/** The buyer’s first and last name */
@property (strong, readonly, nonatomic) NSPersonNameComponents *_Nonnull fullName;

/** The buyer’s email address */
@property (strong, readonly, nonatomic) NSString *_Nonnull email;

/** The buyer’s telephone number */
@property (strong, readonly, nonatomic) CNPhoneNumber *_Nonnull phoneNumber;

/** The buyer’s full street address, including name, street, city, state or province, postal code, and country */
@property (strong, readonly, nonatomic) CNPostalAddress *_Nonnull shippingAddress;

/**
 @param shippingAddress The buyer’s full street address, including name, street, city, state or province, postal code, and country
 @param fullName The buyer’s first and last name
 @param email The buyer’s email address
 @param phoneNumber The buyer’s telephone number
 */
- (instancetype _Nonnull) initWithShippingAddress:(CNPostalAddress *_Nonnull)shippingAddress fullName:(NSPersonNameComponents *_Nonnull)fullName email:(NSString *_Nonnull)email phoneNumber:(CNPhoneNumber *_Nonnull)phoneNumber;

@end
