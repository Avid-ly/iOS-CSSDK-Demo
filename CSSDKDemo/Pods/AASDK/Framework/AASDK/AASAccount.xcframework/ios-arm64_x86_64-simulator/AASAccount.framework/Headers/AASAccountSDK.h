//
//  AccountSDK.h
//  AccountSDK
//
//  Created by steve on 2019/1/24.
//  Copyright © 2019  Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AASEnumDefine.h"
#import "AASAccountLoginModel.h"

@interface AASAccountSDK : NSObject

#pragma mark - Init

+ (void)initSDK:(NSString *)productId;

#pragma mark - Application

+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

#pragma mark - Callback

+ (void)setLoginCallback:(void (^)(AASAccountLoginModel *model))succeedCallback errorCallback:(void (^)(NSError *error))errorCallback;

+ (void)setLoginCallback:(void (^)(AASAccountLoginModel *model))succeedCallback errorCallback:(void (^)(NSError *error))errorCallback cancelCallback:(void (^)(NSString *msg))cancelCallback;

+ (void)setBindCallback:(void (^)(AASAccountLoginModel *model))succeedCallback errorCallback:(void (^)(NSError *error))errorCallback;

#pragma mark - Login

+ (void)login;

+ (void)loginWithVisible:(BOOL)visible; // visible为false，表示自动登录不展示弹窗

+ (void)loginWithUnAware;

#pragma mark - UserCenter

+ (void)showUserCenter:(UIViewController *)vc;

#pragma mark - Parameter

+ (NSString *)getFacebookLoginedToken;

+ (NSString *)getGGID;

#pragma mark - Delete Account

+ (void)enableDeleteAccount:(BOOL)enable;

+ (void)registerDeleteAccountCallback:(void (^)(AASAccountLoginModel *model))callback;

+ (void)notifySDKDeletedAccountCallback:(void (^)(NSError *error))callback;

@end
