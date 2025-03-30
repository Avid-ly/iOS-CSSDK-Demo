//
//  AASEnumDefine.h
//  yAccountSDK
//
//  Created by samliu on 2019/1/23.
//  Copyright © 2019年 Technology Co.,Ltd. All rights reserved.
//
#import <Foundation/Foundation.h>

#ifndef AASEnumDefine_h
#define AASEnumDefine_h

#define AAS_USER_SERVICE_AGREEMENT_URL @"https://d5q0hty07mfa4.cloudfront.net/privacy_policy/pp_cn.html"

#define ACCOUNT_MODE_GUEST 1
#define ACCOUNT_MODE_AAS  2
#define ACCOUNT_MODE_FACEBOOK  3
#define ACCOUNT_MODE_GOOGLEPLAY  4
#define ACCOUNT_MODE_TWITTER  6
#define ACCOUNT_MODE_INSTAGRAM 8
#define ACCOUNT_MODE_GAMECENTER 9
#define ACCOUNT_MODE_ULT 10
#define ACCOUNT_MODE_APPLE 11

#define AACOUNT_NAME @"accountName"
#define AACOUNT_NICK_NAME @"nickname"
#define AACOUNT_PASSWORD @"accountPwd"
#define AACOUNT_MODE @"mode"
#define AACOUNT_BINDED @"isBinded"
#define AACOUNT_FB_APPID @"fbAppId"
#define AACOUNT_FB_TOKEN @"fbToken"
#define AACOUNT_FB_USERID @"fbUserId"
#define AACOUNT_FB_AUTHENTICATIONTOKEN @"fbAuthenticationToken"

#define ALOGIN_USER_GGID @"ggid"
#define ALOGIN_USER_TOKEN @"token"
#define ALOGIN_USER_LOGIN_MODE @"loginedMode"
#define ALOGIN_USER_ACTIVED @"actived"
#define ALOGIN_USER_ACCOUNTS @"accounts"

#define ALOGIN_USER_ISVERIFIEDEMAIL @"isVerifiedEmail"
#define ALOGIN_USER_VERIFIEDEMAIL @"verifyEmail"

#define USERDEFAULT_KEY_GUEST_USER  @"guest_user"
#define USERDEFAULT_KEY_ACCOUNT_USER  @"account_user"

#define AACOUNT_APPLE_GCPLAYERID @"appleGCPlayerId"
#define AACOUNT_APPLE_GCPLAYERNAME @"appleGCPlayerName"
#define AACOUNT_APPLE_BUNDLEID @"appleBundleId"
#define AACOUNT_APPLE_GC_PUBLICKKEY_URL @"appleGCPublicKeyURL"
#define AACOUNT_APPLE_GC_SIGNATURE @"appleGCSignature"
#define AACOUNT_APPLE_GC_SALT @"appleGCSalt"
#define AACOUNT_GC_TIMESTAMP @"appleGCTimeStamp"

#define ATOKEN @"atoken"
#define IDTOKEN @"idToken"

#define CONSUMERKEY @"consumerKey"
#define CONSUMERSECRET @"consumerSecret"
#define ACCESSTOKEN @"accessToken"
#define ACCESSTOKENSECRET @"accessTokenSecret"

#define AACOUNT_APPLE_ID_USERIDENTIFIER @"appleIdUserIdentifier"
#define AACOUNT_APPLE_ID_IDENTITYTOKEN @"appleIdIdentityToken"
#define AACOUNT_APPLE_ID_EMAIL @"appleIdEmail"
#define AACOUNT_APPLE_ID_FAMILYNAME @"appleIdFamilyName"
#define AACOUNT_APPLE_ID_GIVENNAME @"appleIdGivenName"

#endif /* AASEnumDefine_h */
