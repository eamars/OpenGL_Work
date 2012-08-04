//
//  define_data.h
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_minesweeper_define_data_h
#define opengl_minesweeper_define_data_h


#define BOARD_SIZE 12

#define MINE_NO 20
#define NON_MINE 0
#define MINE -1


/* board control start */
int coordinate_x[BOARD_SIZE];
int coordinate_y[BOARD_SIZE];
char display_board[BOARD_SIZE][BOARD_SIZE];
int data_board[BOARD_SIZE][BOARD_SIZE];
int value_board[BOARD_SIZE][BOARD_SIZE+1];//prevent to loop to next line

//print out the current board
/*
 1 to turn on coordinate
 0 to turn off coordinate
 */
void print_board(int);

//initialize the board
/* input anything to display the blank board
 */
void init_board();
void generate_board();



/* board control finish*/


/* data control start */

void generate_mine(int);//generate mine and place on the board

int x_mine[MINE_NO];
int y_mine[MINE_NO];
#endif
