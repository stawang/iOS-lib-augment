//
//  IOS_UTIL_REF.h
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

#ifndef IOS_UTIL_REF_h
#define IOS_UTIL_REF_h

//G－C－D
/*后台线程*/
#define BACK_BLOCK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)

/*主线程*/
#define MAIN_BLOCK(block) dispatch_async(dispatch_get_main_queue(),block)

/*用户默认设置*/
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

/*度数转弧度*/
#define DEGREES_TO_RADIAN_FLOAT(x) (M_PI * (x) / 180.0f)

/*弧度转度数*/
#define RADIAN_TO_DEGREES_FLOAT(radian) ((radian*180.0f)/(M_PI))

/*构造颜色-rgb*/
#define RGBCOLOR_UICOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

/*构造颜色-rgba*/
#define RGBACOLOR_UICOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

/*自定义断言*/
#define CAssert(condition, ...)                                       \
    if (!(condition)) {                                                 \
        [[NSAssertionHandler currentHandler]                            \
            handleFailureInFunction:                                    \
            [NSString stringWithUTF8String:__PRETTY_FUNCTION__]         \
            file:[NSString stringWithUTF8String:__FILE__]               \
            lineNumber:__LINE__                                         \
            description:__VA_ARGS__];                                   \
        break;                                                          \
    } else do {} while (0)

/*加载图片，性能高，不会缓存照片*/
#define LOADIMAGE_UIIMAGE(file,ext) [UIImage imageWithContentsOfFile:           \
            [[NSBundle mainBundle] pathForResource:file ofType:ext]]

/*通过视图tag获取子视图*/
#define VIEWWITHTAG_UIVIEW(_OBJECT, _TAG)  [_OBJECT viewWithTag : _TAG]

/**构造颜色
 * 使用方式:UICOLORFROMRGB_UICOLOR(0xfec0c0)
 */
#define UICOLORFROMRGB_UICOLOR(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#endif
