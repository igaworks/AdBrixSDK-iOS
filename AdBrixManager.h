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
    @private
        NSString *_appKey;
        NSString *_hashKey;
    
        HandleCoreData *_handleCoreData;
        TrackingResult *_trackingResult;
        ConversionResult *_conversionResult;
        SendDemoResult *_sendDemoResult;
    
        GetScheduleResult *_getScheduleResult;
    
        CompleteResult *_completeResult;
    
        NSArray *_fetchActivityForTrackingArray;
        NSArray *_fetchDemoArray;
    
        NSDate *_startSessoinDate;
    
        __block UIBackgroundTaskIdentifier background_task;
    
        NSDateFormatter *_dateFormatter;
    
        NSString *_identifier;
    
    NSArray *_adBrixUserInfoArray;
}

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
+ (void)viral:(NSString *)activityName;


/*!
 @abstract
 viral의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)viral:(NSString *)activityName param:(NSString *)param;


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
+ (void)error:(NSString *)message exception:(NSException *)exception;


/*!
 @abstract
 custom의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)custom:(NSString *)activityName;

/*!
 @abstract
 custom의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)custom:(NSString *)activityName param:(NSString *)param;

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

@end