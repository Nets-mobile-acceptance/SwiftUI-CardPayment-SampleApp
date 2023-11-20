//
//  CardScheme.h
//  Pia
//
//  Created by Luke on 14.4.2021.
//  Copyright © 2021 Nets. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef CardScheme_h
#define CardScheme_h

typedef NS_OPTIONS(NSUInteger, CardScheme) {
    CardSchemeNone                          = 0,
    CardSchemeAmex                          = 1 << 0,
    CardSchemeVisa                          = 1 << 1,
    CardSchemeMasterCard                    = 1 << 2,
    CardSchemeDinersClubInternational       = 1 << 3,
    CardSchemeJCB                           = 1 << 4,
    CardSchemeDankort                       = 1 << 5,
    CardSchemeMaestro                       = 1 << 6,
    CardSchemeSBusiness                     = 1 << 7,
    CardSchemeCoBrandedDankort              = 1 << 8,
    CardSchemeForbrugsForeningen            = 1 << 9,
};

typedef NS_ENUM(NSUInteger, Card) {
    CardAmex = CardSchemeAmex,
    CardVisa = CardSchemeVisa,
    CardMasterCard = CardSchemeMasterCard,
    CardDinersClubInternational = CardSchemeDinersClubInternational,
    CardJcb = CardSchemeJCB,
    CardDankort = CardSchemeDankort,
    CardMaestro = CardSchemeMaestro,
    CardSBusiness = CardSchemeSBusiness,
    CardCoBrandedDankort = CardSchemeCoBrandedDankort,
    CardForbrugsForeningen = CardSchemeForbrugsForeningen,
    CardOther
#define CardLastCase CardOther
};

#endif /* CardScheme_h */


NS_ASSUME_NONNULL_BEGIN

@interface CardDisplay : NSObject
@property(nonatomic) Card card;
@property(nonatomic, nullable) UIImage * customCardImage;

+ (CardDisplay *)card:(Card)card;
+ (CardDisplay *)customCardImage:(UIImage *)customCardImage card:(Card)card;

@end


NS_ASSUME_NONNULL_END
