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
    
    
    /* 1 */
    if (number==1) {
        glBegin(GL_POINTS);
        glVertex2f(x+2*fs, y);
        glVertex2f(x+1*fs, y-fs);
        glVertex2f(x+2*fs, y-fs);
        glVertex2f(x+2*fs, y-2*fs);
        glVertex2f(x+2*fs, y-3*fs);
        glVertex2f(x+1*fs, y-4*fs);
        glVertex2f(x+2*fs, y-4*fs);
        glVertex2f(x+3*fs, y-4*fs);
        glEnd();
    }
    
    if (number==2) {
        glBegin(GL_POINTS);
        glVertex2f(x+2*fs, y);
        glVertex2f(x+fs, y-fs);
        glVertex2f(x+3*fs, y-fs);
        glVertex2f(x+3*fs, y-2*fs);
        glVertex2f(x+2*fs, y-3*fs);
        glVertex2f(x+fs, y-4*fs);
        glVertex2f(x+2*fs, y-4*fs);
        glVertex2f(x+3*fs, y-4*fs);
        glEnd();
    }
    if (number==3) {
        glBegin(GL_POINTS);
        glVertex2f(x+fs, y);
        glVertex2f(x+2*fs, y);
        glVertex2f(x+3*fs, y-fs);
        glVertex2f(x+fs, y-2*fs);
        glVertex2f(x+2*fs, y-2*fs);
        glVertex2f(x+3*fs, y-3*fs);
        glVertex2f(x+fs, y-4*fs);
        glVertex2f(x+2*fs, y-4*fs);
        glEnd();
        
    }
    
    //none
    
    
    //mine
    if (number==-1) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glVertex2f(x+4*fs, y);
        glVertex2f(x, y-fs);
        glVertex2f(x+fs, y-fs);
        glVertex2f(x+3*fs, y-fs);
        glVertex2f(x+4*fs, y-fs);
        glVertex2f(x, y-2*fs);
        glVertex2f(x+2*fs, y-2*fs);
        glVertex2f(x+4*fs, y-2*fs);
        glVertex2f(x, y-3*fs);
        glVertex2f(x+4*fs, y-3*fs);
        glVertex2f(x, y-4*fs);
        glVertex2f(x+4*fs, y-4*fs);
        glEnd();
    }
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