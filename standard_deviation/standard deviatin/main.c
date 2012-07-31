//
//  main.c
//  standard deviatin
//
//  Created by eamars on 12-7-3.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
#define SIZE 100
#include <stdio.h>
#include "math.h"

int main(int argc, const char * argv[])
{
    float power(float,int);
    float data[SIZE],sum=0;
    float mean;
    float var[SIZE];//(x-varx)^2
    float sum_var=0;
    float stand_dev;
    int valid_number;
    int frequency[SIZE],sum_frequency=0;
    struct data_type;
    {
        float data_value[SIZE];
        int data_frequency[SIZE];
    }

    
    printf("input valid group=");
    scanf("%d",&valid_number);
    printf("input data\n=");
    for (int i = 0; i<valid_number; i++) {
        scanf("%f,%d",&data[i],&frequency[i]);//input data and frequency
        sum=sum+data[i]*frequency[i];   //sum up the data*frequency
        sum_frequency=sum_frequency+frequency[i];//sum up the frequency
        
        //get detailed data
    }
    
    //calc mean
    mean=sum/(float)sum_frequency;
    
    
    //calc var
    for (int i=0; i<valid_number; i++) {
        var[i]=power(data[i]-mean, 2);
    }
    
    //calc sum_var
    for (int i=0; i<valid_number; i++) {
        sum_var=sum_var+var[i]*frequency[i];
    }
    
    //calc sd
    stand_dev=sqrtf(sum_var/(float)sum_frequency);
    /*
     in some cases
        stand_dev=sqrtf(sum_var/(float)sum_frequency);
     can be replaced by 
        stand_dev=sqrtf(sum_var/(float)sum_frequency-1);
     */
    
    //print out data
    for (int i=0; i<valid_number; i++) {
        printf("%0.3f ",data[i]);
    }
    
    printf("\n");
    printf("[number]\n= %d\n",sum_frequency);
    printf("[mean]\n= %0.2f\n",mean);
    printf("[standard deviation]\n= %0.2f\n",stand_dev);
    return 0;
}

float power(float base,int power)
{
    float p=1;
    for (int i=1; i<=power; i++) {
        p=p*base;
    }
    return p;
}


