//
//  TokenCardInfo.h
//  Pia
//
//  Created by Triet Le on 05/05/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Enumeration of all the supported card schemes.
 */
typedef enum SchemeType {
    /**
     Visa scheme
     */
    VISA = 0, 
    
    /**
     Mastercard scheme
     */
    MASTER_CARD,
    
    /**
     American Express scheme
     */
    AMEX,
    
    /**
     Diners Club International scheme
     */
    DINERS_CLUB_INTERNATIONAL,
    
    /**
     Dankort Scheme (co-brand with either Master or Visa)
     */
    DANKORT,
    
    /**
     Japanese credit burean scheme
     */
    JCB,
    
    /**
     Maestro card scheme
     */
    MAESTRO,
    
    /**
     S-Business card scheme
     */
    SBUSINESS,
    
    /**
     ForbrugsForeningen card scheme
    */
    FORBRUGSFORENINGEN,
    
    /**
     Other schemes
     */
    OTHER
} SchemeType;

/**
 NPITokenCardInfo describes a tokenized card - one that the user previously saved.
 */
__deprecated
@interface NPITokenCardInfo : NSObject

/**
 Card token retrieved from the backend
 */
@property (strong, readonly, nonatomic) NSString * _Nonnull tokenId;

/**
 Card expiration date, format: MM/YY, example: "04/19"
 */
@property (strong, readonly, nonatomic) NSString * _Nonnull expiryDate;

/**
 Whether or not the security code is needed
 */
@property (nonatomic, assign) BOOL cvcRequired;

/**
 Whether or not system authentication is needed
 */
@property (nonatomic, readonly) BOOL systemAuthenticationRequired;

/**
 Card scheme
 */
@property (nonatomic) SchemeType schemeType;

@property (nonatomic, nullable) UIImage * customCardSchemeImage;

/**
 @param tokenId Card token
 @param schemeType Card scheme
 @param expiryDate Card expiry date
 @param cvcRequired Whether or not cvc is needed for payment
 @param systemAuthenticationRequired Whether or not system authentication is needed
 */
- (instancetype _Nonnull) initWithTokenId:(NSString * _Nonnull)tokenId
                               schemeType:(SchemeType )schemeType
                               expiryDate:(NSString *_Nonnull)expiryDate
                              cvcRequired:(BOOL )cvcRequired
             systemAuthenticationRequired:(BOOL )systemAuthenticationRequired
__deprecated_msg("System authentication becomes obsolete due to PSD2/SCA regulation.\nReplaced with `init(tokenId:schemeType:expiryDate:cvcRequired:)`");

/**
 @param tokenId Card token
 @param schemeType Card scheme
 @param expiryDate Card expiry date
 @param cvcRequired Whether or not cvc is needed for payment
 */
- (instancetype _Nonnull) initWithTokenId:(NSString * _Nonnull)tokenId
                               schemeType:(SchemeType )schemeType
                               expiryDate:(NSString *_Nonnull)expiryDate
                              cvcRequired:(BOOL )cvcRequired;

@end
