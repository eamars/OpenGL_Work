//
//  main.c
//  opengl_monopoly
//
//  Created by eamars on 27/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "dice.h"
#include "board.h"

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
	/*
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(700,10);
    glutCreateWindow("Monopoly");
    init();
    glutDisplayFunc(board1);
    glutMainLoop();
	*/
    
    board1();
    return 0;
}

