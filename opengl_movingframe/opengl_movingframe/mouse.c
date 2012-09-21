//
//  mouse.c
//  opengl_movingframe
//
//  Created by eamars on 21/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"

void MouseAction(int button,int state,int x,int y)
{
    //vx
    if(state == GLUT_DOWN && x>301 && x<327 && y>102 && y<119)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            vx++;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            vx--;
            
        }
        startup();
    }
    //vy
    else if (state == GLUT_DOWN && x>301 && x<327 && y>202 && y<217)
    {
		if(button == GLUT_LEFT_BUTTON)
        {
            vy++;
            
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            vy--;
            
        }
        startup();
    }
     //launch
    else if (state == GLUT_DOWN && x>125 &&x<226 && y>352 && y<404)
    {
        if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
            glutMouseFunc(NULL);
            glutIdleFunc(function);
        }
    }
}
void MouseLocation(int x,int y)
{
    printf("x=%d y=%d\n",x,y);
}