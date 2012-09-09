//
//  board_opengl.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "define_UI.h"
#include "define_data.h"
#define FRAMEWORK 1




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

    /*Mouse action*/
    glutMouseFunc(MouseAction);
    
    /* buffer */
    glFlush();
    
    
}

void startup()
{
    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    prints("Gomoku", 0.27, 0.9, 0.5,0.08);
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
    glColor3f(0, 0, 0);
    prints("challenge", 0.29, 0.605, 0.35, 0.05);
    prints("versus", 0.35, 0.405, 0.35, 0.05);
    prints("exit", 0.4, 0.205, 0.35, 0.05);
    glFlush();
    glutMouseFunc(MouseClickStartFrame);
}


void MouseClickStartFrame(int button, int state, int x, int y)
{
    //printf("x=%d y=%d\n",x,y);
    if(state == GLUT_DOWN && (float)x/100>COEI*0.2&&(float)x/100<COEI*0.8&&(float)y/100>COEI*0.8&&(float)y/100<COEI*0.9)
    {
        if(button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON)
        {
            //exit
            
            exit(0);
        }
        
    }
    else if(state == GLUT_DOWN && (float)x/100>COEI*0.2&&(float)x/100<COEI*0.8&&(float)y/100>COEI*0.6&&(float)y/100<COEI*0.7)
    {
        if(button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON)
        {
            
            //versus
            
            mode=2;
            glutMouseFunc(NULL);//disable mouse
            model1();

        }
        
    }
    else if(state == GLUT_DOWN && (float)x/100>COEI*0.2&&(float)x/100<COEI*0.8&&(float)y/100>COEI*0.4&&(float)y/100<COEI*0.5)
    {
        if(button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON)
        {
            
            //challenge
            
            mode=1;
            glutMouseFunc(NULL);
            model1();

        }
        
    }
    
    
}
