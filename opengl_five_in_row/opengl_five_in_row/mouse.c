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
#include <GLUT/glut.h>
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
                    exit(0);
                }
                else if (win==-1)
                {
                    printf("\n[White wins]\n");
                    exit(0);
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

