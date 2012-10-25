//
//  screen.c
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "screen.h"

void init_var(void)
{
    //floattime = 0.0;
    inttime = 0;
}


void displayfunc(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    coordinates();
    display_FPS();
    displaytime(inttime);
    testfunc2(inttime);
    inttime++;
    
    
    
    //testfunc(floattime);
    //displaytime(floattime);
    //floattime = floattime + 0.01;
    usleep(1000);
    glutSwapBuffers();
}

void scope(void)
{
    
    initfunc();
    init_var();
    glutIdleFunc(displayfunc);
    
}


void coordinates(void)
{
    glLineWidth(0.1f);
    //other coordinates x
    glColor3f(GREY);
    //x
    for (int i = -5; i<=5; i++) {
        glBegin(GL_LINES);
        glVertex2f(-5, i);
        glVertex2f(5, i);
        glEnd();
    }
    //y
    for (int i = -4; i<=4; i++) {
        glBegin(GL_LINES);
        glVertex2f(i, -4);
        glVertex2f(i, 4);
        glEnd();
    }
    
    //smaller coordinates
    glColor3f(GREY);
    //x
    for (float i = -4; i<=4; i = i+0.2) {
        glBegin(GL_LINES);
        glVertex2f(-0.05, i);
        glVertex2f(0.05, i);
        glEnd();
    }
    //y
    for (float i = -5; i<=5; i = i+0.2) {
        glBegin(GL_LINES);
        glVertex2f(i, -0.05);
        glVertex2f(i, 0.05);
        glEnd();
    }
    
    // main coordinates x,y
    glColor3f(GREY);
    //x
    glBegin(GL_LINES);
    glVertex2f(-5.0, 0.0);
    glVertex2f(5.0, 0.0);
    glEnd();
    //y
    glBegin(GL_LINES);
    glVertex2f(0.0, -4.0);
    glVertex2f(0.0, 4.0);
    glEnd();
	
    glFlush();
}