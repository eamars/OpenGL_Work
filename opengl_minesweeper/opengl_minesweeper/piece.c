//
//  piece.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "define_data.h"
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

void Blind_piece()
{
    // blind pieces
    // from down left
    glColor3f(0, 1, 1);
    for (float i=0; i<FRAMEWORK; i=i+FRAMEWORK/BOARD_SIZE) {
        for (float j=0; j<FRAMEWORK; j=j+FRAMEWORK/BOARD_SIZE) {
            glBegin(GL_POLYGON);
            glVertex2f(i+FRAMEWORK/120, j+FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/120, j+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, j+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, j+FRAMEWORK/120);
            glEnd();
        }
    }
    // outer line
    glLineWidth(1);
    glColor3f(0, 0.7193, 1);
    for (float i=0; i<FRAMEWORK; i=i+FRAMEWORK/BOARD_SIZE) {
        for (float j=0; j<FRAMEWORK; j=j+FRAMEWORK/BOARD_SIZE) {
            glBegin(GL_LINE_LOOP);
            glVertex2f(i+FRAMEWORK/120, j+FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/120, j+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, j+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120);
            glVertex2f(i+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, j+FRAMEWORK/120);
            glEnd();
        }
    }
    
    glFlush();
}



void Piece_With_number(float x,float y,int number)
{
    x=x*FRAMEWORK/BOARD_SIZE;
    y=(BOARD_SIZE+1-y)*FRAMEWORK/BOARD_SIZE;
    if (number!=-1) {
        glColor3f(0, 0, 0);
    }
    else
        glColor3f(1, 0, 0);
    
    //from upper left
    glBegin(GL_POLYGON);
    glVertex2f(x+FRAMEWORK/120, y-FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, y-FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, y-FRAMEWORK/BOARD_SIZE+FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/120, y-FRAMEWORK/BOARD_SIZE+FRAMEWORK/120);
    glEnd();
    
    //outer line
    if (number!=-1) {
        glColor3f(0, 0.7193, 1);
    }
    else
        glColor3f(1, 1, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x+FRAMEWORK/120, y-FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, y-FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/BOARD_SIZE-FRAMEWORK/120, y-FRAMEWORK/BOARD_SIZE+FRAMEWORK/120);
    glVertex2f(x+FRAMEWORK/120, y-FRAMEWORK/BOARD_SIZE+FRAMEWORK/120);
    glEnd();
    glFlush();
    if (number!=0) {
        NumberSet(number, x+BOARD_SIZE/65.0, y-BOARD_SIZE/72.0, BOARD_SIZE*-2+28);
    }
    
    
    
    
}