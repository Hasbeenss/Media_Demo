//
//  main.m
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "test_demo_method.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"Hello, World!");
        //1
//        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
//        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv420_split([filePath UTF8String], [outputDir UTF8String], 256, 256, 1);
        
        //2
//        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv444p.yuv";
//        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv444_split([filePath UTF8String], [outputDir UTF8String], 256, 256, 1);
        
        //3
//        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
//        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv420_gray([filePath UTF8String], [outputDir UTF8String], 256, 256, 1);
        
        //4
//        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
//        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv420_half([filePath UTF8String], [outputDir UTF8String], 256, 256, 1);
        
        //5
        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
        yuv420_border([filePath UTF8String], [outputDir UTF8String], 256, 256, 20, 1);
    }
    return 0;
}
