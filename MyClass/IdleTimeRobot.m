//
//  IdleTimeRobot.m
//
// Created by wgs on 13-4-21.
// Copyright (c) 2013年 wgs.
// mail: stawangguoshi@gmail.com
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//

#import "IdleTimeRobot.h"

#define IDLETIMEROBOT_NOTIFICATION @"w_idletime_notification"
#define wIdleTimeErrorDomain @"w_idletime_errordomain"

enum wIdleTimeRobotErrorCode {
    wIdleTimeRobotObserverNilError = 1,
};

@interface IdleTimeRobot ()
@property (nonatomic, weak) id itrObserver;
@end

@implementation IdleTimeRobot

- (id)init {
    self = [super init];
    if (nil != self) {
        self.itrObserver = nil;
    }
    
    return self;
}

- (void)wrapError:(NSError**)err errStr:(NSString*)estr {
    NSDictionary * dict = [NSDictionary dictionaryWithObject:estr forKey:NSLocalizedDescriptionKey];
    *err = [NSError errorWithDomain:wIdleTimeErrorDomain code:wIdleTimeRobotObserverNilError userInfo:dict];
}

- (void)removeIdleTimeRobotObserver {
    [[NSNotificationCenter defaultCenter] removeObserver:_itrObserver name:IDLETIMEROBOT_NOTIFICATION object:nil];
}

- (BOOL)registerIdleObserver:(id)observer selector:(SEL)sel error:(NSError**)err{
    BOOL registerResult = NO;
    if (nil != observer) {
        //remove old observer
        if (nil != _itrObserver) {
            [self removeIdleTimeRobotObserver];
            self.itrObserver = observer;
        }
        
        [[NSNotificationCenter defaultCenter] addObserver:observer selector:sel name:IDLETIMEROBOT_NOTIFICATION object:nil];
        NSNotification *notification = [NSNotification
                                        notificationWithName:IDLETIMEROBOT_NOTIFICATION object:nil];
        [[NSNotificationQueue defaultQueue] enqueueNotification:notification
                                                   postingStyle:NSPostWhenIdle];
        registerResult = YES;
    } else {
        if (err) {
            NSString* errStr = NSLocalizedString(@"Observer should be not nil", nil);
            [self wrapError:err errStr:errStr];
        }
    }
    
    return registerResult;
}

- (void)unregisterObserver {
    if (nil != _itrObserver) {
        [self removeIdleTimeRobotObserver];
    }
}
@end
