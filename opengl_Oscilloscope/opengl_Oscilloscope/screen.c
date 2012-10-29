//
//  screen.c
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "screen.h"
#include "wave.h"

void init_var(void)
{
    //floattime = 0.0;
    inttime = 0;
}


void displayfunc(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    coordinates();
    testfunc2(inttime);
    display_FPS();
    displaytime(inttime);
    displayPercentage(inttime);
    printWavdata();
    printSettings();
    printChannels();
    if (inttime < DataLength) {
        inttime++;
    }
    
    else
        exit(0);
    
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
    glLineWidth(1.0f);
    glColor3f(GREEN);
    //x
    for (float i = -4; i<=4; i = i+0.2) {
        glBegin(GL_LINES);
        glVertex2f(-4.95, i);
        glVertex2f(-4.85, i);
        glEnd();
    }
    //y
    for (float i = -5; i<=5; i = i+0.2) {
        glBegin(GL_LINES);
        glVertex2f(i, 2.05);
        glVertex2f(i, 1.95);
        
        glVertex2f(i, -2.05);
        glVertex2f(i, -1.95);
        glEnd();
    }
    

    
    
    //edge
    glColor3f(WHITE);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glVertex2f(-5.0, 4.0);
    glVertex2f(5.0, 4.0);
    
    glVertex2f(-5.0, -4.0);
    glVertex2f(5.0, -4.0);
    
    glColor3f(GREY);
    glVertex2f(-5.0, 0.0);
    glVertex2f(5.0, 0.0);
    
    glEnd();
	
    glFlush();
}