//
//  main.c
//  opengl_ploting_graph
//
//  Created by eamars on 30/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include "define.h"
#define COEI 8
#define PREC 0.01
float scale_each=0.5/COEI;




void init(void)
{
    /* clearing background */
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
}


int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Plotted Graph");
    init();
    glutDisplayFunc(model1);
    
    glutMainLoop();
    
    return 0;
}

void model1()
{
    /* clear all pixels */
    glClearColor (0.0, 0.0, 0.0, 0.0);//default background for white
    glClear (GL_COLOR_BUFFER_BIT);
    
    /* print coordinate */
    grid();
    coordinate();
    function_1();
    function_2();
    function_3();
    function_4();
    /* buffer */
    glFlush();
}

void coordinate()
{
    glColor3f(1,1,1);//white
    glLineWidth(1.0f);//line width=1
    glBegin(GL_LINES);
    
    //x coordinate
    glVertex2f(0.0, 0.5);
    glVertex2f(1.0, 0.5);
    //y coordinate
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 1.0);
    glEnd();
    
    //scale
    glBegin(GL_LINES);
    
    //0
    for (float i=0.0; i<0.5; i=i+scale_each) {
        glVertex2f(0.5-PREC, 0.5+i);
        glVertex2f(0.5+PREC, 0.5+i);
    }
    //180
    for (float i=0.0; i<0.5; i=i+scale_each) {
        glVertex2f(0.5-PREC, 0.5-i);
        glVertex2f(0.5+PREC, 0.5-i);
    }
    //90
    for (float i=0.0; i<0.5; i=i+scale_each) {
        glVertex2f(0.5+i, 0.5-PREC);
        glVertex2f(0.5+i, 0.5+PREC);
    }
    //270
    for (float i=0.0; i<0.5; i=i+scale_each) {
        glVertex2f(0.5-i, 0.5-PREC);
        glVertex2f(0.5-i, 0.5+PREC);
    }
    glEnd();
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

void function_1()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glColor3f(1,0,0);//red line
    
    glBegin(GL_LINE_LOOP);
    float y;
    for (float x=-COEI; x<=COEI; x=x+PREC) {
        y=Quadratic_function(x);
        glVertex2f(x/COEI+0.5, y/COEI+0.5);
    }
    glEnd();
}

void function_2()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glColor3f(0,1,1);//cyan line
    
    glBegin(GL_LINE_LOOP);
    float y;
    for (float x=-COEI; x<=COEI; x=x+PREC) {
        y=Sine_function(x);
        glVertex2f(x/COEI+0.5, y/COEI+0.5);
    }
    glEnd();
}

void function_3()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    glColor3f(0,1,0);//green line

    glBegin(GL_LINE_LOOP);
    float PI=3.1415926;
    int N=80;
    float x[N],y[N];
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    

    
}

void function_4()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glColor3f(1,1,0);//yellow line
    
    glBegin(GL_LINE_LOOP);
    float y;
    for (float x=0; x<=COEI; x=x+PREC) {
        y=Logarithm_function(x);
        glVertex2f(x/COEI+0.5, y/COEI+0.5);
    }
    glEnd();
}