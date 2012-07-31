//
//  ai_function.c
//  five_in_row
//
//  Created by eamars on 12-7-20.
//  Copyright (c) 2012年 Ran Bao. All rights reserved.
//

#include <stdio.h>
#include "define.h"

/* the following are for ai use*/

//get length for marking use
int get_length_vertical(int x_i,int y_i) //i stand for initial
{
    int length=1;
    
    //vertical
    for (int x_a=x_i+1; x_a<BOARD_SIZE&&x_a<=x_i+4; x_a++) {
        
        if (board[x_a][y_i]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_i]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    
    for (int x_a=x_i-1; x_a>=0&&x_a>=x_i-4; x_a--) {
        if (board[x_a][y_i]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_i]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    length=0.5*(length-1);
    return length;
}

int get_length_horizontal(int x_i,int y_i) //i stand for initial
{
    int length=1;
    
    //horizontal
    for (int y_a=y_i+1; y_a<BOARD_SIZE&&y_a<=y_i+4; y_a++) {
        if (board[x_i][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_i][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    
    for (int y_a=y_i-1; y_a>=0&&y_a>=y_i-4; y_a--) {
        if (board[x_i][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_i][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    length=0.5*(length-1);
    return length;
}

int get_length_diagonal_p(int x_i,int y_i)
{
    int length=1;
    
    //plus diagonal
    for (int x_a=x_i+1,y_a=y_i-1; x_a<BOARD_SIZE&&y_a>=0&&x_a<=x_i+4&&y_a>=y_i-4; x_a++,y_a--) {
        if (board[x_a][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    
    for (int x_a=x_i-1,y_a=y_i+1; x_a>=0&&y_a<BOARD_SIZE&&x_a>=x_i-4&&y_a<=y_i+4; x_a--,y_a++) {
        if (board[x_a][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    length=0.5*(length-1);
    return length;
}

int get_length_diagonal_m(int x_i,int y_i)
{
    int length=1;
    
    //minus diagonal
    for (int x_a=x_i+1,y_a=y_i+1; x_a<BOARD_SIZE&&y_a<BOARD_SIZE&&x_a<=x_i+4&&y_a<=y_i+4; x_a++,y_a++) {
        if (board[x_a][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    
    for (int x_a=x_i-1,y_a=y_i-1; x_a>=0&&y_a>=0&&x_a>=x_i-4&&y_a>=y_i-4; x_a--,y_a--) {
        if (board[x_a][y_a]==board[x_i][y_i]) {
            length++;
        }
        else if (board[x_a][y_a]!=board[x_i][y_i]){
            length--;
            break;
        }
        else
        {
            length--;
        }
        
        
    }
    
    length=0.5*(length-1);
    return length;
}

/* My method to get marks*/

int get_length(int x,int y)
{
    int total_mark=0;
    
    //length
    int v_length=0;
    int h_length=0;
    int d_plength=0;
    int d_mlength=0;
    
    //x-y
    int x_v=x;
    int y_v=y;
    
    int x_h=x;
    int y_h=y;
    
    int x_dp=x;
    int y_dp=y;
    
    int x_dm=x;
    int y_dm=y;
    
    
    
    //vertical
    for (; x_v+2<BOARD_SIZE; ) {
        while (board[x_v+1][y_v]==board[x][y]||(board[x_v+1][y_v]==blank_board&&board[x_v+2][y_v]==board[x][y]))
        {
            x_v++;
            if (board[x_v+1][y_v]==blank_board&&board[x_v+2][y_v]==board[x][y]) {
                x_v++;
            }
            v_length++;
        }
        if ((board[x_v+1][y_v]==blank_board)&&(board[x_v+2][y_v]==blank_board)) {
            v_length++;
            break;
        }
        else if ((board[x_v+1][y_v]==blank_board)&&(board[x_v+2][y_v])!=blank_board&&(board[x_v+2][y_v])!=(board[x][y]))
        {
            v_length--;
            break;
        }
        else
            break;
    }
    for (; x_v-2>=0; ) {
        while (board[x_v-1][y_v]==board[x][y]||(board[x_v-1][y_v]==blank_board&&board[x_v-2][y_v]==board[x][y]))
        {
            x_v--;
            if (board[x_v-1][y_v]==blank_board&&board[x_v-2][y_v]==board[x][y]) {
                x_v--;
            }
            v_length++;
        }
        if ((board[x_v-1][y_v]==blank_board)&&(board[x_v-2][y_v]==blank_board)) {
            v_length++;
            break;
        }
        else if ((board[x_v-1][y_v]==blank_board)&&(board[x_v-2][y_v])!=blank_board&&(board[x_v-2][y_v])!=(board[x][y]))
        {
            v_length--;
            break;
        }
        else
            break;
    }
    v_length=v_length*0.5;
    
    //honzontal
    
    
    
    total_mark=mark(v_length);
    return total_mark;
}

int mark(int length)
{
    int mark_value;
    if (length==0) {
        mark_value=0;
    }
    else if (length==1) {
        mark_value=1;
    }
    else if (length==2) {
        mark_value=10;
    }
    else if (length==3) {
        mark_value=100;
    }
    else if (length==4) {
        mark_value=1000;
    }
    else if (length==5) {
        mark_value=10000;
    }
    else
        mark_value=0;
    
    return mark_value;
}

int ana_x()
{
    int x;
    int max=0,buff;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            buff=get_length(i, j);
            if (buff>max) {
                max=buff;
                x=i;
                continue;
            }
        }
    }
    
    return x;
}

int ana_y()
{

    int y;
    int max=0,buff;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            buff=get_length(i, j);
            if (buff>max) {
                max=buff;
                y=j;
                continue;
            }
        }
    }
    
    return y;
}
