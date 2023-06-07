//
//  CServiceSDK.h
//  CSSDK
//
//  Created by Steve on 11/18/19.
//  Copyright © 2019 customerservice. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CServiceSDK : NSObject

#pragma mark - init

+ (BOOL)initSDK:(NSString *)pdtId;

#pragma mark - view

+ (BOOL)show:(UIViewController *)vc;

#pragma mark - faq view

+ (BOOL)showFAQ:(UIViewController *)vc;

#pragma mark - question view

+ (BOOL)showQuestion:(UIViewController *)vc;

+ (BOOL)showQuestion:(UIViewController *)vc gameAccountId:(NSString *)gameAccountId scene:(NSString *)scene customParams:(NSString *)customParams;

+ (void)submitQuestion:(NSString *)questionType questionContent:(NSString *)questionContent gameAccountId:(NSString *)gameAccountId scene:(NSString *)scene images:(NSArray <UIImage *> *)images customParams:(NSString *)customParams completion:(void (^)(BOOL succeed, NSError *error))completionBlock;

+ (void)submitQuestion:(NSString *)questionType questionContent:(NSString *)questionContent gameAccountId:(NSString *)gameAccountId scene:(NSString *)scene imagePaths:(NSArray <NSString *> *)imagePaths customParams:(NSString *)customParams completion:(void (^)(BOOL succeed, NSError *error))completionBlock;

#pragma mark - message

+ (void)haveNewMessage:(void (^)(BOOL haveNewMessage))completionBlock;

#pragma mark - util

+ (void)addExtraParam:(NSDictionary *)param;

#pragma mark - version

+ (NSString *)getVersion;

@end
