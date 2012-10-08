//
//  SIDE.c
//  opengl_monopoly
//
//  Created by eamars on 7/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "player.h"

void init_player(int player_no,int init_money)
{
    for (int i=1; i<=player_no; i++) {
        player[i]=init_money;
    }
}



void player1_turn()
{
    int dice = dice_data(2);
    int purchase;
    int fine;
    int get;
    player1_position = dice+player1_position; //drop the dices
    
    /*
     when finish one loop, the counter back to zero
     */
    if (player1_position > 40) {
        player1_position = player1_position-40;
    }
    
    printf("Player[1] droped %d points\n",dice);
    
    /*
     when occupy_condition = 0
     buy the space
     the cost is it's original price
     */
    if (space[player1_position].occupy_condition == 0) { 
        purchase = buy_space(player1_position, 1);
        printf("Player[1] bought %s for %d dollars\n",space[player1_position].space_name, purchase);
        player[1]=player[1]-purchase;
        printf("Player[1] has %d dollars left\n\n",player[1]);
        
    }
    
    /*
     for player1
     when the space's occupy_condation = 1
     it means the space has been purchased, no fine and no get
     */
    else if (space[player1_position].occupy_condition == 1)
    {
        printf("%s is already belongs to Player[1]\n\n",space[player1_position].space_name);
    }
    
    /*
     for player1
     When the space's occupy_condition != 1, for example of 2
     player1 - fine and player + fine
     */
    else if (space[player1_position].occupy_condition == 2)
    {
        fine = get_payment(player1_position);
        player[1] = player[1]-fine;
        player[2] = player[2]+fine;
        printf("FINE: %s is owned by Player[2], Player[1] is fined %d dollars\n",space[player1_position].space_name,fine);
        printf("Player[1] has %d dollars left\n\n",player[1]);
    }
    
    /*
     When the space's occupy_condition == -1
     the fine and get depends on space itself
     */
    else if (space[player1_position].occupy_condition == -1)
    {
        if (player1_position == 30) {
            player1_position = 10;
            player[1] = player[1]-50;
            printf("Player[1] is sent to Jail and fined 50 dollars\n");
            printf("Player[1] has %d dollars left\n\n",player[1]);
        }
        else{
            get = get_payment(player1_position);
            player[1] = player[1]-get;
            printf("Player[1] get %d dollars from %s\n",-get,space[player1_position].space_name); // -get to get positive value
            printf("Player[1] has %d dollars left\n\n",player[1]);
        }
    }
    
    /* error */
    else
        printf("WARNING: %s ERROR\n\n",space[player1_position].space_name);

    
}
void player2_turn()
{
    int dice = dice_data(2);
    int purchase;
    int fine;
    int get;
    player2_position = dice+player2_position;
    
    if (player2_position > 40) {
        player2_position = player2_position-40;
    }
    
    printf("Player[2] droped %d points\n",dice);
    if (space[player2_position].occupy_condition == 0) {
        purchase = buy_space(player2_position, 2);
        printf("Player[2] bought %s for %d dollars\n",space[player2_position].space_name, purchase);
        player[2]=player[2]-purchase;
        printf("Player[2] has %d dollars left\n\n",player[2]);
        
    }
    else if (space[player2_position].occupy_condition == 2)
    {
        printf("%s is already belongs to Player[2]\n\n",space[player2_position].space_name);
    }
    else if (space[player2_position].occupy_condition == 1)
    {
        fine = get_payment(player2_position);
        player[2] = player[2]-fine;
        player[1] = player[1]+fine;
        printf("FINE: %s is owned by Player[1], Player[2] is fined %d dollars\n",space[player2_position].space_name,fine);
        printf("Player[2] has %d dollars left\n\n",player[2]);
    }
    else if (space[player2_position].occupy_condition == -1)
    {
        if (player2_position == 30) {
            player2_position = 10;
            player[2] = player[2]-50;
            printf("Player[2] is sent to Jail and fined 50 dollars\n");
            printf("Player[2] has %d dollars left\n\n",player[2]);
        }
        else{
            get = get_payment(player2_position);
            player[2] = player[2]-get;
            printf("Player[2] get %d dollars from %s\n",-get,space[player2_position].space_name);// -get to get positive value
            printf("Player[2] has %d dollars left\n\n",player[2]);
        }
        
    }
    else
        printf("WARNING: %s ERROR\n\n",space[player2_position].space_name);
}