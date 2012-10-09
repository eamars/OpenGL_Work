//
//  md5_hash.c
//  md5_Test
//
//  Created by eamars on 9/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "md5.h"
#include "md5_hash.h"


const char *md5hash (const char *const inputString)
{
    md5_state_t state;
    md5_byte_t digest[16];
    char hex_output[33];
    
    
    md5_init(&state);
    md5_append(&state, (const md5_byte_t *)inputString, (int)strlen(inputString));
    md5_finish(&state, digest);
    
    for (int di = 0; di<16; ++di) {
        sprintf(hex_output + di * 2, "%02x", digest[di]);
        //printf("MD5 (\"%s\") = ", TestString);
	    //puts(hex_output);
    }
    char *Str = hex_output;
    printf("%s","");
    
    return Str;
}

int md5check (const char *const inputString, const char *const hash)
{
    md5_state_t state;
    md5_byte_t digest[16];
    char hex_output[33];
    
    
    md5_init(&state);
    md5_append(&state, (const md5_byte_t *)inputString, (int)strlen(inputString));
    md5_finish(&state, digest);
    
    for (int di = 0; di<16; ++di) {
        sprintf(hex_output + di * 2, "%02x", digest[di]);
        //printf("MD5 (\"%s\") = ", TestString);
	    //puts(hex_output);
    }
    if (strcmp(hex_output, hash) == 0) {
        return 1;
    }
    else
        return 0;
}

const char *hash_file (const char *const file_dir)
{
    FILE *fp;
    const int DATA_BLOCK = 8192;
    
    if ((fp=fopen(file_dir, "rb"))==NULL){
        printf("ERROR WHILE LOADING\n");
        return 0;
    }
    
    unsigned char data[DATA_BLOCK];
    char hex_output[33];
    md5_state_t Context;
    md5_byte_t digest[16];
    int bytes;
    
    md5_init(&Context);
    while ((bytes = (int)fread (data, 1, DATA_BLOCK, fp)) != 0)
    {
        md5_append(&Context, data, bytes);
    }
    md5_finish(&Context, digest);
    
    for (int di = 0; di<16; ++di) {
        sprintf(hex_output + di * 2, "%02x", digest[di]);
    }
    char *Str = hex_output;
    
    return Str;
    
}

