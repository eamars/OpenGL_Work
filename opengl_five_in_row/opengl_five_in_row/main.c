//
//  main.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_board_opengl.h"
#include <GLUT/glut.h>

float scale_each=0.5/COEI;

int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(((int)COEI)*100,((int)COEI)*100);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Gomoku");
    init();
    
    glutDisplayFunc(model1);

    glutMouseFunc(MouseAction);
    
    glutMainLoop();
    
    
    
    return 0;
}
