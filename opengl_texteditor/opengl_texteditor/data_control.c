//
//  data_control.c
//  opengl_texteditor
//
//  Created by eamars on 12/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"


void Writetodata(char ch,int x,int y)
{
    data[x][y]=ch;
}

void init_data()
{
    for (int i=0; i<96; i++) {
        for (int j=0; j<24; j++) {
            data[i][j]=' ';
        }
    }
}