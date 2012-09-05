//
//  define_board_opengl.h
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_five_in_row_define_board_opengl_h
#define opengl_five_in_row_define_board_opengl_h
#define COEI 6.0
void grid();
void init();
void print_board_UI();
void model1();


void MousePassingEndFrame(int,int);
void MouseClickEndFrame(int,int,int,int);
void MouseAction(int,int,int,int);
void piece_GL(char,int,int);


void Lett_Y (float,float,float);
void Lett_O (float,float,float);
void Lett_U (float,float,float);
void Lett_W (float,float,float);
void Lett_I (float,float,float);
void Lett_N (float,float,float);
void Sign_1 (float,float,float);

void YOU_WIN (float,float,float);

void printc(char,float,float,float);// --> print_font.c
void prints(const char str[],float,float,float);// --> print_font.c
#endif

