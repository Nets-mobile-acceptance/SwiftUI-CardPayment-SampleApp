//
//  NPIMerchantInfo.h
//  Pia
//
//  Created by Amir Ghoreshi on 05/08/16.
//  Copyright © 2016 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Class used to encapsulate merchant identification
 */
__deprecated
@interface NPIMerchantInfo : NSObject
/**
 Uniquely identifies the merchant.
*/
@property (strong, readonly, nonatomic) NSString * _Nonnull identifier;

/**
 Inform SDK of using Netaxept's test environment
 */
@property (readonly, nonatomic) BOOL testMode;

/**
 Inform SDK of making payments without Security Code
 */
@property (readonly, nonatomic) BOOL cvcRequired;

/**
 @param identifier Merchant id provided by Nets. Must not be nil.
 */
- (instancetype _Nonnull)initWithIdentifier:(NSString * _Nonnull)identifier;
/**
 @param identifier Merchant id provided by Nets. Must not be nil.
 @param testMode Default is false, set it to true to use Netaxept's test environment
 */
- (instancetype _Nonnull)initWithIdentifier:(NSString * _Nonnull)identifier testMode:(BOOL)testMode;
/**
 @param identifier Merchant id provided by Nets. Must not be nil.
 @param testMode Default is false, set it to true to use Netaxept's test environment
 @param cvcRequired Default is true, set it to false to make payments without Security Code
 Important: Note that disabling Security Code entry by setting _cvcRequired=False_ is submitted to both approval from your acquirer and activation by Netaxept customer service. Before proceeding, please contact your Netaxept customer service.
 */
- (instancetype _Nonnull)initWithIdentifier:(NSString * _Nonnull)identifier testMode:(BOOL)testMode cvcRequired:(BOOL)cvcRequired;
@end
