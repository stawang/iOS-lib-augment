//
//  IOS_SYSTEM_REF.h
//
// Created by wgs on 13-4-7.
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

#ifndef IOS_SYSTEM_REF_h
#define IOS_SYSTEM_REF_h

/*系统版本-数字*/
#define IOS_VERSION_FLOAT [[[UIDevice currentDevice] systemVersion] floatValue]

/*系统版本-字符串*/
#define IOS_VERSION_STR ([[UIDevice currentDevice] systemVersion])

/*用户当前设置的使用语言*/
#define USER_PREFERRED_LANGUAGES_STR ([[NSLocale preferredLanguages] objectAtIndex:0])

/*判断是否是retina屏*/
#define IS_RETINA_BOOL ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (640.0f == [[UIScreen mainScreen] currentMode].size.width) : NO)

/*判断是否是iphone5手机*/
#define IS_IPHONE5_BOOL ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

/*判断是否是iPad*/
#define IS_IPAD_BOOL (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#endif
