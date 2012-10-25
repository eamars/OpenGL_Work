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

void initfunc(void)
{
    float x = -5.0;
    for (int i = 0; i<PREC; i++) {
        points[i].x = x;
        points[i].y = 0;
        x = x + (float)10/PREC;
        //printf("x = [%0.2f]  y = [%0.2f]\n",points[i].x, points[i].y);
    }
}

void printFunc(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1.0f);
    for (int i = 0; i<PREC; i++) {
        if (points[i].y < 4 && points[i].y > -4) {
            glBegin(GL_POINTS);
            glVertex2f(points[i].x, -points[i].y);
            glEnd();
        }
    }
    
    glFlush();
}

void printScanLine(long t)
{
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(points[t].x, -4);
    glVertex2f(points[t].x, 4);
    glEnd();
    
    glPointSize(5.0f);
    glColor3f(GREEN);
    glBegin(GL_POINTS);
    glVertex2f(points[t].x, points[t].y); //upper point
    glVertex2f(points[t].x, -points[t].y); //lower point
    glEnd();
    glFlush();
}

void printLinkLine(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(1.0f);
    for (int i = 0; i<PREC-1; i++) {
        glBegin(GL_LINES);
        glVertex2f(points[i].x, points[i].y);
        glVertex2f(points[i+1].x, points[i+1].y);
        glEnd();
    }
    glFlush();
}


void testfunc2(long t)
{
    int d = t/PREC;
    points[t - d*PREC].y = buffer[t];
    
    //printf("t=%ld buffer[t]=%f\n",t, buffer[t]);
    glColor3f(BLUE);
	printScanLine(t - d*PREC);
    glColor3f(CYAN);
    printFunc();
    printLinkLine();
    //usleep(1000);
}
void displaytime(long t)
{
    char time[40];
    sprintf(time, "Frame = %ld",t);
    glColor3f(CYAN);
    prints(time, -4.95, -3.7, 1);
}

void displayPercentage(long t)
{
    
}