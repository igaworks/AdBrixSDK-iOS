//
//  AdPOPcornSDKRevisionAdvanced.h
//  AdPOPcornSDKRevision
//
//  Created by wonje,song on 13. 1. 21..
//  Copyright (c) 2013년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdPopcornSDK.h"

/*!
 @header
 
 @abstract  Advanced 라이브러리 헤더, AdPopcorn의 advanced된 서비스를 사용하기 위해 이 파일을 import 해야한다.
 
 @discussion   기본 서비스를 제공하는 AdPopcornSDK를 상속하여, popcode, tracking 서비스와, 기타 추가적인 기능을 제공한다.
 
 */
@interface AdPopcornSDKAdvanced : AdPopcornSDK
{
    @private
        // popcode
        BOOL _activePopcode;
        PopCodeService *_apPopCodeService;
}

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
 @param tracerActivity      tracer activity를 추척하기 위한 설정값
 @param activePopcode       popcode 사용할건지 여부
 */
+ (AdPopcornSDKAdvanced *)initAdPopcorn:(NSString *)mediaKey hashKey:(NSString *)hashKey userSerialNumber:(NSString *)userSerialNumber rewardServerType:(RewardServerType)rewardServerType activeTracer:(BOOL)activeTracer tracerActivity:(NSString *)tracerActivity activePopcode:(BOOL)activePopcode;

/*!
 @abstract
 singleton AdPopcornSDKAdvanced 객체를 반환한다.
 */
+ (AdPopcornSDKAdvanced *)shared;

/*!
 @abstract
 초기화. AdPopcornSDK 객체를 반환한다.
 
 @param mediakey            미디어 등록 후, IGAWorks로부터 발급된 키.
 @param hashkey             미디어 등록 후 발급된 키.
 @param userSerialNumber    User를 식별할 수 있는 고유번호(1기기당 1개).
 @param rewardServerType    reward server type으로 AdPopcornRewardServerTypeServer, AdPopcornRewardServerTypeClient, AdPopcornRewardServerTypePoint 중 목적에 맞게 선택.
 @param activeTracer        tracer 사용할건지 여부
 @param tracerActivity      tracer activity를 추척하기 위한 설정값
 @param activePopcode       popcode 사용할건지 여부
 */
- (id)initWithMediaKey:(NSString *)mediaKey hashKey:(NSString *)hashKey userSerialNumber:(NSString *)userSerialNumber rewardServerType:(RewardServerType)rewardServerType activeTracer:(BOOL)activeTracer tracerActivity:(NSString *)tracerActivity activePopcode:(BOOL)activePopcode;

/*!
 @abstract
 Show popicon.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) popicon을 노출하고자할 때 호출한다.
 
 @param popiconImageView            popicon image view
 @param trackCode                   tracking을 위한 코드
 */
- (void)showPopicon:(UIImageView *)popiconImageView andTrackCode:(NSString *)trackCode __deprecated;


/*!
 @abstract
 Show popicon.
 
 @discussion
 popicon을 노출하고자할 때 호출한다.
 
 @param popiconImageView            popicon image view
 @param trackCode                   tracking을 위한 코드
 */
- (void)showPopicon:(UIImageView *)popiconImageView WithViewController:(UIViewController *)vController andTrackCode:(NSString *)trackCode;

/*!
 @abstract
 Open offerwall.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) 리스트 형태의 광고를 노출한다.
 
 @param trackCode                   tracking을 위한 코드
 */
- (void)openOfferWall:(NSString *)trackCode __deprecated;

/*!
 @abstract
 Open offerwall.
 
 @discussion
 리스트 형태의 광고를 노출한다.
 
 @param trackCode                   tracking을 위한 코드
 */
- (void)openOfferWallWithViewController:(UIViewController *)vController andTrackCode:(NSString *)trackCode;

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
 Open event view.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) custom 로고 이미지와 리스트 버튼을 노출할지 여부와 함께 이벤트 페이지를 오픈한다.
 
 @param adUrl                       광고주 페이지 url
 @param isInlinePopup               리스트 버튼 노출할지 여부
 @param customLogoImageUrl          custom logo 이미지 url
 */
- (void)openEventView:(NSString *)adUrl andIsInlinePopup:(BOOL)isInlinePopup andCustomLogoImageUrl:(NSString *)customLogoImageUrl __deprecated;

/*!
 @abstract
 Open event view with track code.
 
 @discussion
 (Deprecated in AdPopcornSDK 2.0.3i) custom 로고 이미지와 리스트 버튼을 노출할지 여부와 함께 이벤트 페이지를 오픈한다.
 
 @param adUrl                       광고주 페이지 url
 @param isInlinePopup               리스트 버튼 노출할지 여부
 @param customLogoImageUrl          custom logo 이미지 url
 @param trackCode                   tracking을 위한 코드
 */
- (void)openEventView:(NSString *)adUrl andIsInlinePopup:(BOOL)isInlinePopup andCustomLogoImageUrl:(NSString *)customLogoImageUrl andTrackCode:(NSString *)trackCode __deprecated;

/*!
 @abstract
 Open event view.
 
 @discussion
 custom 로고 이미지와 리스트 버튼을 노출할지 여부와 함께 이벤트 페이지를 오픈한다.
 
 @param adUrl                       광고주 페이지 url
 @param isInlinePopup               리스트 버튼 노출할지 여부
 @param customLogoImageUrl          custom logo 이미지 url
 */
- (void)openEventViewWithViewController:(UIViewController *)vController andAdUrl:(NSString *)adUrl andIsInlinePopup:(BOOL)isInlinePopup andCustomLogoImageUrl:(NSString *)customLogoImageUrl;

/*!
 @abstract
 Open event view with track code.
 
 @discussion
 custom 로고 이미지와 리스트 버튼을 노출할지 여부와 함께 이벤트 페이지를 오픈한다.
 
 @param adUrl                       광고주 페이지 url
 @param isInlinePopup               리스트 버튼 노출할지 여부
 @param customLogoImageUrl          custom logo 이미지 url
 @param trackCode                   tracking을 위한 코드
 */
- (void)openEventViewWithViewController:(UIViewController *)vController andAdUrl:(NSString *)adUrl andIsInlinePopup:(BOOL)isInlinePopup andCustomLogoImageUrl:(NSString *)customLogoImageUrl andTrackCode:(NSString *)trackCode;

/*!
 @abstract
 자세한 로그를 볼지 여부를 설정한다.
 
 @discussion
 param isEnable값이 YES이면 로그 레벨의 info, debug, trace의 로그를 확인하고, isEnable값이 NO이면 info, debug 로그를 확인하다.
 
 @param isEnable            세부 로그 볼지 여부
 */
+ (void)viewDetailLog:(bool)isEnable;

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

/*!
 @abstract
 광고 리스트를 josn 데이타로 제공하는 url를 반환한다.
 
 @discussion
 해당 url를 통해 얻어진 json 객체를 사용하여, user에게 목록 형태의 광고 리스트를 구성하여 보여준다.
 */
- (NSString *)getCampaignListJsonUrl;


@end
