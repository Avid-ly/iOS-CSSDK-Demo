//
//  AASBaseParameter.h
//  AccountSDK
//
//  Created by steve on 2019/1/23.
//  Copyright © 2019 Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AASBaseParameter : NSObject

@property(nonatomic,copy) NSString *productId;

+ (instancetype)shareInstance;

+ (NSMutableDictionary *)getBaseParamter;

@end

NS_ASSUME_NONNULL_END
