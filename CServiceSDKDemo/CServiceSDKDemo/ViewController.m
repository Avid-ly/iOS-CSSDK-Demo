//
//  ViewController.m
//  CServiceSDKDemo
//
//  Created by 何健 on 12/11/19.
//  Copyright © 2019 何健. All rights reserved.
//

#import "ViewController.h"
#import <AASAccount/AASAccountSDK.h>
#import <TraceAnalysisSDK/TraceAnalysis.h>
#import <CServiceSDK/CServiceSDK.h>

@interface ViewController ()
{
    UIButton *_button4;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGFloat y = 40;
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, y + 10, 250, 40);
    [button setTitle:@"init" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(initSDK) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    y = button.frame.origin.y + button.frame.size.height;
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.backgroundColor = [UIColor orangeColor];
    button2.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, y + 60, 250, 40);
    [button2 setTitle:@"反馈问题" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(faqView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    y = button2.frame.origin.y + button2.frame.size.height;
    
    UIButton *button4 = [UIButton buttonWithType:UIButtonTypeCustom];
    button4.backgroundColor = [UIColor orangeColor];
    button4.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, y + 10, 250, 40);
    [button4 setTitle:@"是否有新消息" forState:UIControlStateNormal];
    [button4 addTarget:self action:@selector(newMessageClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button4];
    y = button4.frame.origin.y + button4.frame.size.height;
    
    _button4 = [UIButton buttonWithType:UIButtonTypeCustom];
    _button4.backgroundColor = [UIColor orangeColor];
    _button4.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, y + 10, 250, 40);
    [_button4 setTitle:@"获取版本号" forState:UIControlStateNormal];
    [_button4 addTarget:self action:@selector(getVer) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_button4];
}

-(void)initSDK {
    
    NSString *productId = @"600168";
    NSString *channelId = @"32400";
    NSString *appId = @"id123456789";
    
    [TraceAnalysis initWithProductId:productId ChannelId:channelId AppID:appId];

    [AASAccountSDK initSDK:productId];
    [AASAccountSDK setLoginCallback:^(AASAccountLoginModel * _Nonnull model) {

        NSLog(@"AASAccountSDK login gameGuestId:%@，loginMode:%d",model.gameGuestId,model.loginMode);
    } errorCallback:^(NSError * _Nonnull error) {

        NSLog(@"AASAccountSDK login error:%@",error);
    }];
    [AASAccountSDK login];
    

    BOOL succeed = [CServiceSDK initSDK:productId];
    if (succeed) {
        NSLog(@"初始化成功");
    } else {
        NSLog(@"初始化失败,请检查");
    }
}

- (void)faqView {
    [CServiceSDK show:self];
    
}

- (void)newMessageClick {
    
    [CServiceSDK haveNewMessage:^(BOOL haveNewMessage) {
        
        // 回到主线程处理
        dispatch_async(dispatch_get_main_queue(), ^{
            UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"" message:[NSString stringWithFormat:@"是否有新消息 %@",haveNewMessage?@"YES":@"NO"] preferredStyle:UIAlertControllerStyleAlert];
            [alertController addAction:[UIAlertAction actionWithTitle:@"ok" style:UIAlertActionStyleCancel handler:nil]];
            [self presentViewController:alertController animated:YES completion:nil];
        });
    }];
}

- (void)getVer {
    NSString *ver =  [CServiceSDK getVersion];
    NSLog(@"version is %@",ver);
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_button4 setTitle:ver forState:UIControlStateNormal];
    });
}
@end
