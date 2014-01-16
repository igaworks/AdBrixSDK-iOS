//
//  OfferWallStyle.h
//  AdPOPcornSDKRevision
//
//  Created by wonje,song on 13. 1. 11..
//  Copyright (c) 2013년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface OfferWallStyle : NSObject

// top bar background color
@property (nonatomic, strong) UIColor *topBarBackgroundColor;
// top bar text color
@property (nonatomic, strong) UIColor *topBarTextColor;
// top bar text size
@property (nonatomic, unsafe_unretained) float topBarTextSize;
// top bar text
@property (nonatomic, copy) NSString *topBarText;
// top bar logo image
@property (nonatomic, strong) UIImage *topBarLogoImage;
// top bar title type : AdPopcornEventViewTopBarTitleTypeText, AdPopcornEventViewTopBarTitleTypeImage
@property (nonatomic, unsafe_unretained) NSUInteger topBarTitleType;

@end
