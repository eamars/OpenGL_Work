//
//  main.c
//  opengl_Oscilloscope
//
//  Created by eamars on 13/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "define.h"


void init(void)
{
    /* clearing background */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(BLACK,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* x -5,5
    y -4,4
    z -1,1
     */
    glOrtho(-5.0,5.0,-5.0,5.0,-1.0,1.0);
    /* AA */
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
}



int main(int argc, char **argv)
{
    if (!readfromWave()) {
        printf("Failed to read,exit\n");
        exit(0);
    }
    
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(501,501);
    glutInitWindowPosition(200,0);
    glutCreateWindow("Oscilloscope Build v1.01");
    init();
    glutDisplayFunc(scope);
    glutMainLoop();
     
    return 0;
}



