//
//  Math_Extented.c
//  calculator.brain.api
//
//  Created by Ran Bao on 11/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

#include <math.h>

long fac(long argu)
{
	long product = 1;
	for (register long i = 1; i < argu; ++i) {
		product = product * i + product;
	}
	
	return product;
}

