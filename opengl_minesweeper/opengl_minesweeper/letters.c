//
//  letters.c
//  opengl_minesweeper
//
//  Created by eamars on 4/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Lett_Y (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x, y);
    glVertex2f(x+FS, y-FS);
    glVertex2f(x+2*FS, y-2*FS);
    glVertex2f(x+3*FS, y-FS);
    glVertex2f(x+4*FS, y);
    glVertex2f(x+2*FS, y-3*FS);
    glVertex2f(x+2*FS, y-4*FS);
    
    glEnd();
    glFlush();
    
}

void Lett_O (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x+FS,y);
    glVertex2f(x+2*FS, y);
    glVertex2f(x+3*FS, y);
    glVertex2f(x, y-FS);
    glVertex2f(x+4*FS, y-FS);
    glVertex2f(x, y-2*FS);
    glVertex2f(x+4*FS, y-2*FS);
    glVertex2f(x, y-3*FS);
    glVertex2f(x+4*FS, y-3*FS);
    glVertex2f(x+3*FS, y-4*FS);
    glVertex2f(x+2*FS, y-4*FS);
    glVertex2f(x+FS, y-4*FS);
    
    
    
    
    glEnd();
    glFlush();
    
}

void Lett_U (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x, y);
    glVertex2f(x+4*FS, y);
    glVertex2f(x, y-FS);
    glVertex2f(x+4*FS, y-FS);
    glVertex2f(x, y-2*FS);
    glVertex2f(x+4*FS, y-2*FS);
    glVertex2f(x, y-3*FS);
    glVertex2f(x+4*FS, y-3*FS);
    glVertex2f(x+FS, y-4*FS);
    glVertex2f(x+2*FS, y-4*FS);
    glVertex2f(x+3*FS, y-4*FS);
    
    
    glEnd();
    glFlush();
}

void Lett_W (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x, y);
    glVertex2f(x+4*FS, y);
    glVertex2f(x, y-FS);
    glVertex2f(x+4*FS, y-FS);
    glVertex2f(x, y-2*FS);
    glVertex2f(x+2*FS, y-2*FS);
    glVertex2f(x+4*FS, y-2*FS);
    glVertex2f(x, y-3*FS);
    glVertex2f(x+2*FS, y-3*FS);
    glVertex2f(x+4*FS, y-3*FS);
    glVertex2f(x+FS, y-4*FS);
    glVertex2f(x+3*FS, y-4*FS);
    
    
    
    glEnd();
    glFlush();
}

void Lett_I (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x+FS, y);
    glVertex2f(x+2*FS, y);
    glVertex2f(x+3*FS, y);
    glVertex2f(x+2*FS, y-FS);
    glVertex2f(x+2*FS, y-2*FS);
    glVertex2f(x+2*FS, y-3*FS);
    glVertex2f(x+2*FS, y-4*FS);
    glVertex2f(x+FS, y-4*FS);
    glVertex2f(x+3*FS, y-4*FS);
    
    glEnd();
    glFlush();
}



void Lett_N (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x, y);
    glVertex2f(x, y-1*FS);
    glVertex2f(x, y-2*FS);
    glVertex2f(x, y-3*FS);
    glVertex2f(x, y-4*FS);
    glVertex2f(x+4*FS, y);
    glVertex2f(x+4*FS, y-1*FS);
    glVertex2f(x+4*FS, y-2*FS);
    glVertex2f(x+4*FS, y-3*FS);
    glVertex2f(x+4*FS, y-4*FS);
    glVertex2f(x+1*FS, y-1*FS);
    glVertex2f(x+2*FS, y-2*FS);
    glVertex2f(x+3*FS, y-3*FS);
    
    
    
    glEnd();
    glFlush();
}

void Sign_1 (float x,float y,float FS)
{
    float Point_size;

    
    
    /* init axis is from upper left */
    Point_size=FS;
    FS=FS/100;
    glColor3f(1, 1, 1);
    glPointSize(Point_size);
    glBegin(GL_POINTS);
    
    
    
    glVertex2f(x+2*FS, y);
    glVertex2f(x+2*FS, y-1*FS);
    glVertex2f(x+2*FS, y-2*FS);
    glVertex2f(x+2*FS, y-4*FS);
    
    
    
    glEnd();
    glFlush();
}


void YOU_WIN (float x,float y,float FS)
{
    Lett_Y(x, y, FS);
    x=x+FS/15;
    Lett_O(x, y, FS);
    x=x+FS/15;
    Lett_U(x, y, FS);
    x=x+FS*2/15;
    Lett_W(x, y, FS);
    x=x+FS/15;
    Lett_I(x, y, FS);
    x=x+FS/15;
    Lett_N(x, y, FS);
    x=x+FS/15;
    Sign_1(x, y, FS);
}
