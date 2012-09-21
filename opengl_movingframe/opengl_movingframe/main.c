//
//  main.c
//  opengl_movingframe
//
//  Created by eamars on 20/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "define_UI.h"


void init(void)
{
    /* clearing background */
    glClearColor(0.0,0.0,0.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,20.0,0.0,10.0,-1.0,1.0);
    glLineWidth(1.0f);//default line width =1
}

int main(int argc,char **argv)
{
    //settings
    
    /*
	printf("type horizontal velocity\nvx=");
    scanf("%f",&vx);
    printf("type vertical velocity\nvy=");
    scanf("%f",&vy);
    
    
    printf("Ready to simulate..\n");
	printf("3...\n");
    usleep(1000000);
    printf("2...\n");
    usleep(1000000);
    printf("1...\n");
    usleep(1000000);
    printf("Start to simulate..\n");
     */
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(200,50);
    glutCreateWindow("Projectile motion");
    init();
    glutDisplayFunc(startup);
	glutMouseFunc(MouseAction);
    glutMainLoop();
    return 0;
}

