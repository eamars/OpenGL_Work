//
//  main.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"
#include "define_UI.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char **argv)
{
    init_board();
    set_mine=0;
    generate_mine(MINE_NO);
    generate_board();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(((int)FRAMEWORK)*100,((int)FRAMEWORK)*100);
    glutInitWindowPosition(100,100);
    
    glutCreateWindow("Mine Sweeper.Build 1.10");
    init();
    glutDisplayFunc(Mine_sweeper);
    
    /*
    glutInitWindowSize(100,100);
    glutInitWindowPosition(730,100);
    glutCreateWindow("Remaining mines");
    glutDisplayFunc(remain_framework);
     */
    glutMainLoop();
     
    return 0;
}

