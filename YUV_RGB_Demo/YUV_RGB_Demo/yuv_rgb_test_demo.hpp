//
//  yuv_rgb_test_demo.hpp
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#ifndef yuv_rgb_test_demo_hpp
#define yuv_rgb_test_demo_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int yuv420_split(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv444_split(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_gray(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_half(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_border(const char *input_path, const char *output_dir, int w, int h, int border, int num);

int yuv420_graybar(int width, int height, int ymin, int ymax, int barnum, const char *url_out);

int yuv420_psnr(const char *input_path1, const char *input_path2, int w, int h, int num);

int rgb24_split(const char *input_path, const char *output_dir, int w, int h, int num);

int rgb24_bmp(const char *input_path, const char *output_dir, int w, int h);
//int simplest_rgb24_to_bmp(const char *rgb24path,int width,int height,const char *bmppath);

int rgb24_to_yuv420p(const char *input_path, const char *output_dir, int w, int h, int num);

#endif /* yuv_rgb_test_demo_hpp */
