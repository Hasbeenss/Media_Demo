//
//  test_demo_method.hpp
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#ifndef test_demo_method_hpp
#define test_demo_method_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yuv420_split(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv444_split(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_gray(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_half(const char *input_path, const char *output_dir, int w, int h, int num);

int yuv420_border(const char *input_path, const char *output_dir, int w, int h, int border, int num);
#endif /* test_demo_method_hpp */
