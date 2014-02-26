//
//  AdBrixManager.h
//
//
//  Created by wonje,song on 12. 12. 18..
//  Copyright (c) 2012년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TrackingResult;
@class ConversionResult;
@class SendDemoResult;
@class HandleCoreData;
@class GetScheduleResult;
@class CompleteResult;


typedef enum _gender
{
    AdBrixManagerGenderMALE = 2,
    AdBrixManagerGenderFEMALE = 1
} Gender;

typedef enum _adBrixLogLevel
{
    /*! only info logging  */
    AdBrixLogInfo,
    /*! info, debug logging  */
    AdBrixLogDebug,
    /*! all logging */
    AdBrixLogTrace
} AdBrixLogLevel;

/*!
 @header
 
 @abstract  라이브러리 헤더, AdBrix 서비스를 사용하기 위해 이 파일을 import 해야한다.
 
 @discussion
 
 */
@interface AdBrixManager : NSObject
{
    
}

@property (nonatomic, copy) NSString *appleAdvertisingIdentifier;
@property (nonatomic, unsafe_unretained) BOOL isAppleAdvertisingTrackingEnabled;


/*!
 @abstract
 초기화. init한다.
 
 @discussion
 발급 받은 appkey로 connect한다.
 
 @param appkey              app. 등록 후, IGAWorks로부터 발급된 키.
 @param hashkey             app. 등록 후 발급된 키.
 */
- (id)initWithAppKey:(NSString *)appKey andHashKey:(NSString *)hashKey;


/*!
 @abstract
 singleton Tracer 객체를 반환한다.
 */
+ (AdBrixManager *)shared;


/*!
 @abstract
 초기화. AppDelegate에서 앱 기동시 초기화한다.
 
 @discussion
 App. 기동시 한번만 호출하면 된다. 따라서 AppDelegate 클래스의 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 메소드에서 호출할것을 권장한다.
 
 @param appkey              app. 등록 후, IGAWorks로부터 발급된 키.
 @param hashkey             app. 등록 후 발급된 키.
*/
+ (id)traceWithAppKey:(NSString *)appkey andHashKey:(NSString *)hashkey;


/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)firstTimeExperience:(NSString *)activityName;


/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)firstTimeExperience:(NSString *)activityName param:(NSString *)param;


/*!
 @abstract
 viral의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)viral:(NSString *)activityName __deprecated;


/*!
 @abstract
 viral의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)viral:(NSString *)activityName param:(NSString *)param __deprecated;


/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)retention:(NSString *)activityName;

/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)retention:(NSString *)activityName param:(NSString *)param;


/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)buy:(NSString *)activityName;

/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)buy:(NSString *)activityName param:(NSString *)param;


/*!
 @abstract
 error의 Activity에 해당할때 호출한다.
 
 @param errorName                 error name.
 @param detail                    detail.
 */
+ (void)error:(NSString *)message exception:(NSException *)exception __deprecated;


/*!
 @abstract
 custom의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)custom:(NSString *)activityName __deprecated;

/*!
 @abstract
 custom의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)custom:(NSString *)activityName param:(NSString *)param __deprecated;

/*!
 @abstract
 custom의 Activity, Group에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param activityGroup             activity group.
 */
+ (void)custom:(NSString *)activityName activityGroup:(NSString *)activityGroup appKey:(NSString *)appKey;

/*!
 @abstract
  사용자의 demo정보를 전송하고자 할때 호출한다.
 
 @param userDemoInfo              user demo info.
 */
+ (void)setDemographic:(NSDictionary *)userDemoInfo;

/*!
 @abstract
 사용자의 나이 정보를 전송하고자 할때 호출한다.
 
 @param age              age.
 */
+ (void)setAge:(int)age;

/*!
 @abstract
 사용자의 성별 정보를 전송하고자 할때 호출한다.
 
 @param gender              gender.
 */
+ (void)setGender:(Gender)gender;

/*!
 @abstract
 사용자의 user id를 전송하고자 할때 호출한다.
 
 @param userId              user id.
 */
+ (void)setUserId:(NSString *)userId;


/*!
 @abstract
 광고를 노출하고자 할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)showAD:(NSString *)activityName parentView:(UIView *)parentView __deprecated;

/*!
 @abstract
 광고를 노출하고자 할때 호출한다.
 
 @param activityName              activity name.
 @param parentViewController      광고를 노출시킬 view controller
 */
+ (void)showAD:(NSString *)activityName parentViewController:(UIViewController *)parentViewController;

/*!
 @abstract
 자세한 로그를 볼지 여부를 설정한다.
 
 @discussion
 param isEnable값이 YES이면 로그 레벨의 info, debug, trace의 로그를 확인하고, isEnable값이 NO이면 info, debug 로그를 확인하다.
 
 @param isEnable            세부 로그 볼지 여부
 */
+ (void)viewDetailLog:(bool)isEnable __deprecated;

/*!
 @abstract
 로그를 level를 설정한다.
 
 @discussion
 보고자 하는 로그 level을 info, debug, trace으로 설정한다.
 
 @param LogLevel            log level
 */
+ (void)setLogLevel:(AdBrixLogLevel)logLevel;

/*!
 @abstract
 App.이 최초 실행될때 시작되었음을 서버로 전송하기 위해 호출한다.
 한번만 호출한다.
 
 @discussion
 AppDelegate의 - application:didFinishLaunchingWithOptions: 메소드에서 AdBrixManager - traceWithAppKey:andHashKey: 메소드를 호출하는 경우에는 start 메소드를 호출하지 않는다.
 Unity plugin의 경우 traceWithAppKey:andHashKey: 메소드 호출 후에, start 메소드를 호출한다.
 */
+ (void)start;

/*!
 @abstract
 Apple AdvertisingIdentifier를 전송한다.
 
 @param appleAdvertisingIdentifier              Apple AdvertisingIdentifier.
 
 @discussion
 광고 목적이 아닌 경우, Apple AdvertisingIdentifier를 사용하면, app reject 사유가 되기 때문에, iAd(AdSupport.framework)를 사용하지 않는다면 값을 전송하지 않는다.
 AdBrix에서는 전달받은 Apple AdvertisingIdentifier 값이 없는경우, identifierForVendor 값을 identifier로 사용한다.
 */
+ (void)setAppleAdvertisingIdentifier:(NSString *)appleAdvertisingIdentifier isAppleAdvertisingTrackingEnabled:(BOOL)isAppleAdvertisingTrackingEnabled;

@end
