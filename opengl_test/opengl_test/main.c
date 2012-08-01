//
//  main.c
//  opengl_test
//
//  Created by eamars on 30/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>

void model1()
{
    /* clear all pixels */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    /* draw white rectangle */
    glColor3f (0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f (0.25, 0.25);
    glVertex2f (0.75, 0.25);
    glVertex2f (0.75, 0.75);
    glVertex2f (0.25, 0.75);
    glEnd();
    /* buffer */
    glFlush();
}

#define N 256
#define PI 3.1415926
double x[N],y[N];
float M=0.3;

void model2()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}

void model3()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* AA 
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    */
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}

void model4()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    //another circle
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.2*cos(2*i*PI/N)+0.5;
        y[i]=0.2*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();

    glFlush();
}

void model5()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* AA */
     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
     glEnable(GL_LINE_SMOOTH);
     
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    for (float j=0.4; j>=0; j=j-0.01) {
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<N;i++)
        {
            x[i]=j*cos(2*i*PI/N)+0.5;
            y[i]=j*sin(2*i*PI/N)+0.5;
            glVertex2f(x[i],y[i]);
        }
        glEnd();
    }
    glColor3f (1.0, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f (0.9, 0.9);
    glVertex2f (0.9, 0.1);
    glVertex2f (0.1, 0.1);
    glVertex2f (0.1, 0.9);
    glEnd();

    glFlush();
}

void model6()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    // 1
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.2*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    //2
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.2*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    //3
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.1*cos(2*i*PI/N)+0.5;
        y[i]=0.3*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    //4
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        x[i]=0.3*cos(2*i*PI/N)+0.5;
        y[i]=0.1*sin(2*i*PI/N)+0.5;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}

void model7()
{
    
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    //x coordinate
    glVertex2f(0.0, 0.5);
    glVertex2f(1.0, 0.5);
    //y coordinate
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 1.0);
    glEnd();
    //function
    glBegin(GL_LINE_LOOP);
    double y=0;
    for (double x=-5; x<=5; x=x+0.01) {
        y=x*x;
        glVertex2f(x/5+0.5, y/5+0.5);
    }
    glEnd();
    
    glFlush();
}
void piece(char,float,float);

void model8()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH); 
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_POINT_SMOOTH);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(2, 0x0F0F);
    
    glLineWidth(1.5f);
    glColor3f(1,1,0);
    piece('w', 5, 5);
    //coordinate
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(1.0, 0.5);
    
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 1.0);
    glEnd();
    glFlush();
}

void model9()
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_POINT_SMOOTH);

    glLineWidth(1.5f);
    
    /*
    glColor3f(1,0,0);
    
    glBegin(GL_POLYGON);
    glVertex2d(0.25, 0.25);
    glVertex2d(0.25, 0.75);
    glVertex2d(0.75, 0.75);
    glVertex2d(0.75, 0.25);
    glEnd();
    glFlush();
     */
}

void MousePassing(int x, int y)
{
    if (x>125&&x<375&&y>125&&y<375) {
        glColor3f(0.75, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(0.25, 0.25);
        glVertex2d(0.25, 0.75);
        glVertex2d(0.75, 0.75);
        glVertex2d(0.75, 0.25);
        glEnd();
        glFlush();
    }
    else
    {
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(0.25, 0.25);
        glVertex2d(0.25, 0.75);
        glVertex2d(0.75, 0.75);
        glVertex2d(0.75, 0.25);
        glEnd();
        glFlush();
    }
}
void MouseClick(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN && x>125&&x<375&&y>125&&y<375)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            printf("YouHaveLeftClickedIt!\n");
            glColor3f(1, 1, 1);
            glBegin(GL_POLYGON);
            glVertex2d(0.25, 0.25);
            glVertex2d(0.25, 0.75);
            glVertex2d(0.75, 0.75);
            glVertex2d(0.75, 0.25);
            glEnd();
            glFlush();
        }
        if (button == GLUT_RIGHT_BUTTON) {
            printf("YouHaveRightClickedIt!\n");
            glColor3f(0, 0, 0);
            glBegin(GL_POLYGON);
            glVertex2d(0.25, 0.25);
            glVertex2d(0.25, 0.75);
            glVertex2d(0.75, 0.75);
            glVertex2d(0.75, 0.25);
            glEnd();
            glFlush();
        }
        
    }
        
}

void MouseOutFrame(int state)
{
    if (state==GLUT_LEFT) {
        printf("YouHaveLeft!\n");
    }
    if (state==GLUT_ENTERED) {
        printf("YouHaveReturned!\n");
    }
}

void piece(char side,float x_axis,float y_axis)
{
    int const COEI=8;
    if (side=='w') {
        glColor3f(1, 1, 1);
    }
    else if (side=='b')
        glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for(int i=0;i<N;i++)
    {
        x[i]=0.03*cos(2*i*PI/N)+x_axis/COEI;
        y[i]=0.03*sin(2*i*PI/N)+y_axis/COEI;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    
    glFlush();
    
}

void init(void)
{
    /* clearing background */
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}


int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("AA Enabled");
    init();
    
    glutPassiveMotionFunc(MousePassing);
    glutMouseFunc(MouseClick);
    glutEntryFunc(MouseOutFrame);
    glutDisplayFunc(model9);
    
    glutMainLoop();
    
    return 0;
}
