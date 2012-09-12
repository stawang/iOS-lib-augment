//
//  UIButton+notify.h
//  deweiguardian
//
//  Created by wgs on 12-8-23.
//  Copyright (c) 2012年 wgs.
//  mail: stawangguoshi@gmail.com
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

@interface UIButton (notify)
/*!
 @method setNotification:
 @abstract 给button按钮添加红色提示信息
 @discussion 若果提示框已经存在，则把当前条目数量添加上count，然后再显示
 @param count   提示的信息，标示有多少条目
 @result none
 */
- (void)setNotification:(NSInteger)count;

/*!
 @method resetNotification
 @abstract 重置按钮，去掉红色信息提示框
 @discussion none
 @result none
 */
- (void)resetNotification;
@end
