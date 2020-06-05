//
//  AASLoginViewController.h
//  AccountSDK
//
//  Created by steve on 2019/1/31.
//  Copyright © 2019 Technology Co.,Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AASLoginViewController : UIViewController

+ (instancetype)shareInstance;

- (void)showAutoLogin;

- (void)showHomepageLogin;

- (void)showSignupAndBindding;

- (void)addData:(NSString *)text;

/** 本地数据数组 */
@property (nonatomic, strong) NSMutableArray *localArrM;
@end

NS_ASSUME_NONNULL_END
