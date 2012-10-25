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

void readfromfile(void)
{
    FILE *fp;
    char filename[]={"wave.dat"};
    if ((fp=fopen(filename, "r"))==NULL)
    {
        printf("No Wave File Founded!\nPlease Check If There Is A File Named <wave.dat> and Run Again\n");
        sleep(10);
        exit(0);
    }
    
    for (int i = 0; i<1000000; i++) {
        fscanf(fp, "%f, ", &buffer[i]);
    }
    fclose(fp);
}


long getHeader(struct HeaderType *header, char Filename[])
{
    FILE *fp;
    if ((fp=fopen(Filename, "rb"))==NULL)
    {
        printf("No Wave File Founded!\nPlease Check If There Is A File Named <sample.wav> and Run Again\n");
        sleep(10);
        exit(0);
    }
    //0

    fread(&header->RIFF, 4, 1, fp);
    header->RIFF[4] = '\0';
    //4

    fread(&header->Byte, 4, 1, fp);
    
    //8

    fread(&header->WAVE, 4, 1, fp);
    header->WAVE[4] = '\0';
    
    //12

    fread(&header->FMT, 4, 1, fp);
    header->FMT[4] = '\0';
    
    //16

    fread(&header->FILTER, 4, 1, fp);
    
    //20

    fread(&header->PCM, 2, 1, fp);
    
    //22

    fread(&header->CHANNELS, 2, 1, fp);
    
    //24

    fread(&header->SampleRate, 4, 1, fp);
    
    //28

    fread(&header->byte_rate, 4, 1, fp);
    
    //32

    fread(&header->block_align, 2, 1, fp);
    
    //34

    fread(&header->SampleDigits, 2, 1, fp);
    
    //36

    fread(&header->DATASIGN, 4, 1, fp);
    header->DATASIGN[4] = '\0';
    
    //40

    fread(&header->DATACOUNT, 4, 1, fp);
    
    fclose(fp);
    return header->DATACOUNT;
}


void readfromWave(void)
{
    struct HeaderType header;
    
    getHeader(&header, "sample.wav");
    
    /*
    if (header.PCM != 1) {
        printf("Must be a PCM type!\n");
        exit(0);
    }
    if (header.CHANNELS != 1) {
        printf("Must be a mono channel wave file!\n");
        exit(0);
    }
    if (header.SampleDigits != 8) {
        printf("Must be a 8bit wave file!\n");
        exit(0);
    }
    */
    
    //readin
    FILE *fp;
    fp = fopen("sample.wav", "rb");
    
    int bit_per_sample = header.SampleDigits/8;
    
    //find "data" offset
    long offset;
    char head[5];
    head[4] = '\0';
    for (long i = 30; i<45; i++) {
        fseek(fp, i, 0);
        fread(head, 4, 1, fp);
        if (!strcmp(head, "data")) {
            //printf("i = %ld\n",i);
            offset = i + 8;
            break;
        }
    }
    
    int wavebuffer[header.DATACOUNT/bit_per_sample];
    float fbuffer[header.DATACOUNT/bit_per_sample];
    
    for (int i = 0; i<header.DATACOUNT/bit_per_sample; i++) {
        fread(&wavebuffer[i], bit_per_sample, 1, fp);
        fbuffer[i] = 1.5*(float)wavebuffer[i]/100;
        //printf("%f, ",buffer[i]);
    }
    fclose(fp);
    //writeout
    FILE *out;
    if ((out = fopen("wave.dat", "wb")) == NULL) {
    	printf("ERROR while writing, exit!\n");
        exit (0);
    }
    for (int i = 0; i<header.DATACOUNT/bit_per_sample; i++,offset = offset + bit_per_sample) {
        fprintf(out, "%f, ",fbuffer[i]);
    }
    fclose(out);
    
    
     printf("RIFF = %s\n",header.RIFF);
     printf("TotalByte = %d\n",header.Byte);
     printf("WAVE = %s\n",header.WAVE);
     printf("FMT = %s\n",header.FMT);
     printf("FILTER = %d\n",header.FILTER);
     printf("PCM = %d\n",header.PCM);
     printf("CHANNEL = %d\n",header.CHANNELS);
     printf("SAMPLEFREQ = %d\n",header.SampleRate);
     printf("Byte rate = %d\n",header.byte_rate);
     printf("ADJDATA = %d\n",header.block_align);
     printf("SampleDigits = %d\n",header.SampleDigits);
     printf("DataSign = %s\n",header.DATASIGN);
     printf("TotalData = %d\n",header.DATACOUNT);
     
    
    
    
    fclose(fp);
}