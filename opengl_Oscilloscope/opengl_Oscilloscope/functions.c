//
//  functions.c
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"
#include "wave.h"

void initfunc(void)
{
    float x = -5.0;
    for (int i = 0; i<PREC; i++) {
        L_points[i].x = x;
        L_points[i].y = 2;
        if (header.Channels == 2) {
            R_points[i].x = x;
            R_points[i].y = 2;
        }
        
        x = x + (float)10/PREC;
        //printf("x = [%0.2f]  y = [%0.2f]\n",points[i].x, points[i].y);
    }
}

void printSepPoint(void) //point view
{
    glColor3f(CYAN);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_POINT_SMOOTH);
    glPointSize(2.0f);
    for (int i = 0; i<PREC-1; i++) {
        glBegin(GL_POINTS);
        glVertex2f(L_points[i].x, L_points[i].y);
        if (header.Channels == 2) {
            glVertex2f(R_points[i].x, R_points[i].y-4);
        }
        
        glEnd();
    }
    
    glFlush();
}

void printScanLine(long t)
{
    glColor3f(BLUE);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(L_points[t].x, 0);
    glVertex2f(L_points[t].x, 4);
    if (header.Channels == 2) {
        glVertex2f(L_points[t].x, 0);
        glVertex2f(L_points[t].x, -4);
    }
    glEnd();
    
    glPointSize(5.0f);
    glColor3f(GREEN);
    glBegin(GL_POINTS);
    glVertex2f(L_points[t].x, L_points[t].y); //Left Channel
    if (header.Channels == 2) {
        glVertex2f(R_points[t].x, R_points[t].y-4); //Right Channel
    }
    
    glEnd();
    glFlush();
}

void printLinkLine(void)
{
    glColor3f(CYAN);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(1.0f);
    for (int i = 0; i<PREC-1; i++) {
        glBegin(GL_LINES);
        glVertex2f(L_points[i].x, L_points[i].y);
        glVertex2f(L_points[i+1].x, L_points[i+1].y);
        if (header.Channels == 2) {
            glVertex2f(R_points[i].x, R_points[i].y-4);
            glVertex2f(R_points[i+1].x, R_points[i+1].y-4);
        }
        
        glEnd();
    }

    glFlush();
}


void testfunc2(long t)
{
    int d = t/PREC;
    L_points[t - d*PREC].y = L_buffer[t];
    if (header.Channels == 2) {
        R_points[t - d*PREC].y = R_buffer[t];
    }
    
    
    //printf("t=%ld buffer[t]=%f\n",t, R_buffer[t]);
    glColor3f(BLUE);
	printScanLine(t - d*PREC);
    glColor3f(CYAN);
    //printSepPoint();
    printLinkLine();
    //usleep(1000);
}
void displaytime(long t)
{
    char Frame[20];
    sprintf(Frame, "Frame = %ld",t);
    glColor3f(CYAN);
    prints(Frame, 0, 4.4, 1);
    
}

void printChannels()
{
    glColor3f(GREEN);
    if (header.Channels == 1) {
        prints("[M]", -4.8, 3.9, 0.8);
    }
    
    else if (header.Channels == 2) {
        prints("[L]", -4.8, 3.9, 0.8);
        prints("[R]", -4.8, -0.1, 0.8);
    }
}

void displayPercentage(long t)
{
    char Percentage[20];
    
    sprintf(Percentage, "PlayBack: %0.2f%%",(float)t/DataLength *100);
    
    prints(Percentage, -4.95, 4.4, 1);
    
    char TimeInMs[40];
    
    sprintf(TimeInMs, "Time: %0.0fms/%dms", ((float)t/DataLength)*(header.Subchunk2Size/header.ByteRate)*1000, header.Subchunk2Size/header.ByteRate * 1000);
    
    prints(TimeInMs, -4.95, 4.7, 1);
    
    //float point -> indicate the percentage
    if (-5 + 10*(float)t/DataLength < 10) {
        glColor3f(GREEN);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glVertex2f(-5, 0);
        glVertex2f( -5 + 10*(float)t/DataLength, 0);
        glEnd();
        glFlush();
    }
    
    
}

void printSettings()
{
    glColor3f(CYAN);
    char Amp[30];
    
    sprintf(Amp, "Amplification Level: %d", AMP);
    
    prints(Amp, 0, 5, 1);
    
    char FramePerScreen[30];
    
    sprintf(FramePerScreen, "FramePerScreen: %d",PREC);
    
    prints(FramePerScreen, 0, 4.7, 1);
}

void printWavdata()
{
    glColor3f(CYAN);
    
    
    char AudioType[20];
    
    if (header.AudioFormat == 1) {
        sprintf(AudioType, "AudioType: %s/PCM",header.Format);
    }
    else
        sprintf(AudioType, "AudioType: %s/Unknown",header.Format);
    
    

    prints(AudioType, -4.95, -4.1, 1);
    
    char Channels[20];
    
    if (header.Channels == 1) {
        sprintf(Channels, "Channel: Mono");
    }
    else if (header.Channels == 2){
        sprintf(Channels, "Channel: Stereo");
    }
    
    prints(Channels, -4.95, -4.4, 1);
    
    char ByteRate[40];
    
    sprintf(ByteRate, "ByteRate: %dBytes/s",header.ByteRate);
    
    prints(ByteRate, -4.95, -4.7, 1);
    
    char WaveType[20];
    
    sprintf(WaveType, "Type: %d-bit",header.BitsPerSample);
    
    prints(WaveType, 0, -4.1, 1);
    
    char SampleRate[20];
    
    sprintf(SampleRate, "SampleRate: %dHz",header.SampleRate);
    
    prints(SampleRate, 0, -4.4, 1);
    
    char DataChunkSize[40];
    
    sprintf(DataChunkSize, "Size: %dBytes",header.Subchunk2Size);
    
    prints(DataChunkSize, 0, -4.7, 1);
}