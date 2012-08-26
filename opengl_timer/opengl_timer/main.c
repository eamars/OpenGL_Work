//
//  main.c
//  opengl_timer
//
//  Created by eamars on 24/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_graph.h"

void init(void)
{
    /* clearing background */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0,5.0,-5.0,5.0,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
}

int main(int argc, char **argv)
{
    
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,0);
    glutCreateWindow("Clock _build_beta");
    init();
    glutDisplayFunc(timer1);
    glutIdleFunc(timecheck);
    glutMainLoop();
    return 0;
}


