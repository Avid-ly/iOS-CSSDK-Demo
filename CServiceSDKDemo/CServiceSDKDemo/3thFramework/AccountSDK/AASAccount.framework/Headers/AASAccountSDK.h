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

NS_ASSUME_NONNULL_BEGIN

@interface AASAccountSDK : NSObject

+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

+ (void)initSDK:(NSString *)productId;

+ (void)setLoginCallback:(void (^)(AASAccountLoginModel *model))succeedCallback errorCallback:(void (^)(NSError *error))errorCallback;

+ (void)login;

+ (NSString *)getFacebookLoginedToken;

+ (void)showUserCenter:(UIViewController *)vc;

+ (NSString *)getGGID;

@end

NS_ASSUME_NONNULL_END
