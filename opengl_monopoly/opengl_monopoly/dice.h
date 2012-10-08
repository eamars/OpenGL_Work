//
//  dice.h
//  opengl_monopoly
//
//  Created by eamars on 27/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_monopoly_dice_h
#define opengl_monopoly_dice_h

#include "define_UI.h"
/* when double dice, the player have one more chance to play again*/
int double_dice;


/*
 dice[0]
 dice[1]
 */
int dice[2];

int dice_data(int);
void dice_ui(float,float);

#endif
