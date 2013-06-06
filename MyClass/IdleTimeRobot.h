//
//  IdleTimeRobot.h
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

#import <Foundation/Foundation.h>

@interface IdleTimeRobot : NSObject
/*!
 @method registerIdleObserver:selector:error:
 @abstract 注册空闲时间监听机器人，当当前应用进入空闲时间时，会触发该selector
 @param observer 监听者，由它来执行应用空闲时间调用selector方法
 @param sel 应用空闲时间时触发的方法
 @param err 注册失败时填充的错误对象
 @result BOOL   YES 注册成功；NO 注册失败
 */
- (BOOL)registerIdleObserver:(id)observer selector:(SEL)sel error:(NSError**)err;

/*!
 @method unregisterObserver
 @abstract  注销监听应用空闲时间事件
 @result NONE
 */
- (void)unregisterObserver;
@end
