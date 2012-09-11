//
//  UIColor+Augument.m
//  ColorSystem
//
//  Created by 309 on 12-9-11.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "UIColor+Augment.h"

@implementation UIColor (Augment)
+ (CGFloat)colorComponentFrom:(NSString *)string start:(NSUInteger)start length:(NSUInteger)length {
    if (nil == string || string.length < 1) {
        return 0.0f;
    }
    
    NSString* subStr = [string substringWithRange:NSMakeRange(start, length)];
    NSString* fullHex = length == 2 ? subStr : [NSString stringWithFormat:@"%@%@", subStr, subStr];
    
    unsigned hexCompnent;
    
    [[NSScanner scannerWithString:fullHex] scanHexInt:&hexCompnent];
    
    return hexCompnent / 255.0;
}

+ (UIColor*)colorWithHexString:(NSString *)hexString {
    CGFloat alpha, red, blue, green;
    NSString* regxStr = @"^#[A-Za-z0-9]{3,8}$";
    NSPredicate* pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regxStr];
    BOOL isColorHexStr = [pred evaluateWithObject:hexString];
    if (!isColorHexStr) {
        return [UIColor whiteColor];
    }
    
    
    NSString* colorStr = [[hexString stringByReplacingOccurrencesOfString:@"#" withString:@""] uppercaseString];
    switch ([colorStr length]) {
        case 3://#RGB
            alpha = 1.0f;
            red = [self colorComponentFrom:colorStr start:0 length:1];
            green = [self colorComponentFrom:colorStr start:1 length:1];
            blue = [self colorComponentFrom:colorStr start:2 length:1];
            break;
        case 4://#ARGB
            alpha = [self colorComponentFrom:colorStr start:0 length:1];
            red = [self colorComponentFrom:colorStr start:1 length:1];
            green = [self colorComponentFrom:colorStr start:2 length:1];
            blue = [self colorComponentFrom:colorStr start:3 length:1];
            break;
        case 6://#RRGGBB
            alpha = 1.0f;
            red = [self colorComponentFrom:colorStr start:0 length:2];
            green = [self colorComponentFrom:colorStr start:2 length:2];
            blue = [self colorComponentFrom:colorStr start:4 length:2];
            break;
        case 8://#AARRGGBB
            alpha = [self colorComponentFrom:colorStr start:0 length:2];
            red = [self colorComponentFrom:colorStr start:2 length:2];
            green = [self colorComponentFrom:colorStr start:4 length:2];
            blue = [self colorComponentFrom:colorStr start:6 length:2];
            break;
            
        default:
            //[NSException raise:@"Invalid color value" format:@"Color value %@ is invalid, It should be a hex value of the form #RGB, #ARGB, #RRGGBB,or #AARRGGBB", hexString];
            return [UIColor whiteColor];
    }
    
    return [UIColor colorWithRed:red green:green blue:blue alpha:alpha];
}

+ (UIColor*)colorWithHred:(CGFloat)red Hgreen:(CGFloat)green Hblue:(CGFloat)blue Halpha:(CGFloat)alpha {
    return [UIColor colorWithRed:red / 255.0f green:green / 255.0f blue:blue / 255.0f alpha:alpha / 255.0f];
}

- (UIColor*)antiColor {
    CGFloat red, green, blue, alpha;
    BOOL isCoverted;
    
    red = green = blue = alpha = 0.0f;
    isCoverted = [self getRed:&red green:&green blue:&blue alpha:&alpha];
    //能正确获取当前颜色值
    if (isCoverted) {
        return [UIColor colorWithRed:(1.0f-red) green:(1.0f-green) blue:(1.0f-blue) alpha:alpha];
    } else {
        return [UIColor whiteColor];
    }
}
@end
