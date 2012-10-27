//
//  define.h
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_Oscilloscope_define_h
#define opengl_Oscilloscope_define_h
// opengl
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

//fps
void display_FPS();
double CalFrequency();

//color
#define RED 1,0,0
#define GREEN 0,1,0
#define BLUE 0,0,1
#define YELLOW 1,1,0
#define WHITE 1,1,1
#define PURPLE 1,0,1
#define CYAN 0,1,1
#define BLACK 0,0,0
#define GREY 0.618,0.618,0.618
#define Oscilloscope_GREEN 0.518,0.969,0.678

typedef unsigned char uint8; //1
typedef unsigned short uint16; //2
typedef unsigned int uint32; //4
typedef unsigned long uint64; //8
typedef char int8;
typedef short int16;

#include "font.h"
#include "screen.h"
#include "functions.h"
#include "file.h"
#endif
