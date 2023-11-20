//
//  Pia.h
//  Pia
//
//  Created by Emanuel Jarnea on 07/03/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Project version number for Pia.*/
FOUNDATION_EXPORT double PiaVersionNumber;

/** Project version string for Pia.*/
FOUNDATION_EXPORT const unsigned char PiaVersionString[];

/**
 Semantic version string for Pia. The same with the "CFBundleShortVersionString" entry found in the Info.plist file. Ignore the Apple provided versioning constants above.
 */

FOUNDATION_EXPORT NSString *_Nonnull const NPIPiaSemanticVersionString;

/**
 Technical version string for Pia. Please provide this information when reporting any issues.
 */

FOUNDATION_EXPORT NSString *_Nonnull const NPIPiaTechnicalVersionString;

// In this header, you should import all the public headers of your framework using statements like #import <Pia/PublicHeader.h>
#import "NPIMerchantInfo.h"
#import "NPIOrderInfo.h"
#import "NPITransactionInfo.h"
#import "NPITokenCardInfo.h"
#import "NPIError.h"
#import "PiaSDKController.h"
#import "NPIInterfaceConfiguration.h"
#import "NPIApplePayInfo.h"
#import "NPIApplePayShippingInfo.h"
#import "PiALanguage.h"
#import "PiaSDK.h"
#import "PiaSDK+ApplePay.h"
#import "PiaSDKTheme.h"
