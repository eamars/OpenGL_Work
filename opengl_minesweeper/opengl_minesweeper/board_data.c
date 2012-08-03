//
//  board_data.c
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"

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
            printf("%2d",value_board[i][j]);
        }
        printf("\n");
    }
    
}


void init_board()
{
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            data_board[i][j]=0;
            display_board[i][j]='-';
            value_board[i][j]=0;
            
        }
    }
}

