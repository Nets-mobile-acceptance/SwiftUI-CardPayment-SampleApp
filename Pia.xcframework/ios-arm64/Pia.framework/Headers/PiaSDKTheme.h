//
//  PiaSDKTheme
//  Pia
//
//  Created by Luke on 21.8.2020.
//  Copyright © 2020 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// A set of colors used in the SDK's views.
@protocol PiaSDKTheme

/// Color to be used for status bar.
@property(nonatomic, nonnull) UIColor *statusBarColor;

/// Color to be used for all navigation bars.
@property(nonatomic, nonnull) UIColor *navigationBarColor;

/// Color to be used for all navigation bars titles.
@property(nonatomic, nonnull) UIColor *navigationBarTitleColor;

/// Color to be used for all navigation bars left action items.
@property(nonatomic, nonnull) UIColor *leftNavigationBarItemsColor;

/// Color to be used for all navigation bars right action items.
@property(nonatomic, nonnull) UIColor *rightNavigationBarItemsColor;

/// Color to be used for webview navigation toolbar.
@property(nonatomic, nonnull) UIColor *webViewToolbarColor;

/// Color to be used for webview navigation toolbar items.
@property(nonatomic, nonnull) UIColor *webViewToolbarItemsColor;

/// Color to be used for all UIViews that don't fit in any of the special cases below (navBar, label, field, switch, etc).
@property(nonatomic, nonnull) UIColor *backgroundColor;

/// Title color to be used for all the buttons in the SDK for the default state.
@property(nonatomic, nonnull) UIColor *buttonTextColor;

/// Background color to be used for the main action buttons in the SDK for the default state.
@property(nonatomic, nonnull) UIColor *actionButtonBackgroundColor;

/// Color for the switch thumbs.
@property(nonatomic, nonnull) UIColor *switchThumbColor;

/// Color for the switch color when switch is on.
@property(nonatomic, nonnull) UIColor *switchOnTintColor;

/// Color for the switch color when switch is off.
@property(nonatomic, nonnull) UIColor *switchOffTintColor;

/// Color to be used for all the labels in the SDK.
@property(nonatomic, nonnull) UIColor *labelTextColor;

/// Color to be used for text in all textFields/textViews in the SDK.
@property(nonatomic, nonnull) UIColor *textFieldTextColor;

/// Color to be used in the error messages, border color of error text field and color of attention button on the text field.
@property(nonatomic, nonnull) UIColor *textFieldErrorColor;

/// Color to be used in the successful validation case of card entry view.
@property(nonatomic, nonnull) UIColor *textFieldSuccessColor;

/// Color to be used for all textfields background.
@property(nonatomic, nonnull) UIColor *textFieldBackgroundColor;

/// Color to be used for placeholder in textfields.
@property(nonatomic, nonnull) UIColor *textFieldPlaceholderColor;

/// Color to be used to show active textfield while editing.
@property(nonatomic, nonnull) UIColor *activeTextFieldBorderColor;

/// Color to be used in CVC entry for Subsequent transaction view.
@property(nonatomic, nonnull) UIColor *tokenCardCVCViewBackgroundColor;

/// Color to be used for Card IO's background.
@property(nonatomic, nonnull) UIColor *cardIOBackgroundColor;

/// Color to be used for Card IO's "Entry card manually" button text.
@property(nonatomic, nonnull) UIColor *cardIOButtonTextColor;

/// Color to be used for Card IO's "Entry card manually" button background color.
@property(nonatomic, nonnull) UIColor *cardIOButtonBackgroundColor;

/// Color to be used for Card IO preview frame.
@property(nonatomic, nonnull) UIColor *cardIOPreviewFrameColor;

/// Color to be used for all the texts inside Card IO view.
@property(nonatomic, nonnull) UIColor *cardIOTextColor;

@end

NS_ASSUME_NONNULL_END
