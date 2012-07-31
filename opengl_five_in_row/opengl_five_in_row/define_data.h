//
//  define_data.h
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_five_in_row_define_data_h
#define opengl_five_in_row_define_data_h

#define BOARD_SIZE 13



char board[BOARD_SIZE][BOARD_SIZE];

int coordinate_x[BOARD_SIZE];
int coordinate_y[BOARD_SIZE];



//print out the current board
/*
 1 to turn on coordinate
 0 to turn off coordinate
 */
void print_board(int);

//initialize the board
/* input anything to display the blank board
 */
void init_board(char);

//steps
void steps(int,int,char);//do the step

//Win check
int win_check_general(int,int,char);//general method to check if win >>win_check.c


#endif
