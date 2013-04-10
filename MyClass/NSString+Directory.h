//
//  NSString+Directory.h
//
//  Created by 309 on 13-4-10.
//  Copyright (c) 2013年 wgs.
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

#import <Foundation/Foundation.h>

@interface NSString (Directory)
/*!
 @method tempDirectory:
 @abstract 临时目录
 @discussion 使用NSTemporaryDirectory()方法
 @result NSString*  绝对路径
 */
+ (NSString*)tempDirectory;

/*!
 @method cacheDirectory
 @abstract 缓存目录
 @discussion none
 @result NSString* 绝对路径
 */
+ (NSString*)cacheDirectory;

/*!
 @method documentDirectory
 @abstract document目录
 @discussion none
 @result NSString* 绝对路径
 */
+ (NSString*)documentDirectory;
@end
