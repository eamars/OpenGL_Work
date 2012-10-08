//
//  dice_ui.c
//  opengl_monopoly
//
//  Created by eamars on 27/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "dice.h"

void points(int number,float x,float y)
{
    //aa
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_POINT_SMOOTH);
	
    
    glColor3f(BLACK);
    glPointSize(18);
    if (number==1) {
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }
    else if (number==2)
    {
        glBegin(GL_POINTS);
        glVertex2f(x-0.25, y);
        glVertex2f(x+0.25, y);
        glEnd();
    }
    else if (number==3)
    {
        glBegin(GL_POINTS);
        glVertex2f(x+0.25, y+0.25);
        glVertex2f(x, y);
        glVertex2f(x-0.25, y-0.25);
        glEnd();
    }
    else if (number==4)
    {
        glBegin(GL_POINTS);
        glVertex2f(x-0.25, y+0.25);
        glVertex2f(x+0.25, y+0.25);
        glVertex2f(x-0.25, y-0.25);
        glVertex2f(x+0.25, y-0.25);
        glEnd();
    }
    else if (number==5)
    {
        glBegin(GL_POINTS);
        glVertex2f(x-0.25, y+0.25);
        glVertex2f(x+0.25, y+0.25);
        glVertex2f(x, y);
        glVertex2f(x-0.25, y-0.25);
        glVertex2f(x+0.25, y-0.25);
        glEnd();
    }
    else if (number==6)
    {
        glBegin(GL_POINTS);
        glVertex2f(x-0.25, y+0.3);
        glVertex2f(x+0.25, y+0.3);
        glVertex2f(x-0.25, y);
        glVertex2f(x+0.25, y);
        glVertex2f(x-0.25, y-0.3);
        glVertex2f(x+0.25, y-0.3);
        glEnd();
    }
    else
    	prints("ERROR", x-0.4, y+0.2, 1, 2.0);
    
    glFlush();
}

void dice_ui(float x,float y)
{
    glColor3f(WHITE);
    glLineWidth(3);
    //outer line
    glBegin(GL_LINE_LOOP);
    glVertex2f(x-0.1, y+0.1);
    glVertex2f(x+2.6, y+0.1);
    glVertex2f(x+2.6, y-1.9);
    glVertex2f(x-0.1, y-1.9);
    glEnd();
    
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(x-0.1, y+0.1);
    glVertex2f(x+2.6, y+0.1);
    glVertex2f(x+2.6, y-1.9);
    glVertex2f(x-0.1, y-1.9);
    glEnd();
    
    
    //dice1
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+1, y);
    glVertex2f(x+1, y-1);
    glVertex2f(x, y-1);
    glEnd();
    
    
    //dice2
    glBegin(GL_POLYGON);
    glVertex2f(x+1.5, y);
    glVertex2f(x+2.5, y);
    glVertex2f(x+2.5, y-1);
    glVertex2f(x+1.5, y-1);
    glEnd();
    
    
    //click to generate
    glBegin(GL_POLYGON);
    glVertex2f(x, y-1.2);
    glVertex2f(x+2.5, y-1.2);
    glVertex2f(x+2.5, y-1.8);
    glVertex2f(x, y-1.8);
    glEnd();
    glFlush();
    glColor3f(BLACK);
    prints("GENERATE!", x+0.5, y-1.35, 1, 1.9);
    
    //generate dice and display
    points(dice[0], x+0.5, y-0.5);
    points(dice[1], x+2, y-0.5);
    
    
}