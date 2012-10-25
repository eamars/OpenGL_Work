//
//  wave.h
//  opengl_Oscilloscope
//
//  Created by eamars on 25/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_Oscilloscope_wave_h
#define opengl_Oscilloscope_wave_h

struct HeaderType {
    char RIFF[5];//0,4
    int Byte; //4,4
    char WAVE[5]; //8,4
    char FMT[5]; //12,4
    int FILTER; //16,4
    int PCM; //20,2
    int CHANNELS; //22,2
    int SampleRate; //24,4
    int byte_rate; //28,4
    int block_align; //32,2
    int SampleDigits; //34,2
    char DATASIGN[5]; //36,4
    int DATACOUNT; //40,4
};

#endif
