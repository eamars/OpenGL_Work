//
//  main.c
//  swap_order
//
//  Created by eamars on 29/08/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define random(x) (rand()%x)


void debug(int sequence[],int length)
{
    for (int i=0; i<length; i++) {
        printf("%d ",sequence[i]);
    }
    printf("\n");
}




int main(int argc, const char * argv[])
{

    srand((int)time(0));
    clock_t start,end;
    
    //generate sequence
    int sequence1[100000];
    int sequence2[100000];
    for (int i=0; i<100000; i++) {
        sequence1[i]=random(100);
		sequence2[i]=sequence1[i];
    }
    
    
    //int sequence1[]={8,10,7,5,0,1,4,6,9,2,2,6,1,7,10,5,4,5,7,2,10,8,4,9,5};
    int length;
    length=sizeof(sequence1)/4;
    printf("length=%d\n",length);

    //debug (sequence1,length);
    printf("Working...\n");
    start=clock();
    //1
    int k;
	int temp;
    for (int i=0; i<length-1; i++) {
        k=i;
        for (int j=i+1; j<length; j++) {
            if (sequence1[j]<sequence1[k]) {
                k=j;
            }
        }
        temp=sequence1[k];
        sequence1[k]=sequence1[i];
        sequence1[i]=temp;
    }
	end=clock();
    
    //debug (sequence1,length);
    
    printf("[ALGOL1=%lfs]\n",(end-start)/(double)CLOCKS_PER_SEC);
    
    printf("Working...\n");
    
    start=clock();
    //2
    for (int j=0; j<length; j++) {
     	for (int i=0; i<length-j; i++) {
     		if (sequence2[i]>sequence2[i+1]) {
     			temp=sequence2[i+1];
     			sequence2[i+1]=sequence2[i];
            	sequence2[i]=temp;
        		}
     		}
     }
    end=clock();
     printf("[ALGOL2=%lfs]\n",(end-start)/(double)CLOCKS_PER_SEC);
    
     
    printf("Complete, press any key to exit!\n");
    
    int pause;
    pause=getchar();
    if (pause==1) {
        for (int i=0; i<length; i++) {
            printf("%d ",sequence1[i]);
        }
    }
    return 0;
}

