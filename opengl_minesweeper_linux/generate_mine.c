//
//  generate_mine.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "define_data.h"
#include <time.h>
#define random(x) (rand()%x)

void generate_board()
{
    
    //generate display_board
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (data_board[i][j]==0) {
                display_board[i][j]='-';
            }
            else if (data_board[i][j]==-1)
                display_board[i][j]='X';
        }
    }
    
    //generate value_board

    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (data_board[i][j]==-1) {
                value_board[i][j]=-1;
                if (value_board[i+1][j]>=0) {
                    value_board[i+1][j]++;
                }
                if (value_board[i-1][j]>=0) {
                    value_board[i-1][j]++;
                }
                if (value_board[i][j+1]>=0) {
                    value_board[i][j+1]++;
                }
                if (value_board[i][j-1]>=0) {
                    value_board[i][j-1]++;
                }
                if (value_board[i+1][j+1]>=0) {
                    value_board[i+1][j+1]++;
                }
                if (value_board[i+1][j-1]>=0) {
                    value_board[i+1][j-1]++;
                }
                if (value_board[i-1][j+1]>=0) {
                    value_board[i-1][j+1]++;
                }
                if (value_board[i-1][j-1]>=0) {
                    value_board[i-1][j-1]++;
                }
                
            }
            
        }
    }
        

    
}

// generate data_board
void generate_mine(int mine_number)
{
    int x,y;
    srand((int)time(0));
    for (int i=0; i<mine_number; i++) {
        x=random(BOARD_SIZE);
        x_mine[i]=x;
        y=random(BOARD_SIZE);
        y_mine[i]=y;
        if (data_board[x][y]!=MINE) {
            data_board[x][y]=MINE;
        }
        else
            i--;
    }
}

