//
//  define_UI.h
//  opengl_movingframe
//
//  Created by eamars on 21/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_movingframe_define_UI_h
#define opengl_movingframe_define_UI_h


#ifdef __WIN32__
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.1415926
#define N 80
#define G 9.8

#define RED 1,0,0
#define GREEN 0,1,0
#define BLUE 0,0,1
#define YELLOW 1,1,0
#define WHITE 1,1,1
#define PURPLE 1,0,1
#define CYAN 0,1,1
#define BLACK 0,0,0


float vx,vy;

void startup();
void particle(float,float,float);
void function();
void Idle_graph();

float gravity(float);
float displacement_x(float);
float displacement_y(float);
void trace();
void Asymptote(float,float);

void printc(char,float,float,float);// --> print_font.c
void prints(const char str[],float,float,float);// --> print_font.c
void display_FPS(float,float);
void display_time(float,float,float);
void display_value(float,float,float,float,float,float);

void MouseAction(int,int,int,int);
void MouseLocation(int,int);

#endif
