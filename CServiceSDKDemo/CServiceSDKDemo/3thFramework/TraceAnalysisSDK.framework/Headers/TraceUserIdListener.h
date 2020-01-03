//
//  TraceUserIdListener.h
//
//  Created by samliu on 2017/7/4.
//  Copyright © 2017年 samliu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TraceUserIdListener <NSObject>

@optional
- (void)onUserIdGetSuccess:(NSString*)userid;

@end
