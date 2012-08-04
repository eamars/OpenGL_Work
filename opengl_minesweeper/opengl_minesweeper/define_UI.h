//
//  define_UI.h
//  opengl_minesweeper
//
//  Created by eamars on 3/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_minesweeper_define_UI_h
#define opengl_minesweeper_define_UI_h

#define FRAMEWORK 6.0
void grid();
void init();
void Mine_sweeper();
void Blind_piece();
void Piece_With_number(float,float,int);
void NumberSet(int,float,float,float);
void MouseClick(int,int,int,int);
void MousePassing(int,int);
void End_frame(int);

void printc(char,float,float,float);
void disp_font(char *,float,float,float);



void YOU_WIN (float,float,float);
void YOU_LOSE (float,float,float);
void MousePassingEndFrame(int,int);
void MouseClickEndFrame(int,int,int,int);
#endif
