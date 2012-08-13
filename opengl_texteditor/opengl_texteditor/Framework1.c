//
//  Framework1.c
//  opengl_texteditor
//
//  Created by eamars on 12/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "define_graph.h"

void model1()
{
	glutSwapBuffers();
    glColor3f(1, 1, 1);
    printc('_', 0.1, 4.7, 0.5);
    dislplayinfo(0, 0);
    prints("ver_alpha", 7.2, 0.13, 0.5);
    glutKeyboardFunc(KeyBoard);
    glutSpecialFunc(SpecialKey);
}

void dislplayinfo(int line,int col)
{
    float xf=0.01;
    float yf=0.13;
    float fs=0.5;
    
    int ten_line=line/10;
    int one_line=line-10*ten_line;
    
    int ten_col=col/10;
    int one_col=col-10*ten_col;
    /*
    char LINE[]="Line = ";
    for (int i=0; i<sizeof(LINE)-1; i++) {
        glColor3f(1, 1, 1);
        printc(LINE[i], xf, yf, fs);
        xf=xf+0.08;
    
    }
     */
    glColor3f(1, 1, 1);
    prints("Line=", xf, yf, fs);
    xf=xf+0.08*5;
    //clear history
    glColor3f(0, 0, 0);
    printc('\000', xf, yf, fs);
    
    glColor3f(1, 1, 1);
    if (ten_line!=0) {
        printc(ten_line+48, xf, yf, fs);
    }
    
    xf=xf+0.08;
    
    //clear history
    glColor3f(0, 0, 0);
    printc('\000', xf, yf, fs);
    
    glColor3f(1, 1, 1);
    printc(one_line+48, xf, yf, fs);
    
    
    xf=xf+0.08*4;
    
    /*
    char COL[]="Column=";
    for (int i=0; i<sizeof(COL)-1; i++) {

        glColor3f(1, 1, 1);
        printc(COL[i], xf, yf, fs);
        xf=xf+0.08;
    }
     */
    glColor3f(1, 1, 1);
    prints("Column=", xf, yf, fs);
    xf=xf+0.08*7;
    //clear history
    glColor3f(0, 0, 0);
    printc('\000', xf, yf, fs);
    
    glColor3f(1, 1, 1);
    if (ten_col!=0) {
        printc(ten_col+48, xf, yf, fs);
    }
    
    xf=xf+0.08;
    
    //clear history
    glColor3f(0, 0, 0);
    printc('\000', xf, yf, fs);
    
    glColor3f(1, 1, 1);
    printc(one_col+48, xf, yf, fs);
	
    
}