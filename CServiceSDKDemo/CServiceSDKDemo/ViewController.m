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
#import <CSSDK/CServiceSDK.h>

@interface ViewController ()
{
    UIButton *_button4;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UIButton *button = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 200, 200)];
    button.backgroundColor = [UIColor orangeColor];
    button.frame = CGRectMake(60, 100, 255, 40);
    [button setTitle:@"init" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(initSDK) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    
    UIButton *button2 = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 200, 200)];
    button2.backgroundColor = [UIColor orangeColor];
    button2.frame = CGRectMake(60, 200, 255, 40);
    [button2 setTitle:@"反馈问题" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(FeedbackView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 200, 200)];
    button3.backgroundColor = [UIColor orangeColor];
    button3.frame = CGRectMake(60, 250, 255, 40);
    [button3 setTitle:@"用户中心" forState:UIControlStateNormal];
    [button3 addTarget:self action:@selector(userCenter) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
    
    _button4 = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 200, 200)];
    _button4.backgroundColor = [UIColor orangeColor];
    _button4.frame = CGRectMake(60, 300, 255, 40);
    [_button4 setTitle:@"获取版本号" forState:UIControlStateNormal];
    [_button4 addTarget:self action:@selector(getVer) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_button4];
}

-(void)initSDK {
    [TraceAnalysis initWithProductId:@"1000152" ChannelId:@"666666" AppID:nil];

    [AASAccountSDK initSDK:@"1000152"];
    [AASAccountSDK setLoginCallback:^(AASAccountLoginModel * _Nonnull model) {

        NSLog(@"AASAccountSDK login gameGuestId:%@，loginMode:%d",model.gameGuestId,model.loginMode);
    } errorCallback:^(NSError * _Nonnull error) {

        NSLog(@"AASAccountSDK login error:%@",error);
    }];
    [AASAccountSDK login];
    

    BOOL succeed = [CServiceSDK initSDK:@"1000152"];
    if (succeed) {
        NSLog(@"初始化成功");
    } else {
        NSLog(@"初始化失败,请检查");
    }
}

- (void)FeedbackView {
    [CServiceSDK showFeedbackView:self];
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)userCenter {
    [AASAccountSDK showUserCenter:self];
}

- (void)getVer {
    NSString *ver =  [CServiceSDK getVersion];
    NSLog(@"version is %@",ver);
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_button4 setTitle:ver forState:UIControlStateNormal];
    });
}
@end
