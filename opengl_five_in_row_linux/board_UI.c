//
//  board_opengl.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



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
    glClearColor (0.0, 0.0, 0.0, 0.0);//default background for black
    glClear (GL_COLOR_BUFFER_BIT);
    
    /* print coordinate */
    grid();
    
    /* buffer */
    glFlush();
    
    
}





