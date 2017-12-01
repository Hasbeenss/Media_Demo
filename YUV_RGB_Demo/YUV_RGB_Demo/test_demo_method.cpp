//
//  test_demo_method.cpp
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#include "test_demo_method.hpp"

char *output_filepath_generate(const char *output_dir, const char *file_name) {
    char *result = (char *)malloc(strlen(output_dir) + strlen(file_name)+1);
    strcpy(result, output_dir);
    strcat(result, file_name);
    return result;
}

/**
 * Split Y, U, V planes in YUV420P file.
 * @param input_path  Location of Input YUV file.
 * @param w    Width of Input YUV file.
 * @param h    Height of Input YUV file.
 * @param num  Number of frames to process.
 *
 */
int yuv420_split(const char *input_path, const char *output_dir, int w, int h, int num) {
    
    FILE *fp = fopen(input_path, "rb+");
    FILE *fp_y = fopen(output_filepath_generate(output_dir, "/output_420_y.y"), "wb+");
    FILE *fp_u = fopen(output_filepath_generate(output_dir, "/output_420_u.y"), "wb+");
    FILE *fp_v = fopen(output_filepath_generate(output_dir, "/output_420_v.y"), "wb+");
    
    unsigned char *pic = (unsigned char *)malloc(w*h*3/2);
    
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp);
        
        fwrite(pic, 1, w*h, fp_y);
        fwrite(pic+w*h, 1, w*h/4, fp_u);
        fwrite(pic+w*h*5/4, 1, w*h/4,  fp_v);
    }
    
    free(pic);
    fclose(fp);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
    return 0;
}

/**
 * Split Y, U, V planes in YUV444P file.
 * @param input_path  Location of YUV file.
 * @param w    Width of Input YUV file.
 * @param h    Height of Input YUV file.
 * @param num  Number of frames to process.
 *
 */
int yuv444_split(const char *input_path, const char *output_dir, int w, int h, int num) {
    
    FILE *fp = fopen(input_path, "rb+");
    FILE *fp_y = fopen(output_filepath_generate(output_dir, "/output_444_y.y"), "wb+");
    FILE *fp_u = fopen(output_filepath_generate(output_dir, "/output_444_u.y"), "wb+");
    FILE *fp_v = fopen(output_filepath_generate(output_dir, "/output_444_v.y"), "wb+");

    unsigned char *pic = (unsigned char *)malloc(w*h*3);
    
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3, fp);
        
        fwrite(pic, 1, w*h, fp_y);
        fwrite(pic+w*h, 1, w*h, fp_u);
        fwrite(pic+w*h*2, 1, w*h, fp_v);
    }
    
    free(pic);
    fclose(fp);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
    return 0;
}

/**
 * Convert YUV420P file to gray picture
 * @param input_path     Location of Input YUV file.
 * @param w       Width of Input YUV file.
 * @param h       Height of Input YUV file.
 * @param num     Number of frames to process.
 */
int yuv420_gray(const char *input_path, const char *output_dir, int w, int h, int num) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_output = fopen(output_filepath_generate(output_dir, "/output_420_gray.yuv"), "wb+");
    
    unsigned char *pic = (unsigned char *)malloc(w*h*3/2);
    
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp_input);
        
        memset(pic+w*h, 128, w*h/2);
        fwrite(pic, 1, w*h*3/2, fp_output);
    }
    
    free(pic);
    fclose(fp_input);
    fclose(fp_output);
    return 0;
}

/**
 * Halve Y value of YUV420P file
 * @param input_path     Location of Input YUV file.
 * @param w       Width of Input YUV file.
 * @param h       Height of Input YUV file.
 * @param num     Number of frames to process.
 */
int yuv420_half(const char *input_path, const char *output_dir, int w, int h, int num) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_output = fopen(output_filepath_generate(output_dir, "/output_420_half.yuv"), "wb+");
    
    unsigned char *pic = (unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp_input);
        
        for (int j=0; j<w*h; j++) {
            unsigned char temp = pic[j]/2;
            pic[j] = temp;
        }
        fwrite(pic, 1, w*h*3/2, fp_output);
    }
    
    free(pic);
    fclose(fp_input);
    fclose(fp_output);
    return 0;
}

/**
 * Add border for YUV420P file
 * @param input_path     Location of Input YUV file.
 * @param w       Width of Input YUV file.
 * @param h       Height of Input YUV file.
 * @param border  Width of Border.
 * @param num     Number of frames to process.
 */
int yuv420_border(const char *input_path, const char *output_dir, int w, int h, int border, int num) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_output = fopen(output_filepath_generate(output_dir, "/output_420_border.yuv"), "wb+");
    
    unsigned char *pic = (unsigned char *)malloc(w*h*3/2);
    
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp_input);
        
        for (int j=0; j<h; j++) {
            for (int k=0; k<w; k++) {
                if (j<border || j>h-border || k<border || k>w-border) {
                    pic[j*w+k] = 255;
                }
            }
        }
        fwrite(pic, 1, w*h*3/2, fp_output);
    }
    
    free(pic);
    fclose(fp_input);
    fclose(fp_output);
    
    return 0;
}


