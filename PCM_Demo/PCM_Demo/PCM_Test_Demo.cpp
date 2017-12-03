//
//  PCM_Test_Demo.cpp
//  PCM_Demo
//
//  Created by Hasbeenss on 02/12/2017.
//  Copyright © 2017 Hasbeenss. All rights reserved.
//

#include "PCM_Test_Demo.hpp"

char *output_filepath_generate(const char *output_dir, const char *file_name) {
    char *result = (char *)malloc(strlen(output_dir) + strlen(file_name)+1);
    strcpy(result, output_dir);
    strcat(result, file_name);
    return result;
}

int pcm_split(const char *input_path, const char *output_dir) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput1 = fopen(output_filepath_generate(output_dir, "/output_pcm_l.pcm"), "wb+");
    FILE *fp_ouput2 = fopen(output_filepath_generate(output_dir, "/output_pcm_r.pcm"), "wb+");
    
    unsigned char *sample = (unsigned char *)malloc(4);
    
    while (!feof(fp_input)) {
        fread(sample, 1, 4, fp_input);
        fwrite(sample, 1, 2, fp_ouput1);
        fwrite(sample+2, 1, 2, fp_ouput2);
    }
    
    free(sample);
    fclose(fp_input);
    fclose(fp_ouput1);
    fclose(fp_ouput2);
    
    return 0;
}

int pcm_half_volumeleft(const char *input_path, const char *output_dir) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput = fopen(output_filepath_generate(output_dir, "/output_pcm_half_volueleft.pcm"), "wb+");

    unsigned char *sample = (unsigned char *)malloc(4);
    
    int cnt = 0;
    
    while (!feof(fp_input)) {
        fread(sample, 1, 4, fp_input);
        short *sample_num = (short *)sample;
        *sample_num = *sample_num/2;
        
        fwrite(sample, 1, 2, fp_ouput);
        fwrite(sample+2, 1, 2, fp_ouput);

        cnt++;
    }
    
    printf("Sample Cnt:%d\n",cnt);

    free(sample);
    fclose(fp_input);
    fclose(fp_ouput);
    
    return 0;
}

int pcm_double_speed(const char *input_path, const char *output_dir) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput = fopen(output_filepath_generate(output_dir, "/output_pcm_double_speed.pcm"), "wb+");
    
    unsigned char *sample = (unsigned char *)malloc(4);
    
    int cnt = 0;
    
    while (!feof(fp_input)) {
        fread(sample, 1, 4, fp_input);
        
        if (cnt%2 != 0) {
            fwrite(sample, 1, 2, fp_ouput);
            fwrite(sample+2, 1, 2, fp_ouput);
        }
    
        cnt++;
    }
    
    printf("Sample Cnt:%d\n",cnt);
    
    free(sample);
    fclose(fp_input);
    fclose(fp_ouput);
    
    return 0;
}

int pcm16le_to_pcm8(const char *input_path, const char *output_dir) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput = fopen(output_filepath_generate(output_dir, "/output_pcm16le_to_pcm8.pcm"), "wb+");
    
    unsigned char *sample = (unsigned char *)malloc(4);
    
    int cnt = 0;
    
    while (!feof(fp_input)) {
        fread(sample, 1, 4, fp_input);
        
        short *sample_16 = NULL;
        char sample_8 = 0;
        unsigned char sample_8_unsign = 0;
        
        //L
        sample_16 = (short *)sample;
        sample_8 = (*sample_16)>>8;
        sample_8_unsign = sample_8 + 128;
        fwrite(&sample_8_unsign, 1, 1, fp_ouput);
        
        //R
        sample_16 = (short *)(sample+2);
        sample_8 = (*sample_16)>>8;
        sample_8_unsign = sample_8 + 128;
        fwrite(&sample_8_unsign, 1, 1, fp_ouput);
        
        cnt++;
    }
    
    printf("Sample Cnt:%d\n",cnt);
    
    free(sample);
    fclose(fp_input);
    fclose(fp_ouput);
    
    return 0;
}

int pcm16le_single(const char *input_path, const char *output_dir, int start_num,int dur_num) {
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput_pcm = fopen(output_filepath_generate(output_dir, "/output_pcm16le_single.pcm"), "wb+");
    FILE *fp_ouput_txt = fopen(output_filepath_generate(output_dir, "/output_pcm16le_txt.txt"), "wb+");

    unsigned char *sample = (unsigned char *)malloc(2);
    
    int cnt = 0;
    
//    if (fseek(fp_input, start_num*2, SEEK_SET) != 0) {
//        return -1;
//    }
//
//    while (cnt < dur_num) {
//        fread(sample, 1, 2, fp_input);
//        fwrite(sample, 1, 2, fp_ouput_pcm);
//
//        short samplenum=sample[1];
//        samplenum=samplenum*256;
//        samplenum=samplenum+sample[0];
//
//        fprintf(fp_ouput_txt,"%6d,",samplenum);
//        if (cnt%10==0) fprintf(fp_ouput_txt,"\n");
//
//        cnt ++;
//    }
    
    while(!feof(fp_input)){
        fread(sample,1,2,fp_input);
        if(cnt>start_num&&cnt<=(start_num+dur_num)){
            fwrite(sample,1,2,fp_ouput_pcm);

            short samplenum=sample[1];
            samplenum=samplenum*256;
            samplenum=samplenum+sample[0];

            fprintf(fp_ouput_txt,"%6d,",samplenum);
            if(cnt%10==0)
                fprintf(fp_ouput_txt,"\n",samplenum);
        }
        cnt++;
    }
    
    printf("Sample Cnt:%d\n",cnt);
    
    free(sample);
    fclose(fp_input);
    fclose(fp_ouput_pcm);
    fclose(fp_ouput_txt);

    return 0;
}

#pragma pack(2)
int pcm16_to_wav(const char *input_path, const char *output_dir, int channels, int sample_rate) {
    typedef struct WAVE_HEADER{
        char             fccID[4];      //RIFF标志
        unsigned int     dwSize;        //文件长度
        char             fccType[4];    //WAVE标志
    }WAVE_HEADER;
    
    typedef struct WAVE_FMT{
        char            fccID[4];           //fmt标志，最后一位为空
        unsigned int    dwSize;             //WAVE_FMT大小
        unsigned short  wFormatTag;         //格式类别，1表示为PCM形式的声音数据
        unsigned short  wChannels;          //通道数，单声道为1，双声道为2
        unsigned int    dwSamplesPerSec;    //采样频率（每秒样本数）44100;
        unsigned int    dwAvgBytesPerSec;   // 每秒数据量；其值为通道数×每秒数据位数×每样本的数据位数／8。播放软件利用此值可以估计缓冲区的大小。
        unsigned short  wBlockAlign;        //数据块的调整数（按字节算的），其值为通道数×每样本的数据位值／8。播放软件需要一次处理多个该值大小的字节数据，以便将其值用于缓冲区的调整。
        unsigned short  uiBitsPerSample;    //每样本的数据位数，表示每个声道中各个样本的数据位数。如果有多个声道，对每个声道而言，样本大小都一样。
    }WAVE_FMT;
    
    typedef struct WAVE_DATA{
        char            fccID[4];   //"data"标记
        unsigned int    dwSize;     //语音数据大小
    }WAVE_DATA;
    
    if(channels==0||sample_rate==0){
        channels = 2;
        sample_rate = 44100;
    }
    
    int bits = 16;
    unsigned   short   m_pcmData;
    
    FILE *fp_input = fopen(input_path, "rb+");
    FILE *fp_ouput = fopen(output_filepath_generate(output_dir, "/output_pcm16le_to_wav.wav"), "wb+");
    
    if(fp_input == NULL) {
        printf("open pcm file error\n");
        return -1;
    }
    if(fp_ouput == NULL) {
        printf("create wav file error\n");
        return -1;
    }
    
    WAVE_HEADER wav_header = {0};
    memcpy(wav_header.fccID, "RIFF", strlen("RIFF"));
    memcpy(wav_header.fccType, "WAVE", strlen("WAVE"));

    
    WAVE_FMT wav_fmt = {0};
    wav_fmt.dwSamplesPerSec = sample_rate;
    wav_fmt.dwAvgBytesPerSec = wav_fmt.dwSamplesPerSec*sizeof(m_pcmData);
    wav_fmt.uiBitsPerSample = bits;
    memcpy(wav_fmt.fccID,"fmt ",strlen("fmt "));
    wav_fmt.dwSize=16;
    wav_fmt.wBlockAlign=2;
    wav_fmt.wChannels=channels;
    wav_fmt.wFormatTag=1;
    
    fseek(fp_ouput,sizeof(WAVE_HEADER),1);
    fwrite(&wav_fmt,sizeof(WAVE_FMT),1,fp_ouput);

    WAVE_DATA wav_data = {0};
    memcpy(wav_data.fccID, "data", strlen("data"));
    wav_data.dwSize = 0;
    
    fseek(fp_ouput,sizeof(WAVE_DATA),SEEK_CUR);

    fread(&m_pcmData,sizeof(unsigned short),1,fp_input);
    while(!feof(fp_input)){
        wav_data.dwSize+=2;
        fwrite(&m_pcmData,sizeof(unsigned short),1,fp_ouput);
        fread(&m_pcmData,sizeof(unsigned short),1,fp_input);
    }
    
    
//    while (!feof(fp_input)) {
//        fread(&m_pcmData,sizeof(unsigned short),1,fp_input);
//        wav_data.dwSize+=2;
//        fwrite(&m_pcmData,sizeof(unsigned short),1,fp_ouput);
//    }
    
    unsigned short total_size = sizeof(WAVE_HEADER) + sizeof(WAVE_FMT) + sizeof(WAVE_DATA);
    wav_header.dwSize = total_size + wav_data.dwSize;
    
    rewind(fp_ouput);
    fwrite(&wav_header, sizeof(WAVE_HEADER), 1, fp_ouput);
    fseek(fp_ouput, sizeof(WAVE_FMT), SEEK_CUR);
    fwrite(&wav_data, sizeof(WAVE_DATA), 1, fp_ouput);
    
    fclose(fp_input);
    fclose(fp_ouput);
    return 0;
}





