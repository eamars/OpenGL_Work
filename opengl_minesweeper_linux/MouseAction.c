//
//  MouseAction.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "define_UI.h"
#include "define_data.h"
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

int win_condition[MINE_NO];



void MouseClick(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            float xf,yf;
            xf=(float)x/100*BOARD_SIZE/FRAMEWORK;
            yf=(float)y/100*BOARD_SIZE/FRAMEWORK;
            
            if (value_board[(int)yf][(int)xf]==-1) {
                printf("You Lose!\n");
                for (int i=0; i<BOARD_SIZE; i++) {
                    for (int j=0; j<BOARD_SIZE; j++) {
                        if (value_board[j][i]==-1) {
                            Piece_With_number(i, j+1, -1);
                        }
                    }
                }
                Piece_With_number((int)xf, (int)yf+1, -1);
                End_frame(0);
                glutMouseFunc(MouseClickEndFrame);
            }
            else if (value_board[(int)yf][(int)xf]!=-1)
            {
                Piece_With_number((int)xf, (int)yf+1, value_board[(int)yf][(int)xf]);
            }
            
                
            
        }
        if (button == GLUT_RIGHT_BUTTON) {
            float xf,yf;
            xf=(float)x/100*BOARD_SIZE/FRAMEWORK;
            yf=(float)y/100*BOARD_SIZE/FRAMEWORK;
            
            Piece_With_number((int)xf, (int)yf+1, -2);
            
            for (int i=0; i<MINE_NO; i++) {
                if (x_mine[i]==(int)yf && y_mine[i]==(int)xf) {
                    win_condition[i]=1;
                }
            }
            
            int win_state=0;
            for (int i=0; i<MINE_NO; i++) {
                win_state=win_condition[i]+win_state;
                if (win_state==MINE_NO) {
                    
                    printf("You Win!\n");
                    End_frame(1);
                    glutMouseFunc(MouseClickEndFrame);
                }
            }
            
        }
        else if(button == GLUT_MIDDLE_BUTTON)
        {
            //middle button code

            print_board(1);
        }
    }
}

void MouseClickEndFrame(int button, int state, int x, int y)
{
    float xf,yf;
    xf=(float)x/100*BOARD_SIZE/FRAMEWORK;
    yf=(float)y/100*BOARD_SIZE/FRAMEWORK;
    
    if(state == GLUT_DOWN && (float)x/100>FRAMEWORK*0.2&&(float)x/100<FRAMEWORK*0.8&&(float)y/100>FRAMEWORK*0.4&&(float)y/100<FRAMEWORK*0.6)
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



void MouseClickStartFrame(int button, int state, int x, int y)
{
    printf("x=%d y=%d\n",x,y);
    if(state == GLUT_DOWN && (float)x/100>FRAMEWORK*0.2&&(float)x/100<FRAMEWORK*0.8&&(float)y/100>FRAMEWORK*0.8&&(float)y/100<FRAMEWORK*0.9)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            
            /* clearing background */
            glClear (GL_COLOR_BUFFER_BIT);
            glClearColor(0.0,0.0,0.0,0.0);
            //hard
            Mine_sweeper();
        }

    }
    else if(state == GLUT_DOWN && (float)x/100>FRAMEWORK*0.2&&(float)x/100<FRAMEWORK*0.8&&(float)y/100>FRAMEWORK*0.6&&(float)y/100<FRAMEWORK*0.7)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            
            /* clearing background */
            glClear (GL_COLOR_BUFFER_BIT);
            glClearColor(0.0,0.0,0.0,0.0);
            //moderate
            Mine_sweeper();
        }
        
    }
    else if(state == GLUT_DOWN && (float)x/100>FRAMEWORK*0.2&&(float)x/100<FRAMEWORK*0.8&&(float)y/100>FRAMEWORK*0.4&&(float)y/100<FRAMEWORK*0.5)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            
            /* clearing background */
            glClear (GL_COLOR_BUFFER_BIT);
            glClearColor(0.0,0.0,0.0,0.0);
            //simple
            Mine_sweeper();
        }
        
    }


}
void MousePassStartFrame(int x,int y)
{
    
}
