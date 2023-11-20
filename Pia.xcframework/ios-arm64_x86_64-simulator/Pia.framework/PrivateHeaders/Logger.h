//
//  Logger.h
//  Pia
//
//  Created by George Jingoiu on 08/05/2018.
//  Copyright © 2018 Nets. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>

@interface Logger : NSObject

+ (void) log:(NSString *) newLogLine forKey:(NSString *) keyString method:(const char *) methodName;
+ (MFMailComposeViewController *) emailController;
+ (void) removeLogs;
@end
