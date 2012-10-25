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
        points[i].y = -5;
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
            glVertex2f(points[i].x, points[i].y);
            glEnd();
        }
    }
    
    glFlush();
}

void printScanLine(long t)
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(points[t].x, -4);
    glVertex2f(points[t].x, 4);
    glEnd();
    
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(points[t].x, points[t].y);
    glEnd();
    glFlush();
}


void testfunc2(long t)
{
    int d = t/10000;
    points[t - d*10000].y = buffer[t];
    
    //printf("t=%ld buffer[t]=%f\n",t, buffer[t]);
    glColor3f(BLUE);
	printScanLine(t - d*10000);
    glColor3f(CYAN);
    printFunc();
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