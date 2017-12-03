//
//  PCM_Test_Demo.hpp
//  PCM_Demo
//
//  Created by Hasbeenss on 02/12/2017.
//  Copyright © 2017 Hasbeenss. All rights reserved.
//

#ifndef PCM_Test_Demo_hpp
#define PCM_Test_Demo_hpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pcm_split(const char *input_path, const char *output_dir);

int pcm_half_volumeleft(const char *input_path, const char *output_dir);

int pcm_double_speed(const char *input_path, const char *output_dir);

int pcm16le_to_pcm8(const char *input_path, const char *output_dir);

int pcm16le_single(const char *input_path, const char *output_dir, int start_num,int dur_num);

int pcm16_to_wav(const char *input_path, const char *output_dir, int channels, int sample_rate);

#endif /* PCM_Test_Demo_hpp */
