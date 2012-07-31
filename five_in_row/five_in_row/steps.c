//
//  black_steps.c
//  five_in_row
//
//  Created by eamars on 12-7-16.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#include <stdio.h>
#include "define.h"

void black_turn()
{
    int x_axis,y_axis;
    /*check the point if valid
     if no, input again
     */
    do {
        printf("[black step](%d)\n=",count_black);//player count
        scanf("%d,%d",&x_axis,&y_axis);
        
        //undo
        history_b_x[count_black]=x_axis;
        history_b_y[count_black]=y_axis;
        if ((x_axis==-1)&&(y_axis=-1)) {
            board[history_b_x[count_black-1]][history_b_y[count_black-1]]=blank_board;
            //debug
            //printf("last step x=%d y=%d\n",history_b_x[count_black-1],history_b_y[count_black-1]);
            print_board(1);
        }
        //undo finish
        
        else if (board[x_axis][y_axis]!=blank_board) {
            printf("invalid coordinate,try again!\n");
        }
        
                
    } while (board[x_axis][y_axis]!=blank_board);
    
    count_black++;//black count 1
    steps(x_axis, y_axis,'b');
    
    //double check incase bugs
    win=win_check_general(x_axis, y_axis,1);//check if black wins
    //win=win_check(x_axis, y_axis,1);//check if black wins
}

void white_turn()
{
    int x_axis,y_axis;
    /*check the point if valid
     if no, input again
     */
    do {
        printf("[white step](%d)\n=",count_white);//player count
        scanf("%d,%d",&x_axis,&y_axis);
        
        
        //undo
        history_w_x[count_white]=x_axis;
        history_w_y[count_white]=y_axis;
        if ((x_axis==-1)&&(y_axis=-1)) {
            board[history_w_x[count_white-1]][history_w_y[count_white-1]]=blank_board;
            //debug
            //printf("last step x=%d y=%d\n",history_w_x[count_white-1],history_w_y[count_white-1]);
            print_board(1);
        }
        //undo finish
        
        else if (board[x_axis][y_axis]!=blank_board) {
            printf("invalid coordinate,try again!\n");
        }
    } while (board[x_axis][y_axis]!=blank_board);
    
    count_white++;//white count 1
    steps(x_axis, y_axis,'w');
    
    //double check in case bugs
    win=win_check_general(x_axis, y_axis,-1);//check if white wins
    //win=win_check(x_axis, y_axis,-1);//check if white wins
}

void ai_turn_black()
{
    
    steps(ana_x(), ana_y(),'b');
    
    //double check incase bugs
    win=win_check_general(ana_x(), ana_y(),1);//check if black wins
    //win=win_check(x_axis, y_axis,1);//check if black wins
}

void ai_turn_white()
{
    
    
    steps(ana_x(), ana_y(),'w');
    
    //double check in case bugs
    win=win_check_general(ana_x(), ana_y(),-1);//check if white wins
    //win=win_check(x_axis, y_axis,-1);//check if white wins
    
}