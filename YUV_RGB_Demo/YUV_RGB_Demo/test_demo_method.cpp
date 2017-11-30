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
