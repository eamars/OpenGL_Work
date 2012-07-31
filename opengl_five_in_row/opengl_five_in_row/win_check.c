//
//  win_check.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"

int win_check_general(int x_axis,int y_axis,char side_code)
{
    int win_status = 0;
    int side;
    int N=1,NE=1,E=1,SE=1,S=1,SW=1,W=1,NW=1;
    
    if (side_code=='b') {
        side=-1;
    }
    else if (side_code=='w') {
        side=1;
    }
    
    //N
    for (N=1; board[x_axis+N][y_axis]==board[x_axis][y_axis]; N++) {
        if (board[x_axis+N][y_axis]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //S
    for (S=1; board[x_axis-S][y_axis]==board[x_axis][y_axis]; S++) {
        if (board[x_axis-S][y_axis]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //N+S
    if ((N+S)==6) {
        win_status=side;
    }
    
    
    //E
    for (E=1; board[x_axis][y_axis-E]==board[x_axis][y_axis]; E++) {
        if (board[x_axis][y_axis-E]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //W
    for (W=1; board[x_axis][y_axis+W]==board[x_axis][y_axis]; W++) {
        if (board[x_axis][y_axis+W]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //E+W
    if ((E+W)==6) {
        win_status=side;
    }
    
    //NE
    for (NE=1; board[x_axis+NE][y_axis-NE]==board[x_axis][y_axis]; NE++) {
        if (board[x_axis+NE][y_axis-NE]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //SW
    for (SW=1; board[x_axis-SW][y_axis+SW]==board[x_axis][y_axis]; SW++) {
        if (board[x_axis-SW][y_axis+SW]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //SW+NE
    if ((SW+NE)==6) {
        win_status=side;
    }
    
    //SE
    for (SE=1; board[x_axis-SE][y_axis-SE]==board[x_axis][y_axis]; SE++) {
        if (board[x_axis-SE][y_axis-SE]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //NW
    for (NW=1; board[x_axis+NW][y_axis+NW]==board[x_axis][y_axis]; NW++) {
        if (board[x_axis+NW][y_axis+NW]!=board[x_axis][y_axis]) {
            break;
        }
    }
    
    //SE+NW
    if ((SE+NW)==6) {
        win_status=side;
    }
    
    return win_status;
    
}
