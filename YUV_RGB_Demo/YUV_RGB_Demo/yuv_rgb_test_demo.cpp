//
//  yuv_rgb_test_demo.cpp
//  YUV_RGB_Demo
//
//  Created by Hasbeenss on 2017/11/30.
//  Copyright © 2017年 Hasbeenss. All rights reserved.
//

#include "yuv_rgb_test_demo.hpp"

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

/**
 * Generate YUV420P gray scale bar.
 * @param width    Width of Output YUV file.
 * @param height   Height of Output YUV file.
 * @param ymin     Max value of Y
 * @param ymax     Min value of Y
 * @param barnum   Number of bars
 * @param url_out  Location of Output YUV file.
 */
int yuv420_graybar(int width, int height, int ymin, int ymax, int barnum, const char *url_out) {
    FILE *fp_output = NULL;
    unsigned char tmp_y;
    unsigned char inc_y = (float)(ymax - ymin)/(barnum - 1);
    int boreder_width = width/barnum;
    int uv_width = width/2;
    int uv_height = height/2;
    int i=0, j=0, t=0;
    
    
    unsigned char *y_data = (unsigned char *)malloc(width*height);
    unsigned char *u_data = (unsigned char *)malloc(uv_width*uv_height);
    unsigned char *v_data = (unsigned char *)malloc(uv_width*uv_height);

    
    if ((fp_output = fopen(output_filepath_generate(url_out, "/output_420_graybar.yuv"), "wb+")) == NULL) {
        printf("Error: Cannot create file!");
        return -1;
    }
    
    printf("Y, U, V value from picture's left to right:\n");

    for (t=0; t<barnum; t++) {
        tmp_y = (char)(inc_y * t) + ymin;
        printf("%3d, 128, 128\n", tmp_y);
    }
    
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            y_data[i*width+j] = (char)((j/boreder_width)*inc_y) + ymin;
        }
    }
    
    for (i=0; i<uv_height; i++) {
        for (j=0; j<uv_width; j++) {
            u_data[i*uv_width+j] = 128;
            v_data[i*uv_width+j] = 128;
        }
    }
    
    fwrite(y_data, 1, width*height, fp_output);
    fwrite(u_data, 1, uv_width*uv_height, fp_output);
    fwrite(v_data, 1, uv_width*uv_height, fp_output);
    
    fclose(fp_output);
    free(y_data);
    free(u_data);
    free(v_data);
    
    return 0;
}

int yuv420_psnr(const char *input_path1, const char *input_path2, int w, int h, int num) {
    
    FILE *fp_1 = fopen(input_path1, "rb+");
    FILE *fp_2 = fopen(input_path2, "rb+");
    
    unsigned char *pic1 = (unsigned char *)malloc(w*h);
    unsigned char *pic2 = (unsigned char *)malloc(w*h);
    
    for (int i=0; i<num; i++) {
        
        fread(pic1, 1, w*h, fp_1);
        fread(pic2, 1, w*h, fp_2);
        
        double mse_sum = 0;
        for (int j=0; j<w*h; j++) {
            mse_sum += (double)pow((pic1[j] - pic2[j]), 2);
        }
        
        double mse = mse_sum/(w*h);
        
        double psnr = 10*log10(255.0*255.0/mse);
        
        printf("%5.3f\n", psnr);
        
        fseek(fp_1, w*h/2, SEEK_CUR);
        fseek(fp_2, w*h/2, SEEK_CUR);
    }

    free(pic2);
    free(pic1);
    fclose(fp_1);
    fclose(fp_2);
    return 0;
}

int rgb24_split(const char *input_path, const char *output_dir, int w, int h, int num) {
    
    FILE *fp = fopen(input_path, "rb+");
    FILE *fp_r = fopen(output_filepath_generate(output_dir, "/output_r.y"), "wb+");
    FILE *fp_g = fopen(output_filepath_generate(output_dir, "/output_g.y"), "wb+");
    FILE *fp_b = fopen(output_filepath_generate(output_dir, "/output_b.y"), "wb+");
    
    unsigned char *pic = (unsigned char *)malloc(w*h*3);
    
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3, fp);
        for (int j=0; j<w*h*3; j+=3) {
            fwrite(pic+j, 1, 1, fp_r);
            fwrite(pic+j+1, 1, 1, fp_g);
            fwrite(pic+j+2, 1, 1, fp_b);
        }
    }
    
    free(pic);
    fclose(fp);
    fclose(fp_r);
    fclose(fp_g);
    fclose(fp_b);
    return 0;
}
#pragma pack(1)
int rgb24_bmp(const char *input_path, const char *output_dir, int w, int h) {
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
    
    BITMAPFILEHEADER bmp_header = {0};
    unsigned int header_size = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmp_header.bfType = (('M'<<8)+'B');
    bmp_header.bfSize = header_size + w*h*3;
    bmp_header.bfReserverd1 = 0;
    bmp_header.bfReserverd2 = 0;
    bmp_header.bfbfOffBits = header_size;
    
    BITMAPINFOHEADER bmp_info = {0};
    bmp_info.biSize = sizeof(BITMAPINFOHEADER);
    bmp_info.biWidth = w;
    bmp_info.biHeight = -h;
    bmp_info.biPlanes = 1;
    bmp_info.biBitcount = 24;
    bmp_info.biSizeImage = w*h*3;
    
    FILE *fp_output = fopen(output_filepath_generate(output_dir, "/output.bmp"), "wb");
    fwrite(&bmp_header, sizeof(bmp_header), 1, fp_output);
    fwrite(&bmp_info, sizeof(bmp_info), 1, fp_output);

    FILE *fp_input = fopen(input_path, "rb");
    unsigned char *rgb_buffer = (unsigned char *)malloc(3*w*h);
    
    fread(rgb_buffer, 1, 3*w*h, fp_input);
    
//    for(int j =0;j<h;j++){
//        for(int i=0;i<w;i++){
//            char temp=rgb_buffer[(j*w+i)*3+2];
//            rgb_buffer[(j*w+i)*3+2]=rgb_buffer[(j*h+i)*3+0];
//            rgb_buffer[(j*w+i)*3+0]=temp;
//        }
//    }
    
    for (int i=0; i<w*h*3; i+=3) {
        unsigned char tmp = rgb_buffer[i];
        rgb_buffer[i] = rgb_buffer[i+2];
        rgb_buffer[i+2] = tmp;
    }
    
    fwrite(rgb_buffer, 3*w*h, 1, fp_output);
    
    free(rgb_buffer);
    fclose(fp_input);
    fclose(fp_output);
    
    return 0;
}

//int simplest_rgb24_to_bmp(const char *rgb24path,int width,int height,const char *bmppath){
//    typedef struct
//    {
//        long imageSize;
//        long blank;
//        long startPosition;
//    }BmpHead;
//    
//    typedef struct
//    {
//        long  Length;
//        long  width;
//        long  height;
//        unsigned short  colorPlane;
//        unsigned short  bitColor;
//        long  zipFormat;
//        long  realSize;
//        long  xPels;
//        long  yPels;
//        long  colorUse;
//        long  colorImportant;
//    }InfoHead;
//    
//    int i=0,j=0;
//    BmpHead m_BMPHeader={0};
//    InfoHead  m_BMPInfoHeader={0};
//    char bfType[2]={'B','M'};
//    int header_size=sizeof(bfType)+sizeof(BmpHead)+sizeof(InfoHead);
//    unsigned char *rgb24_buffer=NULL;
//    FILE *fp_rgb24=NULL,*fp_bmp=NULL;
//    
//    if((fp_rgb24=fopen(rgb24path,"rb"))==NULL){
//        printf("Error: Cannot open input RGB24 file.\n");
//        return -1;
//    }
//    if((fp_bmp=fopen(bmppath,"wb"))==NULL){
//        printf("Error: Cannot open output BMP file.\n");
//        return -1;
//    }
//    
//    rgb24_buffer=(unsigned char *)malloc(width*height*3);
//    fread(rgb24_buffer,1,width*height*3,fp_rgb24);
//    
//    m_BMPHeader.imageSize=3*width*height+header_size;
//    m_BMPHeader.startPosition=header_size;
//    
//    m_BMPInfoHeader.Length=sizeof(InfoHead);
//    m_BMPInfoHeader.width=width;
//    //BMP storage pixel data in opposite direction of Y-axis (from bottom to top).
//    m_BMPInfoHeader.height=-height;
//    m_BMPInfoHeader.colorPlane=1;
//    m_BMPInfoHeader.bitColor=24;
//    m_BMPInfoHeader.realSize=3*width*height;
//    
//    fwrite(bfType,1,sizeof(bfType),fp_bmp);
//    fwrite(&m_BMPHeader,1,sizeof(m_BMPHeader),fp_bmp);
//    fwrite(&m_BMPInfoHeader,1,sizeof(m_BMPInfoHeader),fp_bmp);
//    
//    //BMP save R1|G1|B1,R2|G2|B2 as B1|G1|R1,B2|G2|R2
//    //It saves pixel data in Little Endian
//    //So we change 'R' and 'B'
//    for(j =0;j<height;j++){
//        for(i=0;i<width;i++){
//            char temp=rgb24_buffer[(j*width+i)*3+2];
//            rgb24_buffer[(j*width+i)*3+2]=rgb24_buffer[(j*width+i)*3+0];
//            rgb24_buffer[(j*width+i)*3+0]=temp;
//        }
//    }
//    fwrite(rgb24_buffer,3*width*height,1,fp_bmp);
//    fclose(fp_rgb24);
//    fclose(fp_bmp);
//    free(rgb24_buffer);
//    printf("Finish generate %s!\n",bmppath);
//    return 0;
//    return 0;
//}

unsigned char clip_value(unsigned char x,unsigned char min_val,unsigned char  max_val){
    if(x>max_val){
        return max_val;
    }else if(x<min_val){
        return min_val;
    }else{
        return x;
    }
}

//RGB to YUV420
bool RGB24_TO_YUV420(unsigned char *RgbBuf,int w,int h,unsigned char *yuvBuf) {
    unsigned char *ptrY = yuvBuf;
    unsigned char *ptrU = yuvBuf + w*h;
    unsigned char *ptrV = yuvBuf + w*h*5/4;
    
    unsigned char r, g, b, y, u, v;
    
    int index;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            index = (i*w+j)*3;
            r = RgbBuf[index++];
            g = RgbBuf[index++];
            b = RgbBuf[index++];
            
            y = (unsigned char)( ( 66 * r + 129 * g +  25 * b + 128) >> 8) + 16  ;
            u = (unsigned char)( ( -38 * r -  74 * g + 112 * b + 128) >> 8) + 128 ;
            v = (unsigned char)( ( 112 * r -  94 * g -  18 * b + 128) >> 8) + 128 ;
            *(ptrY++) = clip_value(y,0,255);
            if (j%2==0&&i%2 ==0){
                *(ptrU++) =clip_value(u,0,255);
            }
            else{
                if (i%2==0){
                    *(ptrV++) =clip_value(v,0,255);
                }
            }
        }
    }

    return true;
}

int rgb24_to_yuv420p(const char *input_path, const char *output_dir, int w, int h, int num) {
    FILE *fp_input = fopen(input_path,"rb+");
    FILE *fp_output = fopen(output_filepath_generate(output_dir, "/output_rgb24_to_yuv.yuv"),"wb+");
    
    unsigned char *pic_rgb24=(unsigned char *)malloc(w*h*3);
    unsigned char *pic_yuv420=(unsigned char *)malloc(w*h*3/2);
    
    for(int i=0;i<num;i++){
        fread(pic_rgb24,1,w*h*3,fp_input);
        RGB24_TO_YUV420(pic_rgb24,w,h,pic_yuv420);
        fwrite(pic_yuv420,1,w*h*3/2,fp_output);
    }
    
    free(pic_rgb24);
    free(pic_yuv420);
    fclose(fp_input);
    fclose(fp_output);
    
    return 0;
}























