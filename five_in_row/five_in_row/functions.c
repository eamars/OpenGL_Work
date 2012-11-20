//
//  functions.c
//  five_in_row
//
//  Created by eamars on 12-7-15.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#include <stdio.h>
#include "define.h"
#include <stdlib.h>

char welcome()
{
    printf("\n\nWelcome to my 'Five in Row' games!\n\n");
    printf("Press 1 to play with computer\n");
    printf("Press 2 to play with your friends\n");
    printf("Your choice:");
    char choice;
    choice=getchar();
    return choice;
}

void print_board(int switcher)
{
    printf("\n");
    //init coordinate_x-y
    for (int i=0; i<BOARD_SIZE; i++) {
        coordinate_x[i]=i;
        coordinate_y[i]=i;
    }
    
    //print coordinate x
    if (switcher==1) {
        printf("i ");
        for (int i=0; i<BOARD_SIZE; i++) {
            printf("%2d",coordinate_x[i]);
        }
        printf("\n");
    }
    //finish
    
    
    
    for (int i=0; i<BOARD_SIZE; i++)
    {
        
        for (int j=0; j<BOARD_SIZE; j++)
        {
            //print coordinate y
            if (switcher==1) {
                if (j==0)
                {
                    if (coordinate_y[i]<10) {
                        printf("%d ",coordinate_y[i]);
                    }
                    else
                        printf("%d",coordinate_y[i]);
                }
                //finish
            }
            printf("%2c",board[i][j]);
        }
        printf("\n");
    }
    
}

void init_board(char default_char)
{
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j]=default_char;
        }
    }
    count_black=0;
    count_white=0;
    
}

void steps(int x,int y,char side)
{
    if (side=='b') {
        board[x][y]='X';
    }
    
    if (side=='w') {
        board[x][y]='O';
    }
    
}


int win_check_general(int x_axis,int y_axis,int side)
{
    int win_status = 0;
    int N=1,NE=1,E=1,SE=1,S=1,SW=1,W=1,NW=1;
    
    //N
    for (N=1; board[x_axis+N][y_axis]==board[x_axis][y_axis]; N++) {
    }
    
    //S
    for (S=1; board[x_axis-S][y_axis]==board[x_axis][y_axis]; S++) {
    }
    
    //N+S
    if ((N+S)==6) {
        win_status=side;
    }
    
    
    //E
    for (E=1; board[x_axis][y_axis-E]==board[x_axis][y_axis]; E++) {
    }
    
    //W
    for (W=1; board[x_axis][y_axis+W]==board[x_axis][y_axis]; W++) {
    }
    
    //E+W
    if ((E+W)==6) {
        win_status=side;
    }
    
    //NE
    for (NE=1; board[x_axis+NE][y_axis-NE]==board[x_axis][y_axis]; NE++) {
    }
    
    //SW
    for (SW=1; board[x_axis-SW][y_axis+SW]==board[x_axis][y_axis]; SW++) {
    }
    
    //SW+NE
    if ((SW+NE)==6) {
        win_status=side;
    }
    
    //SE
    for (SE=1; board[x_axis-SE][y_axis-SE]==board[x_axis][y_axis]; SE++) {    }
    
    //NW
    for (NW=1; board[x_axis+NW][y_axis+NW]==board[x_axis][y_axis]; NW++) {
    }
    
    //SE+NW
    if ((SE+NW)==6) {
        win_status=side;
    }
    //printf("%d %d %d %d %d %d %d %d \n",N,NE,E,SE,S,SW,W,NW);
    return win_status;

}

//unfinished

void undo_steps(int x_axis,int y_axis,int side_count)
{
    board[history_x[side_count-1]][history_y[side_count-1]]=blank_board;
}

void record_history(int x_axis,int y_axis,int side_count)
{
    history_x[side_count]=x_axis;
    history_y[side_count]=y_axis;

}


