//
//  AccountLoginModel.h
//  AccountSDK
//
//  Created by steve on 2019/3/8.
//  Copyright © 2019  Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 loginMode 字段解释，可参见AASEnumDefine.h中枚举
 1  -->  GUEST
 2  -->  AAS
 3  -->  FACEBOOK
 4  -->  GOOGLEPLAY
 6  -->  TWITTER
 8  -->  INSTAGRAM
 9  -->  GAMECENTER
 10 -->  ULT
 11 -->  APPLE
 */

NS_ASSUME_NONNULL_BEGIN

@interface AASAccountLoginModel : NSObject

@property (nonatomic,copy) NSString *gameGuestId;
@property (nonatomic,copy) NSString *signedRequest;
@property (nonatomic,assign) int loginMode;

@end

NS_ASSUME_NONNULL_END
