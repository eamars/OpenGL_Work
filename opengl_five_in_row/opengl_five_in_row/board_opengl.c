//
//  board_opengl.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>

#include "define_board_opengl.h"
#include <GLUT/glut.h>
#include <math.h>
#define PI 3.1415926
#define N 80


void init(void)
{
    /* clearing background */
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
}

void grid()
{
    glColor3f(0.25, 0.25, 0.25);
    glLineWidth(0.5);
    glBegin(GL_LINES);
    
    //horizontal
    for (float i=0; i<1; i=i+0.5/COEI) {
        glVertex2f(0.0+i, 0.0);
        glVertex2f(0.0+i, 1.0);
    }
    //vertical
    for (float i=0; i<1; i=i+0.5/COEI) {
        glVertex2f(0.0, 0.0+i);
        glVertex2f(1.0, 0.0+i);
    }
    
    glEnd();
    
    
    
}




void model1()
{
    /* clear all pixels */
    glClearColor (0.0, 0.0, 0.0, 0.0);//default background for white
    glClear (GL_COLOR_BUFFER_BIT);
    
    /* print coordinate */
    grid();
    piece_GL('w', 5, 5);
    
    /* buffer */
    glFlush();
    
    
}

void piece_GL(char side,int x_axis,int y_axis)
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    //radius of each piece
    float radius=-0.005*COEI+0.065;

    
    float x[N],y[N];
    if (side=='w') {
        glColor3f(1, 1, 1);
    }
    else if (side=='b')
        glColor3f(0, 0, 0);
    
    //start drawing
    glBegin(GL_POLYGON);
    for(int i=0;i<N;i++)
    {
        x[i]=radius*cos(2*i*PI/N)+(float)x_axis/(2*COEI);
        /* reverse the y axis so that the (0,0) is at the upper left */
        y[i]=radius*sin(2*i*PI/N)+(2*COEI-(float)y_axis)/(2*COEI);
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    //circle to highlight
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=radius*cos(2*i*PI/N)+(float)x_axis/(2*COEI);
        /* reverse the y axis so that the (0,0) is at the upper left */
        y[i]=radius*sin(2*i*PI/N)+(2*COEI-(float)y_axis)/(2*COEI);
        glVertex2f(x[i],y[i]);
    }
    glEnd();
}