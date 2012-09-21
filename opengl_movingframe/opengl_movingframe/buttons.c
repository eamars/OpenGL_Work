//
//  buttons.c
//  opengl_movingframe
//
//  Created by eamars on 21/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "define_buttons.h"

void butt(float x,float y)
{
    glColor3f(GREEN);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+0.5, y);
    glVertex2f(x+0.5, y-0.3);
    glVertex2f(x, y-0.3);
    glEnd();
    glFlush();
    
}

void launch(float x,float y)
{
    glColor3f(RED);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+2, y);
    glVertex2f(x+2, y-1);
    glVertex2f(x, y-1);
    glEnd();
    glFlush();
}

void printv(float x,float y,float value)
{
    
    float FS=1;
    float gap=FS/6;
    int neg=0;
    
    if (value<0) {
        value=-value;
        neg=1;
    }
    
    int ten,one;
    ten=value/10;
    one=value-ten*10;
    
    char c_ten,c_one;
    c_ten=ten+48;
    c_one=one+48;
    
    //printf("%c%c\n",c_ten,c_one);
    if (neg==1) {
        printc('-', x, y, FS);
        x=x+gap;
    }
    printc(c_ten, x, y, FS);
    x=x+gap;
    
    printc(c_one, x, y, FS);
    x=x+gap;
}