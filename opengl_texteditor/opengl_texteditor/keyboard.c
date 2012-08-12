//
//  keyboard.c
//  opengl_texteditor
//
//  Created by eamars on 12/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif
#include "define_graph.h"
#include "define_data.h"
int line=0;
int col=0;


const float growth=0.08;
const float offset=0.2;
float xf=0.1,yf=4.7;

void KeyBoard(unsigned char key,int x,int y)
{
    //printf("key=%d\n",key);
    
    /* enter */
    if (key==13)
    {
        //del '_' before print letter
        glColor3f(0, 0, 0);
        printc('_', xf, yf, 0.5);
        
        //graph control
        yf=yf-offset;
        xf=0.1;
        
        //data control
        col=0;
        line++;
        
        glColor3f(1, 1, 1);
        printc('_', xf, yf, 0.5);
    }
    
    
    /* backspace */
    else if (key==127)
    {
        if (xf<0.11 && yf>4.6)
        {
            glColor3f(0, 0, 0);
            printc('_', xf-growth, yf, 0.5);
            
            glColor3f(1, 1, 1);
            printc('_', xf, yf, 0.5);
            
            //graph control
            xf=0.1;
            yf=4.7;
            
            //data control
            col=0;
            line=0;
        }
        else if (xf<0.11)
        {
            glColor3f(0, 0, 0);
            printc('_', xf, yf, 0.5);
            
            //graph control
            xf=7.78;
            yf=yf+offset;
            
            //data control
            col=96;
            line--;
            
            printc('\000', xf, yf, 0.5);
            //printc('\000', xf+growth, yf, 0.5);
            glColor3f(1, 1, 1);
            printc('_', xf, yf, 0.5);
            
        }
        else
        {
        	glColor3f(0, 0, 0);
            printc('\000', xf-growth, yf, 0.5);
            printc('_', xf, yf, 0.5);
            
            //graph control
            xf=xf-growth;
            
            //data control
            col--;;
            
            glColor3f(1, 1, 1);
            printc('_', xf, yf, 0.5);
        }
    }
    
    /* tab */
    else if (key==9)
    {
        //del '_' before print letter
        glColor3f(0, 0, 0);
        printc('_', xf, yf, 0.5);
        
        //graph control
        xf=xf+growth*4;
        
        //data control
        col=col+4;
        
        glColor3f(1, 1, 1);
        printc('_', xf, yf, 0.5);
    }
    
    /* other keys */
    else
    {
    	//del '_' before print letter
        glColor3f(0, 0, 0);
        printc('_', xf, yf, 0.5);
        //clean history
        printc('\000', xf, yf, 0.5);
        //print character
        glColor3f(1, 1, 1);
        printc(key, xf, yf, 0.5);
        //print '_'
        glColor3f(1, 1, 1);
        printc('_', xf+growth, yf, 0.5);
        
        //graph control
        xf=xf+growth;
        
        //data control
        col++;
        
        if (xf>7.8) {
            //del '_' before print letter
            glColor3f(0, 0, 0);
            printc('_', xf, yf, 0.5);
            
            //graph control
            yf=yf-offset;
            xf=0.1;
            
            //data control
            col=0;
            line++;
            
            //print '_'
            glColor3f(1, 1, 1);
            printc('_', xf, yf, 0.5);
        }
    }
    dislplayinfo(line, col);
    printf("line=%d column=%d\n",line,col);
}


void SpecialKey(int key,int x,int y)
{
    
    switch (key)
    {
        case GLUT_KEY_UP:
            if (yf>4.61) {
                break;
            }
            else
            {
                //clean '_'
                glColor3f(0, 0, 0);
                printc('_', xf, yf, 0.5);
                
                yf=yf+offset;
                line--;
                
                //print '_'
                glColor3f(1, 1, 1);
                printc('_', xf, yf, 0.5);
                break;
            }
            
        case GLUT_KEY_DOWN:
            if (yf<0.2) {
                break;
            }
            else
            {
                //clean '_'
                glColor3f(0, 0, 0);
                printc('_', xf, yf, 0.5);
                
                yf=yf-offset;
                line++;
                
                //print '_'
                glColor3f(1, 1, 1);
                printc('_', xf, yf, 0.5);
                break;
            }
            
        case GLUT_KEY_RIGHT:
            if (xf>7.8) {
                break;
            }
            else
            {
                //clean '_'
                glColor3f(0, 0, 0);
                printc('_', xf, yf, 0.5);
                
                xf=xf+growth;
                col++;
                
                //print '_'
                glColor3f(1, 1, 1);
                printc('_', xf, yf, 0.5);
                break;
            }
            
        case GLUT_KEY_LEFT:
            if (xf<0.11) {
                break;
            }
            else
            {
                //clean '_'
                glColor3f(0, 0, 0);
                printc('_', xf, yf, 0.5);
                
                xf=xf-growth;
                col--;
                
                //print '_'
                glColor3f(1, 1, 1);
                printc('_', xf, yf, 0.5);
                break;
            }
            
    
    }
    
    dislplayinfo(line, col);
    
    
    
    
    
}