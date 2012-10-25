//
//  functions.h
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_Oscilloscope_functions_h
#define opengl_Oscilloscope_functions_h
#define PREC 10000
#include "define.h"
float floattime;
long inttime;
void initfunc(void);
void printFunc(void);
void testfunc(float);
void testfunc2(long);
void displaytime(long);
void displayPercentage(long);
void printLinkLine(void);

struct type_points {
    float x;
    float y;
};

struct type_points points[PREC];


#endif
