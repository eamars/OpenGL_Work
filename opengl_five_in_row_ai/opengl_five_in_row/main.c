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



float scale_each=0.5/COEI;

int main(int argc,char **argv)
{
    
    init_board('-');
    //startup
    
    printf("\n\nWelcome to my 'Five in Row' games!\n\n");
    printf("Press 1 to play with computer\n");
    printf("Press 2 to play with your friends\n");
    printf("Your choice:");
    char choice;//default for mode1: player vs ai
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
    else
        mode=1;
    
    //printf("mode=%d\n",mode);
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(((int)COEI)*100,((int)COEI)*100);
    glutInitWindowPosition(10,10);
    if (mode==1) {
        glutCreateWindow("Gomoku Challenge");
    }
    else if (mode==2){
        glutCreateWindow("Gomoku Duel");
    }
    else if (mode==3){
        glutCreateWindow("Gomoku AI Versus");
    }
    else
        glutCreateWindow("Gomoku Challenge");
    
    init();
    glutDisplayFunc(model1);
    glutMouseFunc(MouseAction);
    glutMainLoop();

    return 0;
}
