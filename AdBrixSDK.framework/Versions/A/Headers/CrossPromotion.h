//
//  CrossPromotion.h
//  AdBrix
//
//  Created by wonje,song on 2014. 4. 8..
//  Copyright (c) 2014년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CrossPromotion : NSObject

/*!
 @abstract
 광고를 노출하고자 할때 호출한다.
 
 @param activityName              activity name.
 @param parentViewController      광고를 노출시킬 view controller
 */
+ (void)showAD:(NSString *)activityName parentViewController:(UIViewController *)parentViewController;

@end
