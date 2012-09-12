//
//  UIColor+Augument.h
//  ColorSystem
//
//  Created by 309 on 12-9-11.
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



@interface UIColor (Augment)
/*!
 @method colorComponentFrom:start:length:
 @abstract 从十六进制的颜色字符串中提取某个颜色的浮点值
 @discussion none
 @param string      十六进制标示的颜色字符串，例如:RGB, ARGB, RRGGBB or AARRGGBB
 @param start       某个颜色通道的起始位置
 @param length      这个颜色通道占用的位数，有1或2
 @result CGFloat    这个颜色通道的浮点值
 */
+ (CGFloat)colorComponentFrom:(NSString*)string start:(NSUInteger)start length:(NSUInteger)length;

/*!
 @method colorWithHexString:
 @abstract 把十六进制的颜色字符串转换成UIColor对象
 @discussion 十六进制的颜色字符串格式如：#RGB, #ARGB, #RRGGBB or #AARRGGBB。
             如果格式不符合或产生异常，将返回白色UIColor对象
 @param hexString       十六进制表示的颜色字符串
 @result UIColor*       对应颜色的UIColor对象
 */
+ (UIColor*)colorWithHexString:(NSString*)hexString;

/*!
 @method colorWithHred:Hgreen:Hblue:Halpha:
 @abstract 根据rgba值创建UIColor对象
 @discussion iOS标准库中提供的rgba值创建UIColor对象方法中，rgba值的范围是0.0-1.0。
             而一般习惯使用0-255来表示，本方法就是使用这个范围来表示rgba值
 @param red         红色通道值，0-255
 @param green       绿色通道值，0-255
 @param blue        蓝色通道值，0-255
 @param alpha       透明通道值，0-255
 @result UIColor*   对应颜色的UIColor对象
 */
+ (UIColor*)colorWithHred:(CGFloat)red Hgreen:(CGFloat)green Hblue:(CGFloat)blue Halpha:(CGFloat)alpha;

/*!
 @method antiColor
 @abstract 获取当前颜色的反色，即补色
 @discussion 颜色和其反色混合的效果是白色，如果获取当前颜色有异常，将返回白色
 @result UIColor*   当前颜色的发色对象
 */
- (UIColor*)antiColor;
@end
