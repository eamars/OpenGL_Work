//
//  define_data.h
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_five_in_row_define_data_h
#define opengl_five_in_row_define_data_h

#define BOARD_SIZE 15


char blank_board;
/*gamemode:
 1 for ai vs player
 2 for player vs player
 3 for ai vs ai
 */
int mode;

char board[BOARD_SIZE][BOARD_SIZE];
int markboard[BOARD_SIZE][BOARD_SIZE];
char im_board[BOARD_SIZE][BOARD_SIZE];


int coordinate_x[BOARD_SIZE];
int coordinate_y[BOARD_SIZE];



//print out the current board
/*
 1 to turn on coordinate
 0 to turn off coordinate
 */
void print_board(int);
void print_markboard();
void create_imboard();
//initialize the board
/* input anything to display the blank board
 */
void init_board(char);

//steps
void steps(int,int,char);//do the step
void im_steps(int,int,char);//ai function
//Win check
int win_check_general(int,int,char);//general method to check if win >>win_check.c

//My method get length
int get_length(int,int,char);
int get_length_im(int,int,char);
int mark(int);//0,1,10,100,1000,10000

//analysis points
int ana_x();
int ana_y();

int ana_x_im();
int ana_y_im();

int ai_turn_white();
int ai_turn_black();


void savelog(int);
int win;
#endif
