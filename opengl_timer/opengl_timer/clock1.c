//
//  clock1.c
//  opengl_timer
//
//  Created by eamars on 24/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_graph.h"
#include <math.h>
#include <time.h>

/*
 in Unix liked system, the sleep is defined in <unistd.h> while in windows, sleep() is defined in <windows.h>
 sleep(1)=sleep(1000) in macos than that in linux/windows
 */


#ifdef __WIN32__ 
#include <windows.h>
#else
#include <unistd.h>
#endif



#define PI 3.1415926
#define N 80

void timecheck()
{
    
    time_t timer;
    struct tm *tblock;
    
    
    int current_sec = 0,last_sec;
    
    
    timer=time(NULL);
    tblock=localtime(&timer);
    
    last_sec=current_sec;
    current_sec=tblock->tm_sec;
    
    if (last_sec!=current_sec) {
        timer1();
#ifdef __WIN32__
        Sleep(998);
#else
        sleep(0.998);//give cpu a delay time
#endif
    }
}

void timer1()
{
    //prints("helloworld", 0, 0, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    clock1(0, 0, 4);
    glutSwapBuffers();
    
}

void clock1(float xf,float yf,float radius)
{
    float x[N],y[N];
    
    
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
	
    
    glColor3f(WHITE);
    glLineWidth(10);
    //clock panel outer layor
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<N; i++) {
        x[i]=radius*cos(2*i*PI/N)+xf;
        y[i]=radius*sin(2*i*PI/N)+yf;
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    glFlush();
    
    //unit
    glLineWidth(5);
    glBegin(GL_LINES);
    for (int i=0; i<60; i++) {
        glVertex2f((radius-0.15)*sin(i*6*(PI/180)), (radius-0.15)*cos(i*6*(PI/180)));
        glVertex2f(radius*sin(i*6*(PI/180)), radius*cos(i*6*(PI/180)));
    }
    
    //number
    for (int i=0; i<12; i++) {
        if (i==0) {
            printc(ten_digit(12)+48, radius/1.1*sin(i*30*(PI/180))-0.06, radius/1.1*cos(i*30*(PI/180))+0.15, 1);
            printc(one_digit(12)+48, radius/1.1*sin(i*30*(PI/180))+0.1, radius/1.1*cos(i*30*(PI/180))+0.15, 1);
        }
        if (i<10 && i>0) {
            printc(i+48, radius/1.1*sin(i*30*(PI/180))-0.06, radius/1.1*cos(i*30*(PI/180))+0.15, 1);
        }
        
        else if (i>9)
        {
            printc(ten_digit(i)+48, radius/1.1*sin(i*30*(PI/180))-0.06, radius/1.1*cos(i*30*(PI/180))+0.15, 1);
            printc(one_digit(i)+48, radius/1.1*sin(i*30*(PI/180))+0.1, radius/1.1*cos(i*30*(PI/180))+0.15, 1);
        }
    }
    
    //arrays
    time_t timer;
    struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);//get current time:sec,min,hour
    
    //array_hour
    float hour_d=tblock->tm_hour;
    float hour_r=hour_d*30*(PI/180);
    
    glColor3f(GREEN);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius/3*sin(hour_r), radius/3*cos(hour_r));
    glEnd();
    glFlush();
    
    
    //array_min
    float min_d=tblock->tm_min;
    float min_r=min_d*6*(PI/180);
    
    glColor3f(YELLOW);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius/1.5*sin(min_r), radius/1.5*cos(min_r));
    glEnd();
    glFlush();
    
    
    //array_sec
    float sec_d=tblock->tm_sec;//sec in degree
    float sec_r=sec_d*6*(PI/180);//sec in radius
    
    glColor3f(RED);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(xf, yf);
    glVertex2f(radius*sin(sec_r), radius*cos(sec_r));
    glEnd();
    glFlush();
    
    
    
    //printf("%f,%f,%f\n",sec_d,min_d,hour_d);
    
    
    //inner layor
    glColor3f(WHITE);
    glBegin(GL_POLYGON);
    for (int i=0; i<N; i++) {
        x[i]=radius/15*cos(2*i*PI/N)+xf;
        y[i]=radius/15*sin(2*i*PI/N)+yf;
        glVertex2f(x[i], y[i]);
    }
    glEnd();
    glFlush();
    
    

	//printf("%d\n",tblock->tm_isdst);

    display_date(-2.3, -4.5, 1);
    
    
    
    display_FPS();
}

int ten_digit(int fig)
{
    int ten;
    ten=fig/10;
    return ten;
}

int one_digit(int fig)
{
    int one;
    one=fig-10*ten_digit(fig);
    return one;
}


void display_date(float x,float y,float fs)
{
    
    time_t timer;
    struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);//get current time:sec,min,hour
    
    
    
    
    
    
    prints("TZ:", x, y, 1);
    x=x+0.5;
#ifdef __APPLE__
	prints(tblock->tm_zone, x, y, 1);
#endif
    
#ifdef __linux__
    prints(tblock->__tm_zone, x, y, 1);
#endif
    
#ifdef __WIN32__
    prints("ERROR", x, y, 1);
#endif
	
    
    

    
    x=x+1;
    
    prints("20", x, y, 1);
    x=x+0.3;
    printc(ten_digit(tblock->tm_year-100)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_year-100)+48, x, y, 1);
    x=x+0.15;
    
    prints("-", x, y, 1);
    x=x+0.15;
    printc(ten_digit(tblock->tm_mon)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_mon)+48, x, y, 1);
    x=x+0.15;
    
    prints("-", x, y, 1);
    x=x+0.15;
    printc(ten_digit(tblock->tm_mday)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_mday)+48, x, y, 1);
    x=x+0.45;
    
    printc(ten_digit(tblock->tm_hour)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_hour)+48, x, y, 1);
    x=x+0.15;
    
    prints(":", x, y, 1);
    x=x+0.15;
    printc(ten_digit(tblock->tm_min)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_min)+48, x, y, 1);
    x=x+0.15;
    
    prints(":", x, y, 1);
    x=x+0.15;
    printc(ten_digit(tblock->tm_sec)+48, x, y, 1);
    x=x+0.15;
    printc(one_digit(tblock->tm_sec)+48, x, y, 1);
}
