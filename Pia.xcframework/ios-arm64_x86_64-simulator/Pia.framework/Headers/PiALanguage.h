//
//  PiALanguage.h
//  Pia
//
//  Created by Trong Triet Le on 31/01/2019.
//  Copyright © 2019 Nets. All rights reserved.
//

#ifndef PiALanguage_h
#define PiALanguage_h

/**
 List of supported languages within PiA SDK
 */
typedef enum PiALanguage {
    /**
     Unassigned
     */
    Unassigned = -1,
    /**
    English
     */
    English = 0,
    /**
     Swedish
     */
    Swedish,
    /**
     Danish - Denmark
     */
    Danish,
    /**
     Norwegian - Norwegian Bokmal
     */
    Norwegian,
    /**
     Finnish
     */
    Finnish
} PiALanguage;

#endif /* PiALanguage_h */
