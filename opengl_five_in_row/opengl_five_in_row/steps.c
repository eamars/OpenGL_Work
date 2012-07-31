//
//  steps.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"

void steps(int x,int y,char side)
{
    if (side=='b') {
        board[x][y]='X';
    }
    
    if (side=='w') {
        board[x][y]='O';
    }
    
}

