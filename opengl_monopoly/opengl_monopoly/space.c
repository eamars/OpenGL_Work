//
//  space.c
//  opengl_monopoly
//
//  Created by eamars on 6/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "space.h"

void define_space(int space_no,int house,int ratio_house,int initial_price,int occupy_condition,int mortgage_condition,int link_condition,char space_name[])
{
    space[space_no].house = house;
    space[space_no].ratio_house = ratio_house;
    space[space_no].initial_price = initial_price;
    space[space_no].occupy_condition = occupy_condition;
    space[space_no].mortgage_condition = mortgage_condition;
    space[space_no].link_condition = link_condition;
    for (int i=0; i<strlen(space_name); i++) {
        space[space_no].space_name[i] = space_name[i];
    }
}





void make_space()
{
    
    //0 start point
    define_space(0, 0, 0, -200, -1, 0, 1, "Go");
    
    //1 Mediterranean Ave.
	define_space(1, 0, 10, 60, 0, 0, 0, "Mediterranean Ave");
    
    //2 Community Chest
    define_space(2, 0, 0, -200, -1, 0, 1, "Community Chest");
    
    //3 Baltic Ave.
    define_space(3, 0, 20, 60, 0, 0, 0, "Baltic Ave");
    
    //4 Income Tax
    define_space(4, 0, 0, 200, -1, 0, 1, "Income Tax");
    
    //5 Reading Railroad
    define_space(5, 0, 25, 200, 0, 0, 0, "Reading Railroad");
    
    //6 Oriental Ave.
    define_space(6, 0, 30, 100, 0, 0, 0, "Oriental Ave");
    
    //7 Chance
    define_space(7, 0, 0, 0, -1, 0, 1, "Chance");
    
    //8 Vermont Ave.
    define_space(8, 0, 30, 100, 0, 0, 0, "Vermont Ave");
    
    //9 Connecticut Ave.
    define_space(9, 0, 40, 120, 0, 0, 0, "Connecticut Ave");
    
    //10 Just Visiting/Jail
    define_space(10, 0, 0, 0, -1, 0, 1, "Just Visiting/Jail");
    
    //11 St. Charles Place
    define_space(11, 0, 50, 140, 0, 0, 0, "St. Charles Place");
    
    //12 Electric Company
    define_space(12, 0, 10, 200, 0, 0, 0, "Electric Company");
    
    //13 States Ave.
    define_space(13, 0, 50, 140, 0, 0, 0, "States Ave");
    
    //14 Virginia Ave.
    define_space(14, 0, 60, 160, 0, 0, 0, "Virginia Ave");
    
    //15 Pennsylvania Railroad
    define_space(15, 0, 25, 200, 0, 0, 0, "Pennsylvania Railroad");
    
	//16 St. James Place
    define_space(16, 0, 70, 180, 0, 0, 0, "St. James Place");
    
    //17 Community Chest
    define_space(17, 0, 0, -200, -1, 0, 1, "Community Chest");
    
    //18 Tennessee Ave
    define_space(18, 0, 70, 180, 0, 0, 0, "Tennessee Ave");
    
    //19 New York Ave
    define_space(19, 0, 80, 200, 0, 0, 0, "New York Ave");
    
    //20 Free Parking
    define_space(20, 0, 0, 0, -1, 0, 1, "Free Parking");
    
    //21 Kentucky Ave.
    define_space(21, 0, 90, 220, 0, 0, 0, "Kentucky Ave");
    
    //22 Chance
    define_space(22, 0, 0, 0, -1, 0, 1, "Chance");
    
    //23 Indiana Ave.
    define_space(23, 0, 90, 220, 0, 0, 0, "Indiana Ave");
    
    //24 Illinois Ave.
    define_space(24, 0, 100, 240, 0, 0, 0, "Illinois Ave");
    
    //25 B. & O. Railroad
    define_space(25, 0, 25, 200, 0, 0, 0, "B. & O. Railroad");
    
    //26 Atlantic Ave
    define_space(26, 0, 110, 260, 0, 0, 0, "Atlantic Ave");
    
    //27 Ventnor Ave
    define_space(27, 0, 110, 260, 0, 0, 0, "Ventnor Ave");
    
    //28 Water Works
    define_space(28, 0, 10, 200, 0, 0, 0, "Water Works");
    
    //29 Marvin Gardens
    define_space(29, 0, 120, 280, 0, 0, 0, "Marvin Gardens");
    
    //30 Go to Jail
    define_space(30, 0, 0, 0, -1, 0, 1, "Go to Jail");
    
    //31 Pacific Ave.
    define_space(31, 0, 130, 300, 0, 0, 0, "Pacific Ave");
    
    //32 North Carolina Ave.
    define_space(32, 0, 130, 300, 0, 0, 0, "North Carolina Ave");
    
    //33 Community Chest
    define_space(33, 0, 0, -200, -1, 0, 1, "Community Chest");
    
    //34 Pennsylvania Ave.
    define_space(34, 0, 150, 320, 0, 0, 0, "Pennsylvania Ave");
    
    //35 Short Line Railroad
    define_space(35, 0, 25, 200, 0, 0, 0, "Short Line Railroad");
    
    //36 Chance
    define_space(36, 0, 0, 0, -1, 0, 1, "Chance");
    
    //37 Park Place
    define_space(37, 0, 175, 300, 0, 0, 0, "Park Place");
    
    //38 Luxury Tax
    define_space(38, 0, 0, 100, -1, 0, 1, "Luxury Tax");
    
    //39 Boardwalk
    define_space(39, 0, 200, 400, 0, 0, 0, "Boardwalk");
    
    
}

int get_payment(int space_no)
{
    int actual_payment = 0 ;
    int house;
    int ratio_house;
    
    struct space_type *actual_space;
    actual_space = &space[space_no];
    house = actual_space->house;
    ratio_house = actual_space->ratio_house;
    
    //special condition : start point  etc.
    if (actual_space->occupy_condition == -1) {
        actual_payment = actual_space->initial_price;
        return actual_payment;
    }
    
    //special condition : railway station
    if (space_no == 5 || space_no == 15 || space_no == 25 || space_no == 35) {
        actual_payment = house*ratio_house;
        return actual_payment;
    }
    
    //when captured but not linked the actual payment is its initial price*0.1-4
    if (actual_space->occupy_condition > 0 && actual_space->link_condition == 0 && actual_space->mortgage_condition == 0) {
        actual_payment = (actual_space->initial_price)*0.1 - 4;
        return actual_payment;
    }
    //when mortgaged, the actual payment is 0
    else if (actual_space->mortgage_condition == 1){
        return 0;
    }
    //when linked, the payment depends on it's hotels and houses
    else if (actual_space->link_condition == 1){
        actual_payment = house*house*ratio_house;
        return actual_payment;
    }
    //when encounter bugs return a very big negative number to debug
    else
        return -10000;
}

int buy_space(int space_no,int side)
{
    
    if (space[space_no].occupy_condition == 0) {
        space[space_no].occupy_condition = side;
        return space[space_no].initial_price ;
    }
    else
        return 0;
    
}

int check_link(int space_no)
{
    //purple
    if (space_no == 1 || space_no == 3) {
        if (space[1].occupy_condition == space[3].occupy_condition) {
            space[1].link_condition = 1;
            space[3].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Light-Green
    else if (space_no == 6 || space_no == 8 || space_no == 9 ) {
        if (space[6].occupy_condition == space[8].occupy_condition && space[8].occupy_condition == space[9].occupy_condition) {
            space[6].link_condition = 1;
            space[8].link_condition = 1;
            space[9].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Violet
    else if (space_no == 11 || space_no == 13 || space_no == 14 ) {
        if (space[11].occupy_condition == space[13].occupy_condition && space[13].occupy_condition == space[14].occupy_condition) {
            space[11].link_condition = 1;
            space[13].link_condition = 1;
            space[14].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Orange
    else if (space_no == 16 || space_no == 18 || space_no == 19 ) {
        if (space[16].occupy_condition == space[18].occupy_condition && space[18].occupy_condition == space[19].occupy_condition) {
            space[16].link_condition = 1;
            space[18].link_condition = 1;
            space[19].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Red
    else if (space_no == 21 || space_no == 23 || space_no == 24 ) {
        if (space[21].occupy_condition == space[23].occupy_condition && space[23].occupy_condition == space[24].occupy_condition) {
            space[21].link_condition = 1;
            space[23].link_condition = 1;
            space[24].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Yellow
    else if (space_no == 26 || space_no == 27 || space_no == 29 ) {
        if (space[26].occupy_condition == space[27].occupy_condition && space[27].occupy_condition == space[29].occupy_condition) {
            space[26].link_condition = 1;
            space[27].link_condition = 1;
            space[29].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Dark-Green
    else if (space_no == 31 || space_no == 32 || space_no == 34 ) {
        if (space[31].occupy_condition == space[32].occupy_condition && space[32].occupy_condition == space[34].occupy_condition) {
            space[31].link_condition = 1;
            space[32].link_condition = 1;
            space[34].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    //Dark-Blue
    else if (space_no == 37 || space_no == 39) {
        if (space[37].occupy_condition == space[39].occupy_condition) {
            space[37].link_condition = 1;
            space[39].link_condition = 1;
            return 1;
        }
        else
            return 0;
    }
    
    else
        return 0;
}








