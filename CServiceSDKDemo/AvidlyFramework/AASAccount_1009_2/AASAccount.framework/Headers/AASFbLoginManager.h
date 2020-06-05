//
//  AASFbLoginManager.h
//  AccountSDK
//
//  Created by steve on 2019/1/25.
//  Copyright © 2019  Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AASFbLoginManager : NSObject

/**
 授权并登录

 @param completeBlock 回调
 */
+ (void)loginWithRootViewController:(UIViewController *)rootViewController completeBlock:(void (^)(BOOL succeed, id responseObject, NSError *error))completeBlock;

/**
 授权登录并绑定ggid

 @param gameGuestId ggid
 @param completeBlock 回调
 */
+ (void)loginAndBinddingWithGameGuestId:(NSString *)gameGuestId
                          completeBlock:(void (^)(BOOL succeed, id responseObject, NSError *error))completeBlock;

/**
 解除ggid绑定

 @param gameGuestId ggid
 @param appId appId
 @param tokenString tokenString
 @param completeBlock 回调
 */
+ (void)unBinddingWithGameGuestId:(NSString *)gameGuestId
                            appId:(NSString *)appId
                      tokenString:(NSString *)tokenString
                           userId:(NSString *)userId
                    completeBlock:(void (^)(BOOL succeed, id responseObject, NSError *error))completeBlock;

+ (void)unBinddingWithGameGuestId:(NSString *)gameGuestId
                           atoken:(NSString *)atoken
                    completeBlock:(void (^)(BOOL succeed, id responseObject, NSError *error))completeBlock ;

/**
 自动登录（已存储授权）

 @param appId appId
 @param tokenString tokenString
 @param completeBlock 回调
 */
+ (void)autoLoginWithAppId:(NSString *)appId
               tokenString:(NSString *)tokenString
                    userId:(NSString *)userId
             completeBlock:(void (^)(BOOL succeed, id responseObject, NSError *error))completeBlock;

@end

NS_ASSUME_NONNULL_END
