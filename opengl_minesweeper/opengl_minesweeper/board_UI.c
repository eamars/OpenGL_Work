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
    
    
    
    
}
