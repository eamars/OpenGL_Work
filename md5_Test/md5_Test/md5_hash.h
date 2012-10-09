//
//  md5_hash.h
//  md5_Test
//
//  Created by eamars on 9/10/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#ifndef md5_Test_md5_hash_h
#define md5_Test_md5_hash_h

const char *md5hash (const char *const inputString);
int md5check (const char *const inputString, const char *const hash);
const char *hash_file (const char *const file_dir);
#endif
