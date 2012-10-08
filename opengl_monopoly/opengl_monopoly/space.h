//
//  space.h
//  opengl_monopoly
//
//  Created by eamars on 6/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef opengl_monopoly_space_h
#define opengl_monopoly_space_h

#include "define_UI.h"

void make_space();



int get_payment(int);

int buy_space(int,int);

int check_link(int);

struct space_type {
    int house;
    int ratio_house;
    int initial_price;
    int occupy_condition;
    int mortgage_condition;
    int link_condition;
    char space_name[25];
};

struct space_type space[40];

#endif
