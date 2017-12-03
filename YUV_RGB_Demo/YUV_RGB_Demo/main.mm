//
//  main.m
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <mach-o/dyld.h>
#import "yuv_rgb_test_demo.hpp"

int test();

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
//        NSString *filePath = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
//        NSString *outputDir = @"/Users/meixiang/Desktop/Demo/demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv420_border([filePath UTF8String], [outputDir UTF8String], 256, 256, 20, 1);
        
//        char path[512];
//        unsigned size = 512;
//        _NSGetExecutablePath(path, &size);
//        path[size] = '\0';
//        printf("The path is: %s\n", path);
        
        //6
//        NSString *outputDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        yuv420_graybar(640, 360, 0, 255, 10, [outputDir UTF8String]);
        
        //7
//        NSString *inputPath1 = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_yuv420p.yuv";
//        NSString *inputPath2 = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_distort_256x256_yuv420p.yuv";
//        yuv420_psnr([inputPath1 UTF8String], [inputPath2 UTF8String], 256, 256, 1);
        
        //8
//        NSString *inputPath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/cie1931_500x500.rgb";
//        NSString *outputDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        rgb24_split([inputPath UTF8String], [outputDir UTF8String], 500, 500, 1);
//        printf("%0x\n", 'B');
//        printf("%0x\n", ('B'<<8));
//        printf("%0x\n", 'M');
//        printf("%0x\n", (('B'<<8) + 'M'));
        
        //9
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output/test_rgb24.rgb";
//        unsigned int test = 196664;
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_rgb24.rgb";
//        NSString *outputDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        rgb24_bmp([filePath UTF8String], [outputDir UTF8String], 256, 256);
//        rgb24_bmp([filePath UTF8String], [outputDir UTF8String], 736, 1024);
//        simplest_rgb24_to_bmp([filePath UTF8String],256,256,[outputDir UTF8String]);
//        test();
        
        //8
//        NSString *inputPath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/Sources/lena_256x256_rgb24.rgb";
//        NSString *outputDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output";
//        rgb24_to_yuv420p([inputPath UTF8String], [outputDir UTF8String], 256, 256, 1);
    }
    return 0;
}

int test() {
    typedef  struct  tagBITMAPFILEHEADER
    {
        unsigned short int   bfType;       //位图文件的类型，必须为BM
        unsigned int         bfSize;       //文件大小，以字节为单位
        unsigned short int   bfReserverd1; //位图文件保留字，必须为0
        unsigned short int   bfReserverd2; //位图文件保留字，必须为0
        unsigned int         bfbfOffBits;  //位图文件头到数据的偏移量，以字节为单位
    }BITMAPFILEHEADER;
    
    typedef  struct  tagBITMAPINFOHEADER
    {
        unsigned int        biSize;                         //该结构大小，字节为单位
        int                 biWidth;                        //图形宽度以象素为单位
        int                 biHeight;                       //图形高度以象素为单位
        unsigned short int  biPlanes;                       //目标设备的级别，必须为1
        unsigned short int  biBitcount;                     //颜色深度，每个象素所需要的位数
        unsigned int        biCompression;                  //位图的压缩类型
        unsigned int        biSizeImage;                    //位图的大小，以字节为单位
        int                 biXPelsPermeter;                //位图水平分辨率，每米像素数
        int                 biYPelsPermeter;                //位图垂直分辨率，每米像素数
        unsigned int        biClrUsed;                      //位图实际使用的颜色表中的颜色数
        unsigned int        biClrImportant;                 //位图显示过程中重要的颜色数
    }BITMAPINFOHEADER;
    

//    const char *filename = "/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output/output.bmp";
    const char *filename = "/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/test.bmp";
    FILE *fp = fopen(filename, "rb+");
    
    unsigned short int   bfType;       //位图文件的类型，必须为BM
    fread(&bfType, 1, 2, fp);
    
    unsigned int bfSize = 0;
    fread(&bfSize, 1, 4, fp);
    
    
    unsigned short int   bfReserverd1; //位图文件保留字，必须为0
    fread(&bfReserverd1, 1, 2, fp);
    unsigned short int   bfReserverd2; //位图文件保留字，必须为0
    fread(&bfReserverd2, 1, 2, fp);
    unsigned int         bfbfOffBits;//位图文件头到数据的偏移量，以字节为单位
    fread(&bfbfOffBits, 1, 4, fp);
    
    unsigned int biSize;                        //该结构大小，字节为单位
    fread(&biSize, 1, 4, fp);
    int  biWidth;                     //图形宽度以象素为单位
    fread(&biWidth, 1, 4, fp);
    int  biHeight;                     //图形高度以象素为单位
    fread(&biHeight, 1, 4, fp);
    unsigned short int  biPlanes;               //目标设备的级别，必须为1
    fread(&biPlanes, 1, 2, fp);
    unsigned short int  biBitcount;             //颜色深度，每个象素所需要的位数
    fread(&biBitcount, 1, 2, fp);
    unsigned int  biCompression;        //位图的压缩类型
    fread(&biCompression, 1, 4, fp);
    unsigned int  biSizeImage;              //位图的大小，以字节为单位
    fread(&biSizeImage, 1, 4, fp);
    int  biXPelsPermeter;       //位图水平分辨率，每米像素数
    fread(&biXPelsPermeter, 1, 4, fp);
    int  biYPelsPermeter;       //位图垂直分辨率，每米像素数
    fread(&biYPelsPermeter, 1, 4, fp);
    unsigned int  biClrUsed;            //位图实际使用的颜色表中的颜色数
    fread(&biClrUsed, 1, 4, fp);
    unsigned int  biClrImportant;       //位图显示过程中重要的颜色数
    fread(&biClrImportant, 1, 4, fp);
    
    unsigned char *rgb_buffer = (unsigned char *)malloc(3*biWidth*biHeight);
    fread(rgb_buffer, 1, 3*biWidth*biHeight, fp);
    
    for (int i=biHeight-1; i>=0; i--) {
        for (int j=0; j<biWidth; j++) {
            unsigned char temp = rgb_buffer[(i*biWidth+j)*3];
            rgb_buffer[(i*biWidth+j)*3] = rgb_buffer[(i*biWidth+j)*3+2];
            rgb_buffer[(i*biWidth+j)*3+2] = temp;
        }
    }
    
    const char *ouput = "/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/YUV_RGB_Demo/YUV_RGB_Demo/output/test_rgb24.rgb";
    FILE *fp_out = fopen(ouput, "wb+");
    fwrite(rgb_buffer, 3*biWidth*biHeight, 1, fp_out);
    
    free(rgb_buffer);
    fclose(fp_out);
    fclose(fp);
    return 0;
}

























