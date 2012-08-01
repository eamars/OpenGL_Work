//
//  mouse.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "define_data.h"
#include <GL/glut.h>
#include <stdlib.h>

int turns=2;
char side='b';
char blank_board='-';
int win=0;

void MouseAction(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            //Left Button code.
            //Place piece
            float xf,yf;
            xf=(float)x/50+0.5;
            yf=(float)y/50+0.5;
            
            
            // black and white take turns
            
            
            if (board[(int)yf][(int)xf]==blank_board) {
                piece_GL(side, (int)xf, (int)yf);
                steps((int)yf, (int)xf, side);
                if(turns%2==0)
                {
                    side='w';
                }
                else
                    side='b';
                turns++;
            }
            
            win=win_check_general((int)yf, (int)xf, side);
            
            
            
            if (win!=0) {
                if (win==1) {
                    printf("\n[Black wins]\n");
                    print_board(1);
                    glutPassiveMotionFunc(MousePassingEndFrame);
                    glutMouseFunc(MouseClickEndFrame);
                    
                }
                else if (win==-1)
                {
                    printf("\n[White wins]\n");
                    print_board(1);
                    glutPassiveMotionFunc(MousePassingEndFrame);
                    glutMouseFunc(MouseClickEndFrame);
                    
                }
            }
            

            
        }
        else if(button == GLUT_MIDDLE_BUTTON)
        {
            //middle button code
            print_board(1);
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            //right button code
            //get current axis
            
            float xf,yf;
            xf=(float)x/50+0.5;
            yf=(float)y/50+0.5;
            printf("board axis:x=%d,y=%d\n",(int)xf,(int)yf);
        }
    }
    else
    {
        //alternate code
    }
}



void MouseClickEndFrame(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN && x>((int)COEI)*100*0.2&&x<((int)COEI)*100*0.8&&y>((int)COEI)*100*0.4&&y<((int)COEI)*100*0.6)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            exit(0);
            print_board(1);
        }
        if (button == GLUT_RIGHT_BUTTON) {
            exit(0);
            print_board(1);
        }
        
    }
    
}
void MousePassingEndFrame(int x,int y)
{
    if(x>((int)COEI)*100*0.2&&x<((int)COEI)*100*0.8&&y>((int)COEI)*100*0.4&&y<((int)COEI)*100*0.6)
    {
        glColor4f(1, 0, 0, 0.5);
        glBegin(GL_POLYGON);
        glVertex2d(0.2, 0.4);
        glVertex2d(0.2, 0.6);
        glVertex2d(0.8, 0.6);
        glVertex2d(0.8, 0.4);
        glEnd();
        
        //out line
        glLineWidth(3);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(2, 0x0F0F);
        glColor3f(1, 1, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(0.2, 0.4);
        glVertex2d(0.2, 0.6);
        glVertex2d(0.8, 0.6);
        glVertex2d(0.8, 0.4);
        glEnd();
        glFlush();
        YOU_WIN(0.32, 0.51, 1);
    }
    else
    {
        glColor4f(0, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2d(0.2, 0.4);
        glVertex2d(0.2, 0.6);
        glVertex2d(0.8, 0.6);
        glVertex2d(0.8, 0.4);
        glEnd();
        
        //out line
        glLineWidth(3);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(2, 0x0F0F);
        glColor3f(1, 1, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(0.2, 0.4);
        glVertex2d(0.2, 0.6);
        glVertex2d(0.8, 0.6);
        glVertex2d(0.8, 0.4);
        glEnd();
        glFlush();
    }
    

}

