//
//  main.c
//  factorise_expressions
//
//  Created by 然 包 on 12-3-2.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "math.h"
//#define debug 

int main(int argc, const char * argv[])
{

    //define
    int divisor3(int,int,int);
    int divisor2(int,int);
    int a,b,c;
    int i,j;
    int ex,temp;
    int ex_1;
    
    
loop:printf("This program can factorise the quadratic expressions that in form of ax^2+bx+c\n");
    printf("Please type in a,b and c in the expression");
    printf("\na=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("c=");
    scanf("%d",&c);
    if (a!=1) {
        ex=divisor3(a, b, c);
        if (ex!=1) 
        {
            a=a/ex;
            b=b/ex;
            c=c/ex;
        }
#ifdef debug
        printf("debug menu:");
        printf("\ngcd=%d",ex);
        printf("\na=%d",a);
        printf("\nb=%d",b);
        printf("\nc=%d",c);
#endif
        
        //temp is the product of a and c
        temp=a*c;
        for (i=0; ; i++) {
            if (temp==i*(b-i)) {
                break;
            }
        }
        j=b-i;
#ifdef debug
        printf("\ndebug menu:");
        printf("\ni=%d",i);
        printf("\nj=%d",j);
#endif
        /*change the order of i and j if necessary*/
        ex_1=divisor2(a, i);
        if (ex_1==1) {
            temp=i;
            i=j;
            j=temp;
        }
        
        i=i/a;
        c=c/j;
#ifdef debug
        printf("\ndebug menu:");
        printf("\nex=%d",ex_1);
        printf("\ni=%d",i);
        printf("\na=%d",a);
        printf("\nc=%d",c);
#endif
        
        /*The situation that ex is not equal to 0*/
        if (ex!=1) {
            if (j>0&&i>0) {
                printf("\nThe factorised expression is:%d(%dx+%d)(x+%d)",ex,a,j,i);
            }
            if (j>0&&i<0) {
                printf("\nThe factorised expression is:%d(%dx+%d)(x%d)",ex,a,j,i);
            }
            if (j<0&&i>0) {
                printf("\nThe factorised expression is:%d(%dx%d)(x+%d)",ex,a,j,i);
            }
            if (j<0&&i<0) {
                printf("\nThe factorised expression is:%d(%dx%d)(x%d)",ex,a,j,i);
            }
        }
        /*The situation that ex it equal to 0*/
        else
        {
            if (j>0&&i>0) {
                printf("\nThe factorised expression is:(%dx+%d)(x+%d)",a,j,i);
            }
            if (j>0&&i<0) {
                printf("\nThe factorised expression is:(%dx+%d)(x%d)",a,j,i);
            }
            if (j<0&&i>0) {
                printf("\nThe factorised expression is:(%dx%d)(x+%d)",a,j,i);
            }
            if (j<0&&i<0) {
                printf("\nThe factorised expression is:(%dx%d)(x%d)",a,j,i);
            }
        }

    }
    else {
        //step one
        //if c>0 and b>0
        if (c>0 && b>0) {
            for (i=0;i<=c; i++) {
                
                
                if (c==i*(b-i)) {
                    break;
                }
                
            }
            if ((b-i)>=0) {
                printf("\nfactor1=%d\nfactor2=%d\n",i,b-i);
                printf("\nThe factorised expression is:(x+%d)(x+%d)\n",i,b-i);
            }
            else
                printf("\nThe expression can not be factorised!\n");
        }
        //step two
        //if c>0 and b<0
        if (c>0 && b<0) {
            for (i=0;i>=(-c); i--) {
                
                
                if (c==i*(b-i)) {
                    break;
                }
                
            }
            if ((b-i)<=0) {
                printf("\nfactor1=%d\nfactor2=%d\n",i,b-i);
                printf("\nThe factorised expression is:(x%d)(x%d)\n",i,b-i);
            }
            else
                printf("\nThe expression can not be factorised!\n");
        }
        //step three
        //if c<0
        if (c<0) {
            for (i=0;i<=fabs(c); i++) {
                
                
                if (c==i*(b-i)) {
                    break;
                }
                
            }
            if (i<=fabs(c)) {
                printf("\nfactor1=%d\nfactor2=%d\n",i,b-i);
                printf("\nThe factorised expression is:(x+%d)(x%d)\n",i,b-i);
            }
            else
                printf("\nThe expression can not be factorised!\n");
        }

    }
    char pause;
    pause=getchar();
    getchar();
    if (pause=='r') {
        goto loop;
    }
}






/*Calculate the greatest common divisor 
 Function*/
int divisor3(int a,int b,int c)
{
    static int i;
    for (i=a; i>0; i--) {
        if ((a%i==0)&&(b%i==0)&&(c%i==0)) {
            break;
        }
    }
    return i;
}
/*function2*/
int divisor2(int a,int b)
{
    static int i;
    for (i=a; i>0; i--) {
        if ((a%i==0)&&(b%i==0)) {
            break;
        }
    }
    return i;
}
