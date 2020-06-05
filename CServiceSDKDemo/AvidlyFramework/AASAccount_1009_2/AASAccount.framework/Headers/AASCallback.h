//
//  AASCallback.h
//  AccountSDK
//
//  Created by steve on 2019/2/19.
//  Copyright © 2019  Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^CallbackBlock)(id obj);

@interface AASCallback : NSObject

+ (instancetype)shareInstance;

@property (nonatomic,copy) CallbackBlock loginSucceedBlock;
@property (nonatomic,copy) CallbackBlock loginErrorBlock;

@end
