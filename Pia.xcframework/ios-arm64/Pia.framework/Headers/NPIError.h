//
//  NPIError.h
//  Pia
//
//  Created by George Jingoiu on 22/05/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Standardized codes for NPIError
 */
typedef enum : NSUInteger {
    /**
     Generic error that may occur in the following cases
     - the request is successful but the response body is empty
     - the response code is not HTTP_MOVED_TEMP
     - the headers map does not contain the entry with Location key
     */
    NPIGenericError = 300,
    /**
     Terminal Validation Error. May occur in the following cases:
     - Invalid card number
     - Transaction filter
     - Credit card not allowed
     - IP restriction
     */
    NPITerminalValidationError = 301,
    /**
     Regular iOS network error. May occur in the following cases:
     - internet connectivity issues
     - timeout error
     - failed serialisation in models
     */
    NPIRequestFailed = 101,
    /**
     3DS error before loading webview:
     - no internet connection (from Apple)
     - timeout (normally 3 mins from Apple)
     */
    NPIThreeDSecureError = 102,
    /**
     3DS navigation error while loading webview
     */
    NPIThreeDSecureNavigationError = 103,
    
    /**
     Netaxept error
     The card number is not valid
     */
    NPIInvalidCardNumber = 14,
    /**
     Netaxept error
     The transaction with specific ID could not be found
     */
    NPITransactionNotFound = 25,
    /**
     Netaxept error
     Card number (PAN) is invalid or missing
     */
    NPIKidInvalid = 30,
    /**
     Netaxept error
     The transaction with specific ID has been rejected
     */
    NPIOriginalTransactionRejected = 84,
    /**
     Netaxept error
     The transaction with specific ID has already been reversed
     */
    NPITransactionAlreadyReversed = 86,
    /**
     Netaxept error
     NETAXEPT internal failure
     */
    NPIInternalFailure = 96,
    /**
     Netaxept error
     There is no transaction with that specific ID
     */
    NPINoTransaction = 97,
    /**
     Netaxept error
     The transaction with specific ID has already been processed
     */
    NPITransactionAlreadyProcessed = 98,
    /**
     Netaxept error
     Several errors can result in this error code. Refer to the Response text for details
     */
    NPIUnknownError = 99,
    /**
     Netaxept error
     The 3D Secure Authentication has denied the verification
     */
    NPIDeniedBy3DS = 900,//"MZ",
    /**
     Netaxept error
     Transaction reached merchant timeout value of xx:xx:xx
     */
    NPIMerchantTimeout = 901,//"T1",

    /// Vipps payment failure with Vipps status code parsed from redirect URL
    NPIVippsErrorStatusCode __attribute__((deprecated)) = 302,
    
    /// The wallet app is not installed on the device.
    NPIWalletAppNotInstalled = 303,

    /// The wallet URL returned from payment registration with BE is invalid.
    NPIWalletURLInvalid = 304,

    /// The redirect url (passed from UIApplication open:url) is unknown and could not be parsed.
    /// This can be caused if the SDK was invoked with a URL thats not
    /// from a wallet app redirect or there has been API change in the wallet app.
    /// In the second case, make sure the SDK is the latest version and contact us.
    NPIWalletRedirectURLUnknown = 305,
    
    /// Transaction Info object provided to SDK is null
    NPITransactionInfoNull = 306,
    
    /// RedirectURL provided to SDK is null
    NPIRedirectURLNull = 307,
    
    /// An unknown terminal error.
    NPIUnknownTerminalError = 308,
    
    /// Unidentified redirect url in the webview.
    NPIUnidentifiedWebViewRedirectURL = 309,
   
    ///3DS Page not found
    NPIThreeDSecurePageNotFound = 310,
    
    /// Invalid WebView URL was provided to SDK.
    NPIInvalidWebViewURL = 311,

} NPIErrorCode;


/**
 Class that encapsulates information about an error condition.
 Includes a domain, a domain-specific error code, and localized information.
 */
__deprecated
@interface NPIError: NSObject
/**
 Technical error message which should not be presented directly to customers
 */
@property (readonly, copy) NSString *_Nonnull localizedDescription;

/**
 @param code NPIErrorCode that best describes the error case
 */
- (_Nonnull instancetype) initWithCode:(NSString *_Nonnull)code;

/**
 @param code NPIErrorCode that best describes the error case
 @param info Any useful info that could help better identify the error
 */
- (_Nonnull instancetype) initWithCode:(NSString *_Nonnull)code userInfo:(nonnull NSDictionary<NSErrorUserInfoKey, id> *)info NS_DESIGNATED_INITIALIZER;

- (_Nonnull instancetype) initWithIntCode:(NPIErrorCode)code userInfo:(nonnull NSDictionary<NSErrorUserInfoKey, id> *)info;

/**
 */
- (NSString *_Nonnull) localizedDescription;

/**
 Error code
 */
- (NPIErrorCode) code;

/**
 Mobile Wallet Error code
 */
- (int) getMobileWalletErrorCode;
@end
