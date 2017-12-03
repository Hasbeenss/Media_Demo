//
//  main.m
//  PCM_Demo
//
//  Created by Hasbeenss on 02/12/2017.
//  Copyright © 2017 Hasbeenss. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PCM_Test_Demo.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //1
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/NocturneNo2inEflat_44.1k_s16le.pcm";
//        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
//        pcm_split([filePath UTF8String], [outDir UTF8String]);
        
        //2
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/NocturneNo2inEflat_44.1k_s16le.pcm";
//        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
//        pcm_half_volumeleft([filePath UTF8String], [outDir UTF8String]);
        
        //3
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/NocturneNo2inEflat_44.1k_s16le.pcm";
//        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
//        pcm_double_speed([filePath UTF8String], [outDir UTF8String]);
        
        //4
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/NocturneNo2inEflat_44.1k_s16le.pcm";
//        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
//        pcm16le_to_pcm8([filePath UTF8String], [outDir UTF8String]);
        
        //5
//        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/drum.pcm";
//        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
//        pcm16le_single([filePath UTF8String], [outDir UTF8String], 2360, 120);
        
        //6
        NSString *filePath = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/sources/NocturneNo2inEflat_44.1k_s16le.pcm";
        NSString *outDir = @"/Users/hasbeenss/Desktop/ffmpeg_demo/Media_Demo/PCM_Demo/PCM_Demo/output";
        pcm16_to_wav([filePath UTF8String], [outDir UTF8String], 2, 44100);
    }
    return 0;
}
