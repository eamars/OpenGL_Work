//
//  main.c
//  md5_Test
//
//  Created by eamars on 9/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <time.h>
#include "md5_hash.h"

static const char *const version = "MD5 Hash v1.3 (based on libmd5-rfc 2002)";
static const char *const usage = "usage: md5 \n[-s string] [-f file ...] [-cf/-cs checkMD5sum] [-v version] [-? help]";
static const char *const usage_check = "usage: md5 [-cf File MD5sum] [-cs String MD5sum]";
static const char *const illegal_option = "md5: illegal option";
static const char *const illegal_string = "md5: illegal string";
static const char *const noFileFound = "md5: No such file";


int main(int argc, const char * argv[])
{
    
    if (argc == 2) { 
        if (strcmp(argv[1], "-v") == 0) {
            printf("%s\n",version);
        }
        else if (strcmp(argv[1], "-s") == 0) {
            printf("MD5 (\"\") = %s\n", md5hash(""));
        }
        else if (strcmp(argv[1], "-f") == 0){
            printf("%s\n", illegal_option);
            printf("%s\n", usage);
        }
        else if (strcmp(argv[1], "-?") == 0){
            printf("%s\n", usage);
        }
        else if (strcmp(argv[1], "-cf") == 0){
            printf("%s\n", usage_check);
        }
        else if (strcmp(argv[1], "-cs") == 0){
            printf("%s\n", usage_check);
        }
        else{
            printf("%s %s\n", illegal_option, argv[1]);
            printf("%s\n",usage);
        }
    }
    else if (argc == 3){
        if (strcmp(argv[1], "-s") == 0) {
            printf("MD5 (\"%s\") = %s\n", argv[2], md5hash(argv[2]));
        }
        else if (strcmp(argv[1], "-f") == 0){
            clock_t start,end;
            start = clock();
            printf("MD5 (%s) = %s\n", argv[2], hash_file(argv[2]));
            end = clock();
            printf("Hash in %f sec\n",(float)(end-start)/CLOCKS_PER_SEC);
        }
        else if (strcmp(argv[1], "-cf") == 0){
            printf("%s\n", usage_check);
        }
        else if (strcmp(argv[1], "-cs") == 0){
            printf("%s\n", usage_check);
        }
        else{
            printf("%s (\"%s\")", illegal_string, argv[2]);
            printf("%s\n", usage);
        }
    }
    else if (argc == 4){
        if (strcmp(argv[1], "-cf") == 0 ) {
            if (strcmp(hash_file(argv[2]), argv[3]) == 0) {
                printf("It seems to be all right\n");
            }
            else
                printf("File Dismatch\n");
        }
        else if (strcmp(argv[1], "-cs") == 0 ) {
            if (strcmp(md5hash(argv[2]), argv[3]) == 0) {
                printf("It seems to be all right\n");
            }
            else
                printf("String Dismatch\n");
        }
    }
    else{
        printf("%s\n", illegal_option);
        printf("%s\n", usage);
    }
    
    
    
    return 0;
}

