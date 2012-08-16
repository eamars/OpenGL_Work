//
//  get_fps.c
//  opengl_shooting_game
//
//  Created by eamars on 8/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "define_graph.h"


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
    float x=0.01,y=7,FS=0.5;
    int fps=CalFrequency();
    int thousand=fps/1000;
    int hundred=(fps-thousand*1000)/100;
    int ten=(fps-thousand*1000-hundred*100)/10;
    int one=(fps-thousand*1000-hundred*100-ten*10)/1;
    //printf("fps=%f fps2=%d%d%d%d\n",CalFrequency(),thousand,hundred,ten,one);
    char c_thousand=thousand+48;
    char c_hundred=hundred+48;
    char c_ten=ten+48;
    char c_one=one+48;
    
    
    glColor3f(1, 1, 1);
    float gap=FS/6;
    printc('F', x, y, FS);
    x=x+gap;
    printc('P', x, y, FS);
    x=x+gap;
    printc('S', x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
    printc('=', x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
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
    printc('V', x, y, FS);
    x=x+gap;
    printc('e', x, y, FS);
    x=x+gap;
    printc('r', x, y, FS);
    x=x+gap;
    printc(' ', x, y, FS);
    x=x+gap;
    printc('A', x, y, FS);
    x=x+gap;
    printc('l', x, y, FS);
    x=x+gap;
    printc('p', x, y, FS);
    x=x+gap;
    printc('h', x, y, FS);
    x=x+gap;
    printc('a', x, y, FS);
    x=x+gap;
    printc('.', x, y, FS);
    
    
    glFlush();
}
