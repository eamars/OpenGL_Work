//
//  numbers.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void NumberSet(int number,float x,float y,float fs)
{
    float Point_size;
    
    
    
    /* init axis is from upper left */
    fs=fs/100;
    Point_size=90*fs;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    
    
    
    
    
    
    //flags
    if (number==-2) {
        glColor3f(1, 0, 0);
        glBegin(GL_POINTS);
        glVertex2f(x+3*fs, y);
        glVertex2f(x+2*fs, y-fs);
        glVertex2f(x+3*fs, y-fs);
        glVertex2f(x+fs, y-2*fs);
        glVertex2f(x+2*fs, y-2*fs);
        glVertex2f(x+3*fs, y-2*fs);
        glVertex2f(x+3*fs, y-3*fs);
        glVertex2f(x+3*fs, y-4*fs);
        glEnd();
    }

    glFlush();
    
}

void AdvancedNumverSet(int number,float x,float y,float fs)
{
    glColor3f(0, 0, 0);
    if (number==1) {
        glColor3f(0, 0, 1);
        printc('1', x, y, fs);
    }
    if (number==2) {
        glColor3f(0, 1, 0);
        printc('2', x, y, fs);
    }
    if (number==3) {
        glColor3f(1, 0, 0);
        printc('3', x, y, fs);
    }
    if (number==4) {
        printc('4', x, y, fs);
    }
    if (number==5) {
        printc('5', x, y, fs);
    }
    if (number==6) {
        printc('6', x, y, fs);
    }
    if (number==7) {
        printc('7', x, y, fs);
    }
    if (number==8) {
        printc('8', x, y, fs);
    }
    //mine
    if (number==-1) {
        glColor3f(1, 1, 1);
        printc('\03', x, y, fs);
    }
}