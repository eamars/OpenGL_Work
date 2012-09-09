//
//  savelog.c
//  opengl_five_in_row
//
//  Created by eamars on 6/09/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include "define_data.h"
#include <stdlib.h>
#include <time.h>

void savelog(int switcher)
{
    /*
     it will generate like this:
     
     Gamemode:   Challenge
     LastPlay:   Thu Sep  6 11:40:50 2012
     Winner:     Black
     - - - - - - - - - - - - -
     - - - - - - - - - - - - -
     - - - - X - - - - - - - -
     - - - - O O - - - - - - -
     - - - O O - X - - - - - -
     - - O X O O O X - - - - -
     - - - X O X X - - - - - -
     - - - X X X O - - - - - -
     - - - O O X - - - - - - -
     - - - - - - X - - - - - -
     - - - - - - - X - - - - -
     - - - - - - - - - - - - -
     - - - - - - - - - - - - -
     
     */
    //file
#ifdef __WIN32__
    FILE *fp;
    if ((fp = fopen("autosav.txt", "w+")) == NULL)
    {
        printf("OpenError\n");
        exit(0);
    }
#else
    FILE *fp;
    if ((fp = fopen("autosav", "w+")) == NULL)
    {
        printf("OpenError\n");
        exit(0);
    }
#endif
    
    
    //time
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    /* Gamemode:   Challenge */
    fwrite("Gamemode:  ", 1, sizeof("Gamemode:  "), fp);
    if (mode==1) {
        fwrite("Challenge", 1, sizeof("Challenge"), fp);
        fwrite("\n", 1, 1, fp);
    }
    else if (mode==2){
        fwrite("Duel", 1, sizeof("Duel"), fp);
        fwrite("\n", 1, 1, fp);
    }
    else if (mode==3){
        fwrite("AI Versus", 1, sizeof("AI Versus"), fp);
        fwrite("\n", 1, 1, fp);
    }
    else{
        fwrite("Challenge", 1, sizeof("Challenge"), fp);
        fwrite("\n", 1, 1, fp);
    }
    
    /* LastPlay:   Thu Sep  6 11:40:50 2012 */
    fwrite("LastPlay:  ", 1, sizeof("LastPlay:  "), fp);
    fwrite(asctime(timeinfo), sizeof(asctime(timeinfo)), sizeof(asctime(timeinfo)), fp);
    fwrite("\n", 1, 1, fp);
    
    /* Winner:     Black */
    fwrite("Winner:    ", 1, sizeof("Winner:    "), fp);
    if (win==-1) {
        fwrite("Black", 1, sizeof("Black"), fp);
        fwrite("\n", 1, 1, fp);
    }
    else if (win==1){
        fwrite("White", 1, sizeof("White"), fp);
        fwrite("\n", 1, 1, fp);
    }
    else{
        fwrite("None", 1, sizeof("None"), fp);
        fwrite("\n", 1, 1, fp);
    }
    
    /* 
     - - - - - - - - - - - - -
     - - - - - - - - - - - - -
     - - - - X - - - - - - - -
     - - - - O O - - - - - - -
     - - - O O - X - - - - - -
     - - O X O O O X - - - - -
     - - - X O X X - - - - - -
     - - - X X X O - - - - - -
     - - - O O X - - - - - - -
     - - - - - - X - - - - - -
     - - - - - - - X - - - - -
     - - - - - - - - - - - - -
     - - - - - - - - - - - - -
     
     */
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            fwrite(&board[i][j], 1, 1, fp);
            fwrite(" ", 1, 1, fp);
            
        }
        fwrite("\n", 1, 1, fp);
    }
 	fclose(fp);
    //printf ( "The current date/time is: %s", asctime (timeinfo) );
}