//
//  framework.c
//  opengl_movingframe
//
//  Created by eamars on 21/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "define_UI.h"
#include "define_buttons.h"

float time=0;


void startup(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    prints("Projectile motion", 1, 9, 1);
    prints("set horizontal velocity:", 1, 8, 1);
    printv(5.2, 8, vx);
    butt(6, 8); //up
    glColor3f(BLACK);
    prints("VX", 6.12, 7.98, 1);

    
    glColor3f(WHITE);
    prints("set vertical velocity:", 1, 6, 1);
    printv(5.2, 6, vy);
    butt(6, 6);
    glColor3f(BLACK);
    prints("VY", 6.12, 5.98, 1);

    glColor3f(WHITE);
    prints("(note:LEFT click the green button to add on, RIGHT click to take away)", 1, 4, 1);
    
    launch(2.5, 3);
    glColor3f(WHITE);
    prints("Launch", 3, 2.6, 1);
	glutSwapBuffers();
}

void function()
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    display_FPS(0, 10);
    display_time(2, 10,time);
    
    /* for horzontal
     displacement=velocity*time;
     
       for vertical
     displacement=velocity(init)*time+0.5*a*time^2
     */
    float x=0,y=8;
    x=x+displacement_x(time);
    y=y-displacement_y(time);
    Asymptote(x, y);
    particle(x, y, 0.15);
    if (y+1.6>10 || x-2.1<0) {
        display_value(x+0.1, y-0.1, x, y, vx, vy+G*time);
    }
    else
    	display_value(x-2.1, y+1.6, x, y, vx, vy+G*time);
    time=time+0.001;
#ifdef __WIN32__
    Sleep(1);
#else
    usleep(1000);
#endif
    glutSwapBuffers();
    if (x>20 || y<0) {
        glutIdleFunc(NULL);
        printf("Simulation finished!\n");
	}
    
    
    //printf("x=%f y=%f t=%0.0f\n",x,y,time);
}

void trace()
{
    
}



void particle(float xf,float yf,float radius)
{
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glColor3f(RED);
    float x[N],y[N];
    glBegin(GL_POLYGON);
    for(int i=0;i<N;i++)
    {
        x[i]=radius*cos(2*i*PI/N)+xf;
        y[i]=radius*sin(2*i*PI/N)+yf;
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    
    
    
    glFlush();

}



float displacement_x(float time)
{
    float dp;
    dp=vx*time;
    return dp;
}


float displacement_y(float time)
{
    float dp;
    dp=vy*time+0.5*G*time*time;
    return dp;
}


void Asymptote(float x,float y)
{
    glColor3f(GREEN);
    glBegin(GL_LINES);
    glVertex2f(0, y);
    glVertex2f(20, y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x, 0);
    glVertex2f(x, 20);
    glEnd();
    glFlush();
}



