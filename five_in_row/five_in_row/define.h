//
//  define.h
//  five_in_row
//
//  Created by eamars on 12-7-15.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#ifndef five_in_row_define_h
#define five_in_row_define_h
#define BOARD_SIZE 13

char welcome();

char board[BOARD_SIZE][BOARD_SIZE];

int coordinate_x[BOARD_SIZE];
int coordinate_y[BOARD_SIZE];
char blank_board;//default for '-'
/*
 win=1  black win
 win=-1 white win
 win=0  no one win
 */
int win;

/*gamemode:
 1 for ai vs player
 2 for player vs player
 3 for ai vs ai
 */


//  history
//int history_x[MAX_HISTORY];
//int history_y[MAX_HISTORY];
//  history view
//void history_view();

/* ai finish*/

//count times
int count_black;
int count_white;

//undo steps
int history_b_x[BOARD_SIZE*50];
int history_b_y[BOARD_SIZE*50];
int history_w_x[BOARD_SIZE*50];
int history_w_y[BOARD_SIZE*50];

int history_x[BOARD_SIZE*50];
int history_y[BOARD_SIZE*50];
void record_history(int,int,int);
void undo_steps(int,int,int);


//  functions

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

//versus

void player_vs_player(int);
void player_vs_ai(int);
void ai_vs_ai(int);

//steps

void black_turn();//human

void white_turn();//machine

void steps(int,int,char);//do the step

int win_check(int,int,int);//check if win old!

int win_check_general(int,int,int);//general method to check if win



/*for ai use*/
void ai_turn_white();
void ai_turn_black();

//  score of each team
int black_score;
int white_score;
//  value for each point
int board_value_player[BOARD_SIZE][BOARD_SIZE];
int board_value_ai[BOARD_SIZE][BOARD_SIZE];



//My method get length
int get_length(int,int,char);
int mark(int);//0,1,10,100,1000,10000

//analysis points
int ana_x();
int ana_y();

//save the gameplay
void savelog(int);

#endif