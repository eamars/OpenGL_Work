//
//  define_graph.h
//  opengl_timer
//
//  Created by eamars on 24/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_timer_define_graph_h
#define opengl_timer_define_graph_h

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#define RED 1,0,0
#define GREEN 0,1,0
#define BLUE 0,0,1
#define YELLOW 1,1,0
#define WHITE 1,1,1
#define PURPLE 1,0,1
#define CYAN 0,1,1
#define BLACK 0,0,0




void printc(char,float,float,float);// --> print_font.c
void prints(const char str[],float,float,float);// --> print_font.c
int ten_digit(int);
int one_digit(int);

void timer1();
void clock1(float,float,float);
void display_FPS();
void display_date(float,float,float);
void timecheck();

#endif
