//
//  define_board_opengl.h
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_five_in_row_define_board_opengl_h
#define opengl_five_in_row_define_board_opengl_h
#define COEI 7.0

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif



void grid();
void init();
void print_board_UI();
void model1();
void startup();


void MousePassingEndFrame(int,int);
void MouseClickStartFrame(int,int,int,int);
void MouseClickEndFrame(int,int,int,int);
void MouseAction(int,int,int,int);
void piece_GL(char,int,int);




void printc(char,float,float,float);// --> print_font.c
void prints(const char str[],float,float,float,float);// --> print_font.c
#endif

