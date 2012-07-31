//
//  main.c
//  five_in_row
//
//  Created by eamars on 12-7-15.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#include <stdio.h>
#include "define.h"

int main(int argc, const char * argv[])
{
    blank_board='-';//blank_board default for '-'
    win=0;
    init_board(blank_board);//clean and initilize the board
    
    /*for debug use
     board[0][0]='0';
     */
    
    char startup;
    
    startup=welcome();
    
    if (startup=='1') {
        player_vs_ai(1);//0 to switch down ,1 to switch on
    }
    else if (startup=='2')
    {
        player_vs_player(1);//0 to switch down ,1 to switch on
    }
    else if (startup=='3')
    {
        ai_vs_ai(1);
    }
    
    return 0;
}
