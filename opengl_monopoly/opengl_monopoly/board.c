//
//  board.c
//  opengl_monopoly
//
//  Created by eamars on 27/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#ifdef __APPLE__
#include <unistd.h>
#else
#include <windows.h>
#endif
#include "board.h"


void board1(void)
{
    //prints("helloworld", 0, 0, 1,1.5);
    make_space();
    init_player(2, 2000);
    
    player1_position = 0;
    player2_position = 0;
    
    //DEBUG TEST
    
    do {
        if (player[1] > 0) {
            player1_turn();
#ifdef __APPLE__
			sleep(1);
#else
            Sleep(1000);
#endif
        }
        else
            printf("Player[1] is bankrupted, skip\n\n");
        
        if (player[2] > 0) {
            player2_turn();
#ifdef __APPLE__
			sleep(1);
#else
            Sleep(1000);
#endif
        }
        else
            printf("Player[2] is bankrupted, skip\n\n");
        
        
    } while (player[1] > 0 || player[2] > 0);
    
    
    //analysis
    printf("\n\n");
    for (int i=0; i<40; i++) {
        if (space[i].occupy_condition == -1 || space[i].occupy_condition == 0) {
            printf("[%d]%s is owned by the Mother Nature\n",i, space[i].space_name);
        }
        else
        	printf("[%d]%s is owned by Player[%d]\n",i, space[i].space_name, space[i].occupy_condition);
    }
    
    
    
    
    
    //dice_ui(-1, 1);
    
}