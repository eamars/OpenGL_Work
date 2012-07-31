//
//  mouse.c
//  opengl_five_in_row
//
//  Created by eamars on 31/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_board_opengl.h"
#include <GLUT/glut.h>

void MouseAction(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            //Left Button code.
            
            float xf,yf;
            xf=(float)x/50+0.5;
            yf=(float)y/50+0.5;
            printf("board axis:x=%f,y=%f\n",xf,yf);
            piece_GL('w', (int)xf, (int)yf);
            
            glFlush();
        }
        else if(button == GLUT_MIDDLE_BUTTON)
        {
            //middle button code
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            //right button code
        }
    }
    else
    {
        //alternate code
    }
}