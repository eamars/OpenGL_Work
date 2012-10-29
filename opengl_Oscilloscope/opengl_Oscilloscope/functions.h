//
//  functions.h
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_Oscilloscope_functions_h
#define opengl_Oscilloscope_functions_h
#define PREC 1500
#define AMP 4
#include "define.h"


void initfunc(void);
void printSepPoint(void);
void printWavdata();
void testfunc(float);
void testfunc2(long);
void displaytime(long);
void displayPercentage(long);
void printChannels();
void printLinkLine(void);
void printSettings();

struct type_points {
    float x;
    float y;
};

struct type_points L_points[PREC];
struct type_points R_points[PREC];

#endif
