//
//  dice_data.c
//  opengl_monopoly
//
//  Created by eamars on 27/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

#define random(x) (rand()%x)

int dice_data(int tally)
{
    dice[0]=0;
    dice[1]=0;
    double_dice=0;
    srand((int)time(0));
    
    int sum=0;
    for (int i=0; i<tally; i++) {
        dice[i]=random(5)+1; //random number from 0-5
        sum=sum+dice[i];
    }

    
    
    return sum;
}
