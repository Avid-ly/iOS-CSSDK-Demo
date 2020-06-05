//
//  AASLoginUserManager.h
//  AccountSDK
//
//  Created by samliu on 2019/1/23.
//  Copyright © 2019年 Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AASLoginUser.h"
@interface AASLoginUserManager : NSObject
+ (instancetype)shareInstance;

- (void)freshUserCache;

/**
 * 获取当前登陆后有效的ggid
 *
 * @return 返回null，则从未登陆
 */
- (NSString*)getCurrentGGID;

- (NSString*)getCurrentToken;

- (void)updateCurrentAtoken:(NSString *)atoken;
- (NSString*)getCurrentAtoken;

/**
 * 检查当前是否已经登陆
 *
 * @return BOOL
 */
- (BOOL)isLoginedNow;

/**
 * 获取上次登陆成功的用户对象
 *
 * @return AASLoginUser
 */
- (AASLoginUser*)getCurrentActiveLoginUser;

/**
 * 游客登陆成功后调用此方法，记得调用saveAccountUsers()保存用户数据
 *
 * @param ggid ggid
 * @return AASLoginUser
 */
- (AASLoginUser*)onGuestLoginSuccess:(NSString*)ggid;

- (AASLoginUser*)onGuestLoginSuccess:(NSString*)ggid token:(NSString*)token;

/**
 * 帐号用户登陆成功后调用此方法，记得调用saveAccountUsers()保存用户数据
 *
 * @param mode mode
 * @param ggid ggid
 * @return 返回LoginUser，用于更新更多其它的数据
 */
- (AASLoginUser*)onAccountLoginSuccess:(AASAccountModeType)mode ggid:(NSString*)ggid;

- (AASLoginUser*)onAccountLoginSuccess:(AASAccountModeType)mode ggid:(NSString*)ggid token:(NSString*) token;

/**
 * 第三方帐号解绑
 *
 * @param mode mode
 */
- (void)onThirdSdkUnbind:(AASAccountModeType)mode;

/**
 第三方账户绑定

 @param mode mode
 */
- (void)onThirdSdkBind:(AASAccountModeType)mode;

- (void)saveAccountUsers;

- (AASLoginUser*)getGuestLoginUser;

- (AASLoginUser*)getAccountLoginUser;

- (void)removeGuestLoginUser;

@end
