//
//  versus.c
//  five_in_row
//
//  Created by eamars on 12-7-17.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#include <stdio.h>
#include "define.h"

void player_vs_player(int switcher)
{
    if (switcher==1) {
        print_board(1);
        do {
            black_turn();
            print_board(1);
            if (win!=0) {
                break;
            }
            white_turn();
            print_board(1);
        } while (win==0);
        
        if (win==1) {
            printf("\n[Black wins]\n");
        }
        if (win==-1) {
            printf("\n[White wins]\n");
        }
        
    }
    else
        printf("\n[ERROR!]\nVersus with player is not available now\n");
    
    
}



void player_vs_ai(int switcher)
{
    if (switcher==1) {
        print_board(1);
        do {
            black_turn();
            print_board(1);
            if (win!=0) {
                break;
            }
            ai_turn_white();
            print_board(1);
        } while (win==0);
        
        if (win==1) {
            printf("\n[Black wins]\n");
        }
        if (win==-1) {
            printf("\n[White wins]\n");
        }

    }
    else
        printf("\n[ERROR!]\nVersus with computer is not available now\n");
    
}



void ai_vs_ai(int switcher)
{
    int count_times=0;
    if (switcher==1) {
        print_board(1);
        do {
            ai_turn_black();
            print_board(1);
            if (win!=0) {
                break;
            }
            ai_turn_white();
            print_board(1);
            count_times++;
        } while (win==0);
        
        if (win==1) {
            printf("\n[Black wins]\n");
        }
        if (win==-1) {
            printf("\n[White wins]\n");
        }
        printf("It takes %d times to win\n",count_times);
    }
    else
        printf("\n[ERROR!]\nnot available now\n");

}