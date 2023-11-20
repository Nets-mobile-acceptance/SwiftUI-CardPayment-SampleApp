//
//  NPIInterfaceConfiguration.h
//  Pia
//
//  Created by George Jingoiu on 06/08/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "PiALanguage.h"

/**
 Enumeration of all the supported pay button labels.
 */
typedef enum PayButtonTextLabelOption {
    /**
     Pay
     */
    PAY = 0,
    
    /**
     Reserve
     */
    RESERVE
    
} PayButtonTextLabelOption;

/**
 @NSObject NSObject that provides UI Customisation API
 */
@interface NPIInterfaceConfiguration : NSObject

/**
 Font to be used for all buttons in the SDK. The point size will be overwritten, just the font name/family will be used.
 */
@property (nonatomic, strong) UIFont  *buttonFont;

/**
 Font to be used for all fields/textviews. The point size will be overwritten, just the font name/familly will be used.
 */
@property (nonatomic, strong) UIFont  *textFieldFont;

/**
 Font to be used in the SDK for all labels. The point size will be overwritten, just the font name/family will be used.
 */
@property (nonatomic, strong) UIFont  *labelFont;

/**
 Logo image to be displayed in the card form screen. Width equal to the screen, height = 70.
 */
@property (nonatomic, strong) UIImage  *logoImage;

/**
 Whether or not the save card switch should be on by default.
 */
@property (nonatomic, readwrite) BOOL saveCardOn;

/**
 Font to be used for Card IO's "Entry card manually" button font.
 */
@property (nonatomic, strong) UIFont *cardIOButtonTextFont;

/**
 Font to be used in the Card IO view for all labels. The point size will be overwritten, just the font name/family will be used.
 */
@property (nonatomic, strong) UIFont *cardIOTextFont;

/**
 Choose whether to disable CardIO/Card scanner or not
 */
@property (nonatomic, readwrite) BOOL disableCardIO;

/**
 Use either light or dark content for status bar
 */
@property (nonatomic, readwrite) BOOL useStatusBarLightContent;

/**
 Content view mode for logo image
 */
@property (nonatomic, readwrite) UIViewContentMode logoImageContentMode;

/**
 Choose whether to disable save card for later user option
 */
@property (nonatomic, readwrite) BOOL disableSaveCardOption;

/**
 Supported language to use within PiA SDK
 */
@property (nonatomic) PiALanguage language;

/**
 Text to be used for save card Label
 */
@property (nonatomic, strong) NSAttributedString *attributedSaveCardText;

/**
 Left margin for all buttons used in the SDK.
 */
@property (nonatomic) CGFloat buttonLeftMargin;

/**
 Right margin for all buttons used in the SDK.
 */
@property (nonatomic) CGFloat buttonRightMargin;

/**
 Bottom margin for all buttons used in the SDK.
 */
@property (nonatomic) CGFloat buttonBottomMargin;

/**
 Rounding corners for all text fields of the SDK, value ranges from 0.0 - 0.5 (0.5 suggest full rounded corners).
 */
@property (nonatomic) CGFloat textFieldCornerRadius;

/**
 Rounding corners for all buttons of the SDK, value ranges from 0.0 - 0.5 (0.5 suggest full rounded corners).
 */
@property (nonatomic) CGFloat buttonCornerRadius;

/**
 @return Singleton instance used throughout the code
 */
+ (instancetype) sharedInstance;

/**
 Supported text labels for pay button to use within PiA SDK
 */
@property (nonatomic) PayButtonTextLabelOption payButtonTextLabelOption;


@end
