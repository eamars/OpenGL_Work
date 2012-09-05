//
//  main.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "define_data.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float scale_each=0.5/COEI;

int main(int argc,char **argv)
{
    
    init_board('-');
    //startup
    printf("\n\nWelcome to my 'Five in Row' games!\n\n");
    printf("Press 1 to play with computer\n");
    printf("Press 2 to play with your friends\n");
    printf("Your choice:");
    char choice;
    choice=getchar();
    if (choice=='1') {
        mode=1;
    }
    else if (choice=='2')
    {
        mode=2;
    }
    else if (choice=='3')
    {
        mode=3;
    }
    
    //printf("mode=%d\n",mode);
    
    
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
