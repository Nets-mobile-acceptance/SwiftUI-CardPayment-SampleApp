//
//  NPIOrderInfo.h
//  Pia
//
//  Created by Triet Le on 24/04/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Class used to encapsulate order information
 */
__deprecated
@interface NPIOrderInfo : NSObject

/**
 Double value of the transaction
 */
@property (strong, readonly, nonatomic) NSNumber * _Nonnull amount;

/**
 Currency code following iSO 4217
 */
@property (strong, readonly, nonatomic) NSString * _Nonnull currencyCode;

/**
 @param amount Double value to be paid
 @param currencyCode Currency code following ISO 4217
 */
- (instancetype _Nonnull) initWithAmount:(NSNumber * _Nonnull)amount currencyCode:(NSString * _Nonnull) currencyCode;

@end
