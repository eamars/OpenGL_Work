//
//  main.c
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
#include "define_data.h"

void init(void)
{
    /* clearing background */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,8,0.0,4.8,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
    /* AA */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
}

int main(int argc, char **argv)
{
    
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,480);
    glutInitWindowPosition(100,0);
    glutCreateWindow("Text Editor");
    init();
    init_data();
    glutDisplayFunc(model1);
    glutMainLoop();
    return 0;
}

