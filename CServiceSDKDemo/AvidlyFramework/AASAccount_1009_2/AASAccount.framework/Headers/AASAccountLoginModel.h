//
//  AccountLoginModel.h
//  AccountSDK
//
//  Created by steve on 2019/3/8.
//  Copyright © 2019  Technology Co.,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AASAccountLoginModel : NSObject

@property (nonatomic,copy) NSString *gameGuestId;
@property (nonatomic,copy) NSString *signedRequest;
@property (nonatomic,assign) int loginMode;

@end

NS_ASSUME_NONNULL_END
