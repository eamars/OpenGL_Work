//
//  ai_brain.c
//  opengl_five_in_row
//
//  Created by eamars on 5/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"
#include "define_UI.h"

/* the following are for ai use*/
int ai_turn_white()
{
    int win=0;
    int x_axis,y_axis;
    x_axis=ana_x();
    y_axis=ana_y();
    
    
    steps(x_axis, y_axis, 'w');
    piece_GL('w', y_axis, x_axis);
    
    win=win_check_general(x_axis, y_axis, 'w');
    //printf("win=%d\n",win);
	return win;
    
}

int ai_turn_black()
{
    int win=0;
    int x_axis,y_axis;
    x_axis=ana_x();
    y_axis=ana_y();
    
    
    steps(x_axis, y_axis, 'b');
    piece_GL('b', y_axis, x_axis);
    
    win=win_check_general(x_axis, y_axis, 'b');
    //printf("win=%d\n",win);
	return win;
    
}

/* My method to get marks*/

int get_length(int x_axis,int y_axis,char side_before)
{
    blank_board='-';
    char side;
    int total_mark=0;
    int N=1,NE=1,E=1,SE=1,S=1,SW=1,W=1,NW=1;
    int NpS,EpW,SWpNE,SEpNW;
    
    //convert side to board data
    if (side_before=='b') {
        side='X';
    }
    if (side_before=='w') {
        side='O';
    }
    
    //N
    for (N=1; board[x_axis+N][y_axis]==side; N++) {
        if (board[x_axis+N][y_axis]!=side) {
            break;
        }
    }
    
    //S
    for (S=1; board[x_axis-S][y_axis]==side; S++) {
        if (board[x_axis-S][y_axis]!=side) {
            break;
        }
    }
    
    //N+S
    NpS=N+S-1;
    
    
    //E
    for (E=1; board[x_axis][y_axis-E]==side; E++) {
        if (board[x_axis][y_axis-E]!=side) {
            break;
        }
    }
    
    //W
    for (W=1; board[x_axis][y_axis+W]==side; W++) {
        if (board[x_axis][y_axis+W]!=side) {
            break;
        }
    }
    
    //E+W
    EpW=E+W-1;
    
    //NE
    for (NE=1; board[x_axis+NE][y_axis-NE]==side; NE++) {
        if (board[x_axis+NE][y_axis-NE]!=side) {
            break;
        }
    }
    
    //SW
    for (SW=1; board[x_axis-SW][y_axis+SW]==side; SW++) {
        if (board[x_axis-SW][y_axis+SW]!=side) {
            break;
        }
    }
    
    //SW+NE
    SWpNE=SW+NE-1;
    
    //SE
    for (SE=1; board[x_axis-SE][y_axis-SE]==side; SE++) {
        if (board[x_axis-SE][y_axis-SE]!=side) {
            break;
        }
    }
    
    //NW
    for (NW=1; board[x_axis+NW][y_axis+NW]==side; NW++) {
        if (board[x_axis+NW][y_axis+NW]!=side) {
            break;
        }
    }
    
    //SE+NW
    SEpNW=SE+NW-1;
    
    //mark
    total_mark=mark(NpS)+mark(EpW)+mark(SWpNE)+mark(SEpNW);
    
    
	//printf("NpS=%d EpW=%d SWpNE=%d SEpNW=%d \n",NpS,EpW,SWpNE,SEpNW);
    //printf("MarkforCurrentStep=%d\n",total_mark);
    
    return total_mark;
}

int mark(int length)
{
    int mark_value;
    if (length==0) {
        mark_value=0;
    }
    else if (length==1) {
        mark_value=1;
    }
    else if (length==2) {
        mark_value=10;
    }
    else if (length==3) {
        mark_value=100;
    }
    else if (length==4) {
        mark_value=1000;
    }
    else if (length==5) {
        mark_value=10000;
    }
    else
        mark_value=0;
    
    return mark_value;
}

int ana_x()
{
    int x;
    int max=0,buff;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            buff=get_length(i, j,'w')+get_length(i, j, 'b');
            if (buff>max && buff>max && board[i][j]==blank_board) {
                
                max=buff;
                x=i;
            }
        }
    }
    
    return x;
}

int ana_y()
{
    
    int y;
    int max=0,buff;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            buff=get_length(i, j,'w')+get_length(i, j, 'b');
            if (buff>max && board[i][j]==blank_board) {
                max=buff;
                y=j;
            }
        }
    }
    
    return y;
}
