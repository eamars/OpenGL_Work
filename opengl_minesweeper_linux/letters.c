//
//  letters.c
//  opengl_minesweeper
//
//  Created by eamars on 4/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "font_8x16.h"


void disp_font(char *asc,float x,float y,float fs)
{
    float Point_size;
    fs=fs/50;
    Point_size=80*fs;
    if (fs*50<1.5) {
        Point_size=150*fs;
    }
    glPointSize(Point_size);
    
    float xf=x,yf=y;
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(asc[i] & (0x80>>j))
			{
                           
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



void printc(char c,float x,float y,float fs)
{
    char *p;
    long offset;
	offset = c* 16;
    p = fontdata_8x16+offset;
    
    disp_font(p,x,y,fs);
}





void YOU_WIN (float x,float y,float FS)
{
    float gap=FS/6;
    printc('Y', x, y, FS);
    x=x+gap;
    printc('o', x, y, FS);
    x=x+gap;
    printc('u', x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
    printc('W', x, y, FS);
    x=x+gap;
    printc('i', x, y, FS);
    x=x+gap;
    printc('n', x, y, FS);
    
}

void YOU_LOSE (float x,float y,float FS)
{
    float gap=FS/6;
    printc('Y', x, y, FS);
    x=x+gap;
    printc('o', x, y, FS);
    x=x+gap;
    printc('u', x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
    printc('L', x, y, FS);
    x=x+gap;
    printc('o', x, y, FS);
    x=x+gap;
    printc('s', x, y, FS);
    x=x+gap;
    printc('e', x, y, FS);
}
