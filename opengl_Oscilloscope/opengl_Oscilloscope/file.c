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


int readfromWave(void)
{
    
    
    /* read from sample.wav*/
    FILE *fp;
    if ((fp=fopen("sample.wav", "rb"))==NULL)
    {
        printf("ERROR while reading, exit!\n");
        return 0;
    }
    
    //get wav's header from sample.wav
    getHeader(&header, fp);
    
    //Only support wave format
    if (strcmp(header.Format, "WAVE") != 0) {
        printf("The program only support wave file\n");
        return 0;
    }
    
    //Only support PCM
    if (header.AudioFormat != 1) {
        printf("The program only support PCM.\n");
        return 0;
    }
    
    //Only support 8bit and 16bit waves
    if (header.Channels > 16) {
        printf("Wave more than 2 Channels is not supported at current stage.\n");
        return 0;
    }
    
    //Not support BIG file
    if (header.Subchunk2Size > 16700000) { //bigger than 16.5MB
        printf("The file is Tooooooo big!\n");
        return 0;
    }
    
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
    
    
    int byte_per_sample = header.BitsPerSample/8;//16bit->2 or 8bit->1
    //printf("byte_per_sample = %d\n",header.BlockAlign);
    
    DataLength = header.Subchunk2Size/header.BlockAlign;
    //printf("datalength = %ld\n",DataLength);
    
    //locate to 44
    long offset = 0;
    for (int i = 36; i<50; i++) {
        if (!strcmp(header.Subchunk2ID, "data")) {
            offset = i+8;
            break;
        }
    }
    //printf("offset = %ld\n",offset);
    fseek(fp, offset, SEEK_SET);
    
    
    /*read data chunk*/
    
    
    //8bit Mono
    if (byte_per_sample == 1 && header.Channels == 1) {
        //read data
        uint8 w_buffer[DataLength];//1byte, 8bit wave
        for (long i = 0; i<DataLength; i++) {
            fread(&w_buffer[i], 1, 1, fp);
            //printf("%X, ",w_buffer[i]);
        }
        //transfer
        for (long i = 0; i<DataLength; i++) {
            L_buffer[i] = AMP*(float)w_buffer[i]/256 + -0.5*AMP+2;
        }
    }
    
    
    //16bit Mono
    else if (byte_per_sample == 2 && header.Channels == 1){
        int16 w_buffer[DataLength];//2byte, 16bit wave
        for (long i = 0; i<DataLength; i++) {
            fread(&w_buffer[i], 2, 1, fp);
            //printf("%X\n",w_buffer[i]);
        }
        for (long i = 0; i<DataLength; i++) {
            L_buffer[i] = AMP*(float)w_buffer[i]/65536 + 2;
            //printf("%f\n",buffer[i]);
        }
    }
    
    
    //8bit Stereo
    else if (byte_per_sample == 1 && header.Channels == 2) {
        //read data
        uint8 w_buffer[DataLength];//1byte, 8bit wave
        for (long i = 0; i<DataLength; i++) {
            fread(&w_buffer[i], 1, 1, fp);
            //printf("%X, ",w_buffer[i]);
        }
        //transfer
        for (long i = 0, j = 0; j<DataLength; i++, j = j+2) {
            L_buffer[i] = AMP*(float)w_buffer[j]/256 + -0.5*AMP+2;
            R_buffer[i] = AMP*(float)w_buffer[j+1]/256 + -0.5*AMP+2;
        }
    }
    
    //16bit Stereo
    else if (byte_per_sample == 2 && header.Channels == 2){
        int16 w_buffer[DataLength];//2byte, 16bit wave
        for (uint64 i = 0; i<DataLength; i++) {
            //printf("[%ld]\n",ftell(fp));
            fread(&w_buffer[i], 2, 1, fp);
            //printf("%X\n",w_buffer[i]);
        }
        for (uint64 i = 0, j = 0; j<DataLength; i++, j = j+2) {
            L_buffer[i] = AMP*(float)w_buffer[j]/65536 + 2; //even frame to LEFT channel
            R_buffer[i] = AMP*(float)w_buffer[j+1]/65536 + 2; //odd frame to RIGHT channel
            //printf("[%lld]L = %f R = %f\n",i,L_buffer[i],R_buffer[i]);
        }
    }
    
    
    fclose(fp);
    /*read finish*/
    
    
    
    return 1;
}