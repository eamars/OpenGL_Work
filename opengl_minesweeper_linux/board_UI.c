//
//  board_UI.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "define_data.h"
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

void init(void)
{
    /* clearing background */
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,FRAMEWORK,0.0,FRAMEWORK,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
}

void grid()
{
    glColor3f(0.5, 0.5, 0.5);
    glLineWidth(0.5);
    glBegin(GL_LINES);
    
    //horizontal
    for (float i=0; i<FRAMEWORK; i=i+FRAMEWORK/BOARD_SIZE) {
        glVertex2f(0.0+i, 0.0);
        glVertex2f(0.0+i, FRAMEWORK);
    }
    //vertical
    for (float i=0; i<FRAMEWORK; i=i+FRAMEWORK/BOARD_SIZE) {
        glVertex2f(0.0, 0.0+i);
        glVertex2f(FRAMEWORK, 0.0+i);
    }
    
    glEnd();
    glFlush();
    
}

void Mine_sweeper(void)
{
    grid();
    Blind_piece();
    glutMouseFunc(MouseClick);
    glFlush();
}

void End_frame(int status)
{
    glColor4f(0, 0, 0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2d(FRAMEWORK*0.2, FRAMEWORK*0.4);
    glVertex2d(FRAMEWORK*0.2, FRAMEWORK*0.6);
    glVertex2d(FRAMEWORK*0.8,FRAMEWORK* 0.6);
    glVertex2d(FRAMEWORK*0.8, FRAMEWORK*0.4);
    glEnd();
    
    //out line
    glLineWidth(3);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x0F0F);
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(FRAMEWORK*0.2, FRAMEWORK*0.4);
    glVertex2d(FRAMEWORK*0.2, FRAMEWORK*0.6);
    glVertex2d(FRAMEWORK*0.8, FRAMEWORK*0.6);
    glVertex2d(FRAMEWORK*0.8, FRAMEWORK*0.4);
    glEnd();
    glFlush();
    

    if (status==1) {
        glColor3f(1, 0, 0);
        YOU_WIN(FRAMEWORK*0.26, FRAMEWORK*0.55, 2.5);
    }
    else
    {
        glColor3f(1, 0, 0);
        YOU_LOSE(FRAMEWORK*0.23, FRAMEWORK*0.55, 2.5);
    }

}

void startup_frame(void)
{
    glBegin(GL_POLYGON);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.1);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.2);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.2);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.3);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.4);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.4);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.5);
    glVertex2f(FRAMEWORK*0.2, FRAMEWORK*0.6);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.6);
    glVertex2f(FRAMEWORK*0.8, FRAMEWORK*0.5);
    glEnd();
    glFlush();
    
    glutMouseFunc(MouseClickStartFrame);
}