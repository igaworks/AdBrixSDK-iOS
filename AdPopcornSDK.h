//
//  AdPOPcornSDKRevision.h
//  AdPOPcornSDKRevision
//
//  Created by wonje,song on 12. 12. 6..
//  Copyright (c) 2012년 wonje,song. All rights reserved.
//

// check...................

#import <Foundation/Foundation.h>
// style
#import "AdPopcornStyle.h"

// service
@class AdPopcornSDKService;
@class AdPopcornTracer;
@class RewardService;
@class NotificationMessageAgent;
@class PopCodeService;
@class TrackingService;

// view
@class AdPopiconView;
@class AdCampaignListViewControllerForIphone;
@class AdCampaignListViewControllerForIpad;
@class AdBridgeController;
@class AdLandingController;

// orientaion
extern NSUInteger _orientation;
extern float _globalSizeWidth;
extern float _globalSizeHeight;


@protocol AdPopcornDelegate;

/*!
 @typedef RewardServerType enum
 
 @abstract AdPopcorn reward를 사용자에게 지급하는 방식을 설정합니다.
 
 @discussion
 */
typedef enum _RewardServerType
{
    /*! 고객의 자체 서버를 사용하여, 콜백 URL로 관리  */
    AdPopcornRewardServerTypeServer,
    /*! 자체 서버가 없이, AdPopcorn 서버로 관리  */
    AdPopcornRewardServerTypeClient,
    /*! 자체 reward가 없이, AdPopcorn point를 reward로 사용하는 경우 */
    AdPopcornRewardServerTypePoint
} RewardServerType;

typedef enum _AdPopcornLogLogLevel
{
    /*! only info logging  */
    AdPopcornLogInfo,
    /*! info, debug logging  */
    AdPopcornLogDebug,
    /*! all logging */
    AdPopcornLogTrace
} AdPopcornLogLogLevel;

/*!
 @header
 
 @abstract  라이브러리 헤더, AdPopcorn 서비스를 사용하기 위해 이 파일을 import 해야한다.
 
 @discussion
 
 */
@interface AdPopcornSDK : NSObject <UIWebViewDelegate, UIAlertViewDelegate>
{
    @protected
        // view
        AdPopiconView *_adPopiconView;
        AdCampaignListViewControllerForIphone *_adCampaignListViewControllerForIphone;
        AdCampaignListViewControllerForIpad *_adCampaignListViewControllerForIpad;
        AdBridgeController *_adBridgeController;
        AdLandingController *_adLandingController;
        UIWebView *_webViewForPointRewardType;
        UIActivityIndicatorView *_activityIndicatorView;
    
        // service
        AdPopcornSDKService *_adPopcornSDKService;
        RewardService *_rewardService;
        AdPopcornTracer *_adPopcornTracer;
        NotificationMessageAgent *_apNotificationMessageAgent;
        TrackingService *_trackingService;
    
        // key
        NSString *_mediaKey;
        NSString *_hashKey;
    
        // user serial number
        NSString *_userSerialNumber;
    
        // active tracer flag
        BOOL _activeTracer;
        NSString *_tracerActivity;
    
        // reward server type
        RewardServerType _rewardServerType;
    
        // popicon image view reference
        UIImageView *_refPopiconImageView;

        // view controller
        UIViewController *_viewController;

        // current orientation
        NSUInteger _currentOrientaion;
}

// AdPopcorn delegate
@property (nonatomic, unsafe_unretained) id<AdPopcornDelegate> adPopcornDelegate;
// root view (Deprecated in AdPopcornSDK 2.0.3i)
@property (nonatomic, strong) UIView *rootView __deprecated;

@property (nonatomic, readonly) UIViewController *viewController;

// user data dictionary for filter, ex) [NSMutableDictionary dictionaryWithObjectsAndKeys:@"30",AP_FILTER_KEY_AGE,AP_FILTER_VALUE_MALE,AP_FILTER_KEY_GENDER, nil]];
@property (nonatomic, strong) NSMutableDictionary *userDataDictionaryForFilter;
// style
@property (nonatomic, strong) AdPopcornStyle *adPopcornStyle;

/*!
 @abstract
 초기화. AppDelegate에서 앱 기동시 초기화한다.
 
 @discussion
 App. 기동시 한번만 호출하면 된다. 따라서 AppDelegate 클래스의 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 메소드에서 호출할것을 권장한다.
 
 @param mediakey            미디어 등록 후, IGAWorks로부터 발급된 키.
 @param hashkey             미디어 등록 후 발급된 키.
 @param userSerialNumber    User를 식별할 수 있는 고유번호(1기기당 1개).
 @param rewardServerType    reward server type으로 AdPopcornRewardServerTypeServer, AdPopcornRewardServerTypeClient, AdPopcornRewardServerTypePoint 중 목적에 맞게 선택.
 @param activeTracer        tracer 사용할건지 여부
 */
+ (AdPopcornSDK *)initAdPopcorn:(NSString *)mediaKey hashKey:(NSString *)hashKey userSerialNumber:(NSString *)userSerialNumber rewardServerType:(RewardServerType)rewardServerType activeTracer:(BOOL)activeTracer;

/*!
 @abstract
 singleton AdPopcornSDK 객체를 반환한다.
 */
+ (AdPopcornSDK *)shared;

/*!
 @abstract
 초기화. AdPopcornSDK 객체를 반환한다.
  
 @param mediakey            미디어 등록 후, IGAWorks로부터 발급된 키.
 @param hashkey             미디어 등록 후 발급된 키.
 @param userSerialNumber    User를 식별할 수 있는 고유번호(1기기당 1개).
 @param rewardServerType    reward server type으로 AdPopcornRewardServerTypeServer, AdPopcornRewardServerTypeClient, AdPopcornRewardServerTypePoint 중 목적에 맞게 선택.
 @param activeTracer        tracer 사용할건지 여부
 */
- (id)initWithMediaKey:(NSString *)mediaKey hashKey:(NSString *)hashKey userSerialNumber:(NSString *)userSerialNumber rewardServerType:(RewardServerType)rewardServerType activeTracer:(BOOL)activeTracer;

/*!
 @abstract
 Show popicon.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) popicon을 노출하고자할 때 호출한다.
 
 @param popiconImageView            popicon image view
 */
- (void)showPopicon:(UIImageView *)popiconImageView __deprecated;


/*!
 @abstract
 Show popicon.
 
 @discussion
 popicon을 노출하고자할 때 호출한다.
 
 @param popiconImageView            popicon image view
 */
- (void)showPopicon:(UIImageView *)popiconImageView WithViewController:(UIViewController *)vController;


/*!
 @abstract
 Open offerwall.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) 리스트 형태의 광고를 노출한다.
 */
- (void)openOfferWall __deprecated;


/*!
 @abstract
 Open offerwall.
 
 @discussion
 리스트 형태의 광고를 노출한다.
 */
- (void)openOfferWallWithViewController:(UIViewController *)vController;


/*!
 @abstract
 단말기 고유 ID를 리턴한다.
 */
- (NSString *)getAdPopcornIdentifier;

/*!
 @abstract
 매체에서 사용하는 고유 사용자 ID를 설정한다.
 
 @param userSerialNumber            고유 사용자 ID
 */
- (void)setUserSerialNumber:(NSString *)userSerialNumber;

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
+ (void)setLogLevel:(AdPopcornLogLogLevel)logLevel;

/*!
 @abstract
 IGAWorks에 리워드 지급 확정 처리를 요청한다.
 
 @discussion
 이곳에서 사용자에게 리워드 지급 처리를 한다. 지급 처리가 완료 되었다면, 해당 메소드를 호출하여 IGAWorks에 리워드 지급 확정 처리를 요청한다.
 
 @param rewardKey            리워드 식별키
 */
- (void)didGiveRewardItemWithRewardKey:(NSString *)rewardKey;


@end


/*!
 @abstract
 AdPopcorn Delegate
 
 @discussion
 To use AdPopcornSDK more efficiently, implement these delegate methods.
 AdPopcornSDK를 더 효과적으로 연동하시기 위해서는 아래 델리게이트 함수들을 구현하시면 됩니다.
 */
@protocol AdPopcornDelegate <NSObject>

@optional
/*!
 @abstract
 popcion이 화면에 노출되기 직전에 호출된다.
 
 @discussion
 게임에서 적절하게 클릭을 유도하는 장치를 별도로 구현하여 참여를 독려하기를 권장한다.
 */
- (void)willAppearPopiconView:(CGRect)popiconFrame;

/*!
 @abstract
 popcion이 화면에 사라지기 직전에 호출된다.
 
 @discussion
 */
- (void)willDisappearPopiconView;

/*!
 @abstract
 popcion을 눌렀을때 이벤트 뷰가 열리기 직전에 호출된다.
 
 @discussion
 진행중이 task를 일시 정지하기를 권장한다. 슈팅게임과 같은 지속적으로 컨트롤 해야하는 App.에 권장한다.
 
 */
- (void)willOpenEventView;

/*!
 @abstract
 이벤트 뷰가 닫힌직 후 호출된다.
 
 @discussion
 willOpenEventView delegate 메소드에서 일시 정지한 task를 다시 재개할때 사용하기를 권장한다.
 */
- (void)didCloseEventView;


/*!
 @abstract
 offerwall 리스트가 열리기 전에 호출된다.
 
 @discussion
 */
- (void)willOpenOfferWall;

/*!
 @abstract
 offerwall 리스트가 열린직 후 호출된다.
 
 @discussion
 */
- (void)didOpenOfferWall;


/*!
 @abstract
 offerwall 리스트가 닫히기 전에 호출된다.
 
 @discussion
 */
- (void)willCloseOfferWall;

/*!
 @abstract
 offerwall 리스트가 닫힌직 후 호출된다.
 
 @discussion
 */
- (void)didCloseOfferWall;


/*!
 @abstract
 이벤트 참여 완로 직후에 호출된다.
 
 @discussion
 이벤트 참여 완료 후, 즉시 아이템 확인하고 사용할 수 있도록 설정하는것을 권장한다.
 */
- (void)didEventCompleteWithItemKey:(NSString *)itemKey;


@optional

/*!
 @abstract
 (Deprecated in AdPopcornSDK 2.0.1i) 사용자에게 지급할 아이템이 있을때 호출된다.
 
 @discussion
 사용자에게 아이템을 지급하고, 지급이 완료되면 didGiveRewardItemWithRewardKey 메소드를 호출하여 지급 완료 확정 처리를 한다.
 */
- (void)onRewardRequestResult:(BOOL)isSuccess withMessage:(NSString *)message itemName:(NSString *)itemName itemKey:(NSString*)itemKey campaignName:(NSString *)campaignName campaignKey:(NSString*)campaignKey rewardKey:(NSString *)rewardkey __deprecated;


/*!
 @abstract
 사용자에게 지급할 아이템이 있을때 호출된다.
 
 @discussion
 사용자에게 아이템을 지급하고, 지급이 완료되면 didGiveRewardItemWithRewardKey 메소드를 호출하여 지급 완료 확정 처리를 한다.
 */
- (void)onRewardRequestResult:(BOOL)isSuccess withMessage:(NSString *)message itemName:(NSString *)itemName itemKey:(NSString*)itemKey campaignName:(NSString *)campaignName campaignKey:(NSString*)campaignKey rewardKey:(NSString *)rewardkey quantity:(NSUInteger)quantity;


/*!
 @abstract
 사용자에게 지급할 아이템이 있을때 호출된다. 아이템 리스트를 전달한다.
 
 @discussion
 사용자에게 아이템을 지급하고, 지급이 완료되면 didGiveRewardItemWithRewardKey 메소드를 호출하여 지급 완료 확정 처리를 한다.
 */
- (void)onRewardRequestResult:(BOOL)isSuccess withMessage:(NSString *)message items:(NSArray *)itemes;

/*!
 @abstract
 Reward 지급 확정 처리 콜백 메소드.
 
 @discussion
 didGiveRewardItemWithRewardKey 메소드에서 reward 지급 처리를 완료한 뒤에 IGAWorks에 요청한 결과가 이 곳으로 리턴된다. isSuccess가 YES가 리턴되어야 최종 reward 지급이 완료된다.
 */
- (void)onRewardCompleteResult:(BOOL)isSuccess withMessage:(NSString *)message resultCode:(NSUInteger)resultCode withCompletedRewardKey:(NSString *)completedRewardKey;


@optional
/*!
 @abstract
 popcode 처리 결과를 noti.한다.
 
 @param isSuccess            처리 결과, 성공 : YES, 실패 : NO
 @param resultCode           결과 코드
 @param popcode              pop 코드
 @param resultMsg            결과 메세지
 */
- (void)getPopcodeIsResult:(BOOL)isSuccess andResultCode:(NSUInteger)resultCode withPopCode:(NSString *)popcode andResultMsg:(NSString *)resultMsg;

/*!
 @abstract
 처리 시간을 over한 경우에 noti.한다.
 
 @discussion
 기본 30분으로 설정되어 있다.
 
 @param firstExecTime        최초 처리 시간
 */
- (void)overTimeWithFirstExecTime:(long)firstExecTime;

@optional
/*!
 @abstract
 tracer 처리 결과를 noti.한다
 
 @discussion
 모바일 to 모바일 앱 다운로드 캠페인을 진행할때 사용하며, tracer의 connectByAppKey 메소드를 호출하면, 해당 delegate 매소드로 처리 결과를 noti.한다.
 
 @param firstExecTime        최초 처리 시간
 */
- (void)didConnected:(BOOL)isSuccess withResultCode:(NSUInteger)resultCode andMessage:(NSString *)message;

@end

