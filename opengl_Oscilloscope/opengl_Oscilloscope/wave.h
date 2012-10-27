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
    char ChunkID[5];//0,4
    uint32 ChunkSize; //4,4
    char Format[5]; //8,4
    char Subchunk1ID[5]; //12,4
    uint32 Subchunk1Size; //16,4
    uint16 AudioFormat; //20,2
    uint16 Channels; //22,2
    uint32 SampleRate; //24,4
    uint32 ByteRate; //28,4
    uint16 BlockAlign; //32,2
    uint16 BitsPerSample; //34,2
    char Subchunk2ID[5]; //36,4
    uint32 Subchunk2Size; //40,4
};

struct HeaderType header;

long DataLength;
#endif
