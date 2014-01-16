//
//  AdPopcornStyle.h
//  AdPOPcornSDKRevision
//
//  Created by wonje,song on 13. 1. 10..
//  Copyright (c) 2013년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OfferWallStyle.h"
#import "EventViewStyle.h"

// top bar title type
typedef enum _TopBarTitleType
{
    AdPopcornOfferWallTopBarTitleTypeText,
    AdPopcornOfferWallTopBarTitleTypeImage,
    AdPopcornEventViewTopBarTitleTypeText,
    AdPopcornEventViewTopBarTitleTypeImage
} TopBarTitleType;

@interface AdPopcornStyle : NSObject
// offer wall style
@property (nonatomic, strong) OfferWallStyle *offerWallStyle;
// event view style
@property (nonatomic, strong) EventViewStyle *eventViewStyle;

@end
