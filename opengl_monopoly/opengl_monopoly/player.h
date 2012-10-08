//
//  side.h
//  opengl_monopoly
//
//  Created by eamars on 7/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_monopoly_side_h
#define opengl_monopoly_side_h

#include "define_UI.h"

int player[5]; // player[0] is the mother nature

void init_player(int,int);

void player1_turn();
void player2_turn();

int player1_position;
int player2_position;

#endif
