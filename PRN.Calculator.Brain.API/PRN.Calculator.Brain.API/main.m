//
//  main.m
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INTCalculatorBrain.h"
#import "RPNCalculatorBrain.h"

#define N(d) [NSNumber numberWithDouble:d]

int main(int argc, const char * argv[])
{

	@autoreleasepool {
	    
	    
		NSMutableArray *myEquation1 = [NSMutableArray alloc];
		myEquation1 = [NSMutableArray arrayWithObjects:@"sinr", @"(", N(2), @"+", N(3), @")", nil];
		
		NSMutableArray *myEquation2 = [NSMutableArray alloc];
		myEquation2 = [NSMutableArray arrayWithObjects:N(3), @"+", N(4), nil];
		
		NSMutableArray *myEquation3 = [NSMutableArray alloc];
		myEquation3 = [NSMutableArray arrayWithObjects:N(3),  @"*", @"fac", N(5), @"+", N(20) ,nil];
		
		NSMutableArray *myEquation4 = [NSMutableArray alloc];
		myEquation4 = [NSMutableArray arrayWithObjects:@"neg", N(3), @"+", N(9),nil];
		
		
		NSMutableArray *myEquation5 = [NSMutableArray alloc];
		myEquation5 = [NSMutableArray arrayWithObjects:@"F_sum", @"(",N(3), @",", N(4),@")",@"+", N(9),nil];

		// sample
		INTCalculatorBrain *myCalc2 = [[INTCalculatorBrain alloc] init];
		[myCalc2 setINTEquation:myEquation5];
		NSLog(@"%@", [myCalc2 returnEquation]);
		
		[myCalc2 transformToRPN];
		NSLog(@"equation: %@", [myCalc2 returnEquation]);
		
		NSLog(@"error:%@", [myCalc2 getError]);
		
		NSArray *func1 = [NSArray arrayWithObjects:@"a", @"b", @"+",nil];
		[myCalc2 setCustomFunctions:@"F_sum" withFunction:func1];
		//NSLog(@"customF: %@", [myCalc2 returnCustomFunctions]);

		[myCalc2 performCalculation];
		NSLog(@"result = %@", [myCalc2 returnEquation]);
		
	}
    return 0;
}

