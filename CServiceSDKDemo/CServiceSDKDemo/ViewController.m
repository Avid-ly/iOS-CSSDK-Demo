//
//  ViewController.m
//  CServiceSDKDemo
//
//  Created by 何健 on 12/11/19.
//  Copyright © 2019 何健. All rights reserved.
//

#import "ViewController.h"
//#import <AASAccount/AASAccountSDK.h>
#import <TraceAnalysisSDK/TraceAnalysis.h>
#import <CServiceSDK/CServiceSDK.h>

NSString *defaultProductID = @"600168";
NSString *defaultChannelID = @"666666";
NSString *defaultAppID = @"id123456";

@interface ViewController ()
{
    UIButton *_button4;
    UITextField *_pdtID;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGFloat y = 40;
    
    _pdtID = [[UITextField alloc]init];
    _pdtID.backgroundColor = [UIColor whiteColor];
    _pdtID.layer.borderWidth = 1.0f;
    _pdtID.layer.borderColor = [UIColor colorWithRed:0xbf/255.0f green:0xbf/255.0f blue:0xbf/255.0f alpha:1].CGColor;;
    _pdtID.placeholder = [NSString stringWithFormat:@"请输入产品ID,不填默认 %@",defaultProductID];
    _pdtID.frame = CGRectMake(self.view.frame.size.width/2 - 250/2, y + 10, 250, 40);
    [self.view addSubview:_pdtID];
    y = _pdtID.frame.origin.y + _pdtID.frame.size.height;
    
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

    NSString *pid = defaultProductID;
    if (_pdtID.text != nil && ![_pdtID.text isEqualToString:@""]) {
        pid = _pdtID.text;
    }
    
    // 统计SDK和账户SDK，至少有一个
    // 初始化统计SDK
    [TraceAnalysis initWithProductId:pid ChannelId:defaultChannelID AppID:defaultAppID];
    
    // 初始化账户SDK
    //    [AASAccountSDK initSDK:@"600168"];
    //    [AASAccountSDK setLoginCallback:^(AASAccountLoginModel * _Nonnull model) {
    //
    //        NSLog(@"AASAccountSDK login gameGuestId:%@，loginMode:%d",model.gameGuestId,model.loginMode);
    //    } errorCallback:^(NSError * _Nonnull error) {
    //
    //        NSLog(@"AASAccountSDK login error:%@",error);
    //    }];
    //    [AASAccountSDK login];
    
    // 追加透传参数
    NSDictionary *dic = [[NSDictionary alloc] initWithObjectsAndKeys:@"0.212.31", @"hot_version", nil];
    [CServiceSDK addExtraParam:dic];
    
    BOOL succeed = [CServiceSDK initSDK:pid];
    
    NSString *message = succeed?@"初始化成功":@"初始化失败,请检查";
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"" message:message preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"ok" style:UIAlertActionStyleCancel handler:nil]];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)faqView {
    // 显示客服页面
    [CServiceSDK show:self];
}

- (void)newMessageClick {
    
    // 查询是否有新消息
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
    // 获取 客服SDK 版本号
    NSString *ver =  [CServiceSDK getVersion];
    NSLog(@"version is %@",ver);
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_button4 setTitle:ver forState:UIControlStateNormal];
    });
}
@end
