//
//  file.c
//  opengl_Oscilloscope
//
//  Created by eamars on 24/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file.h"
#include "wave.h"

uint16 uEndian_16(uint16 n)
{
    
    // You can do this with unions but...
    uint8 a[2], *pn;
    
    pn = (uint8*)&n;
    a[1] = *(pn+0);
    a[0] = *(pn+1);
    return *(uint16 *)&a;
}

int16 Endian_16(int16 n)
{
    int8 a[2], *pn;
    
    pn = (int8*)&n;
    a[1] = *(pn+0);
    a[0] = *(pn+1);
    return *(int16 *)&a;
}


long getHeader(struct HeaderType *header, FILE *fp)
{
    
    //0

    fread(&header->ChunkID, 4, 1, fp);
    header->ChunkID[4] = '\0';
    //4

    fread(&header->ChunkSize, 4, 1, fp);
    
    //8

    fread(&header->Format, 4, 1, fp);
    header->Format[4] = '\0';
    
    //12

    fread(&header->Subchunk1ID, 4, 1, fp);
    header->Subchunk1ID[4] = '\0';
    
    //16

    fread(&header->Subchunk1Size, 4, 1, fp);
    
    //20

    fread(&header->AudioFormat, 2, 1, fp);
    
    //22

    fread(&header->Channels, 2, 1, fp);
    
    //24

    fread(&header->SampleRate, 4, 1, fp);
    
    //28

    fread(&header->ByteRate, 4, 1, fp);
    
    //32

    fread(&header->BlockAlign, 2, 1, fp);
    
    //34

    fread(&header->BitsPerSample, 2, 1, fp);
    
    //36

    fread(&header->Subchunk2ID, 4, 1, fp);
    header->Subchunk2ID[4] = '\0';
    
    //40

    fread(&header->Subchunk2Size, 4, 1, fp);
    
    return header->Subchunk2Size;
}


void readfromWave(void)
{
    
    
    /* read from sample.wav*/
    FILE *fp;
    if ((fp=fopen("sample.wav", "rb"))==NULL)
    {
        printf("ERROR while reading, exit!\n");
        exit(0);
    }
    
    //get wav's header from sample.wav
    getHeader(&header, fp);
    
    //Stereo Wave Not support at current stage
    if (header.Channels != 1 || header.AudioFormat != 1) {
        printf("The program only support Mono Wave at current stage\n");
        exit(0);
    }
    /*
    printf("ChunkID = %s\n",header.ChunkID);
    printf("ChunkSize = %d\n",header.ChunkSize);
    printf("Format = %s\n",header.Format);
    printf("Subchunk1ID = %s\n",header.Subchunk1ID);
    printf("Subchunk1Size = %d\n",header.Subchunk1Size);
    printf("AudioFormat = %d\n",header.AudioFormat);
    printf("Channels = %d\n",header.Channels);
    printf("SampleRate = %d\n",header.SampleRate);
    printf("ByteRate = %d\n",header.ByteRate);
    printf("BlockAlign = %d\n",header.BlockAlign);
    printf("BitsPerSample = %d\n",header.BitsPerSample);
    printf("Subchunk2ID = %s\n",header.Subchunk2ID);
    printf("Subchunk2Size = %d\n",header.Subchunk2Size);
    */
    int byte_per_sample = header.BitsPerSample/8;//16bit->2 or 8bit->1
    //printf("byte_per_sample = %d\n",byte_per_sample);
    DataLength = header.Subchunk2Size/byte_per_sample;
    
    
    //locate to 44
    long offset = 0;
    for (int i = 36; i<50; i++) {
        if (!strcmp(header.Subchunk2ID, "data")) {
            offset = i+8;
            break;
        }
    }
    
    fseek(fp, offset, SEEK_SET);
    

    
    /*read data chunk*/
    
    
    //8bit Mono
    if (byte_per_sample == 1) {
        //read data
        uint8 w_buffer[DataLength];//1byte, 8bit wave
        for (int i = 0; i<DataLength; i++) {
            fread(&w_buffer[i], 1, 1, fp);
            //printf("%X, ",w_buffer[i]);
        }
        //transfer
        for (int i = 0; i<DataLength; i++) {
            buffer[i] = AMP*(float)w_buffer[i]/256 + 1;
        }
    }
    
    
    //16bit Mono
    else if (byte_per_sample == 2){
        int16 w_buffer[DataLength];//2byte, 16bit wave
        for (int i = 0; i<DataLength; i++) {
            fread(&w_buffer[i], 2, 1, fp);
            //printf("%X\n",w_buffer[i]);
        }
        for (int i = 0; i<DataLength; i++) {
            buffer[i] = AMP*(float)w_buffer[i]/65536 + 2;
            //printf("%f\n",buffer[i]);
        }
    }
    
    
    //24bit
        
    
    
    
    fclose(fp);
    /*read finish*/
    
    
    
    
}