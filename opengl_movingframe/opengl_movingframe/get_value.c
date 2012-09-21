//
//  get_value.c
//  opengl_movingframe
//
//  Created by eamars on 21/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_UI.h"
#include <math.h>

void display_time(float x,float y,float time)
{
    time=time*1000; //in unit of ms
    float FS=1;
    float gap=FS/6;
    int thousand=time/1000;
    int hundred=(time-thousand*1000)/100;
    int ten=(time-thousand*1000-hundred*100)/10;
    int one=(time-thousand*1000-hundred*100-ten*10)/1;
    char c_thousand=thousand+48;
    char c_hundred=hundred+48;
    char c_ten=ten+48;
    char c_one=one+48;
    
    
    prints("Time = ", x, y, FS);
    x=x+7*gap;
    printc(c_thousand, x, y, FS);
    x=x+gap;
    printc(c_hundred, x, y, FS);
    x=x+gap;
    printc(c_ten, x, y, FS);
    x=x+gap;
    printc(c_one, x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
    prints("ms", x, y, FS);
}

void sep_value(float x,float y,float FS,float value)
{
    
    int neg=0;
    float gap=FS/6;
    if (value<0) {
        value=-value;
        neg=1;
    }
    value=value*1000;
    //printf("value=%f\n",value);
    int tenthousand=value/10000;
    int thousand=(value-tenthousand*10000)/1000;
    int hundred=(value-tenthousand*10000-thousand*1000)/100;
    int ten=(value-tenthousand*10000-thousand*1000-hundred*100)/10;
    int one=(value-tenthousand*10000-thousand*1000-hundred*100-ten*10)/1;
    char c_tenthousand=tenthousand+48;
    char c_thousand=thousand+48;
    char c_hundred=hundred+48;
    char c_ten=ten+48;
    char c_one=one+48;
    if (neg==1) {
        printc('-', x, y, FS);
        x=x+gap;
    }
    
    
    if (c_tenthousand=='0') {
    }
    else{
        printc(c_tenthousand, x, y, FS);
        x=x+gap;
    }
        
    
    
    // thousand is always 0
    printc(c_thousand, x, y, FS);
    x=x+gap;
    
    printc('.', x, y, FS);
    x=x+gap;
    
    if (c_hundred=='0' && c_thousand=='0' && c_tenthousand=='0') {
    }
    else{
        printc(c_hundred, x, y, FS);
        x=x+gap;
    }
        
    
    if (c_ten=='0' && c_hundred=='0' && c_thousand=='0' && c_tenthousand=='0') {
    }
    else{
        printc(c_ten, x, y, FS);
        x=x+gap;
    }
        
    
    if (c_one=='0' && c_ten=='0' && c_hundred=='0' && c_thousand=='0' && c_tenthousand=='0') {
    }
    else{
        printc(c_one, x, y, FS);
        x=x+gap;
    }
        
    
}

void display_value(float x,float y,float h,float v,float vx,float vy)
{
    //printf("x=%f y=%f vx=%f vy=%f\n",h,v,vx,vy);
    float velocity=sqrtf(vx*vx+vy*vy);
    float x_init=x;
    glColor3f(WHITE);
    float FS=1;
    float gap=FS/6;
    
    //horizontal displacement
    prints("x=", x, y, FS);
    x=x+2*gap;
    sep_value(x, y, FS, h);
    x=x+6*gap;
    prints("m", x, y, FS);
    
    y=y-0.3; //next line
    x=x_init; //reset x
    
    //vertical displacement
    prints("y=", x, y, FS);
    x=x+2*gap;
    sep_value(x, y, FS, v);
    x=x+6*gap;
    prints("m", x, y, FS);
    
	y=y-0.3; //next line
    x=x_init; //reset x
    
    //horizontal velocity
    prints("vx=", x, y, FS);
    x=x+3*gap;
    sep_value(x, y, FS, vx);
    x=x+6*gap;
    prints("m/s", x, y, FS);
    
    y=y-0.3; //next line
    x=x_init; //reset x
    
    //vertical velocity
    prints("vy=", x, y, FS);
    x=x+3*gap;
    sep_value(x, y, FS, vy);
    x=x+6*gap;
    prints("m/s", x, y, FS);
    y=y-0.3; //next line
    x=x_init; //reset x
    
    //total velocity
    prints("v=", x, y, FS);
    x=x+2*gap;
    sep_value(x, y, FS, velocity);
    x=x+6*gap;
    prints("m/s", x, y, FS);
}
