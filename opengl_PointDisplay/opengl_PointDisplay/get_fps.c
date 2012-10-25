//
//  get_fps.c
//  opengl_shooting_game
//
//  Created by eamars on 8/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "define.h"


double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;
    
    ++count;
    if( count <= 50 )
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current-last)/(double)CLOCKS_PER_SEC;
    save = 50.0/timegap;
    return save;
}

void display_FPS()
{
    float x = -4.95,y = 4,FS = 1;
    int fps=CalFrequency();
    
    glColor3f(RED);
    char fpsStr[20];
    sprintf(fpsStr, "FPS = %d",fps);
    prints(fpsStr, x, y, FS);
    
    glFlush();
}
