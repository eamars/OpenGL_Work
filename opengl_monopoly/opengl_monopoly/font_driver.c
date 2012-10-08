//
//  font_driver.c
//  opengl_texteditor
//
//  Created by eamars on 12/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include "font_8x16.h"
#include <string.h>

void disp_font(char *asc,float x,float y,float fs,float Point_size)
{
    
	glDisable(GL_POINT_SMOOTH);
    fs=fs/50;
    
    glPointSize(Point_size);
    
    float xf=x,yf=y;
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(asc[i] & (0x80>>j))
			{
                glDisable(GL_POINT_SMOOTH);
				glBegin(GL_POINTS);
                glVertex2f(xf, yf);
                glEnd();
                xf=xf+fs;
			}
			else
				xf=xf+fs;
		}
		xf=x;
        yf=yf-fs;
	}
    glFlush();
}

void printc(char c,float x,float y,float fs,float Point_size)
{
    char *p;
    long offset;
	offset = c* 16;
    p = fontdata_8x16+offset;
    
    disp_font(p,x,y,fs,Point_size);
}

void prints(const char str[],float x,float y,float fs,float Point_size)
{
    float interval=0.17;
    float xf=x;
    for (int i=0; i<strlen(str); i++) {
        printc(str[i], xf, y, fs,Point_size);
        xf=xf+interval;
    }
}

