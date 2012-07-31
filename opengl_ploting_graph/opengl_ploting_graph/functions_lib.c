//
//  functions_lib.c
//  opengl_ploting_graph
//
//  Created by eamars on 30/07/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define.h"
#include <math.h>

float Quadratic_function(float x)
{
    float y;
    y=x*x;
    return y;
}

float Sine_function(float x)
{
    float y;
    y=sinf(x);
    return y;
}

float Logarithm_function(float x)
{
    float y;
    y=log(x);
    return y;
    
}