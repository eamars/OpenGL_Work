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
		myEquation2 = [NSMutableArray arrayWithObjects:N(3), N(5), @"+", N(2), @"*", nil];
		
		NSMutableArray *myEquation3 = [NSMutableArray alloc];
		myEquation3 = [NSMutableArray arrayWithObjects:@"fac", N(5),nil];
		
		NSMutableArray *myEquation4 = [NSMutableArray alloc];
		myEquation4 = [NSMutableArray arrayWithObjects:@"neg", N(3), @"+",nil];
		
		
		NSMutableArray *myEquation5 = [NSMutableArray alloc];
		myEquation5 = [NSMutableArray arrayWithObjects:@"F_pv", @"(",N(3), @",", N(5), @")",nil];
		
		NSMutableArray *myEquation6 = [NSMutableArray alloc];
		myEquation6 = [NSMutableArray arrayWithObjects:@"Ran#",nil];
		
		NSMutableArray *myEquation7 = [NSMutableArray alloc];
		myEquation7 = [NSMutableArray arrayWithObjects:@"RanInt#", @"(", N(1), N(3), @")",nil];
		
		NSMutableArray *myEquation8 = [NSMutableArray alloc];
		myEquation8 = [NSMutableArray arrayWithObjects:N(YES), @"xor", N(YES),nil];
		

		// sample
		INTCalculatorBrain *myCalc2 = [[INTCalculatorBrain alloc] init];
		[myCalc2 setINTEquation:myEquation8];
		NSLog(@"%@", [myCalc2 returnEquation]);
		
		[myCalc2 transformToRPN];
		NSLog(@"equation: %@", [myCalc2 returnEquation]);
		
		NSLog(@"error:%@", [myCalc2 getError]);
		
		
		 //Sample: set custom function
		NSArray *func1 = [NSArray arrayWithObjects:@"a", @"b", @"+", @"2", @"*",nil];
		[myCalc2 setCustomFunctions:@"F_pv" withFunction:func1];
		
		
		
		[myCalc2 performCalculation];
		NSLog(@"result = %@", [myCalc2 returnEquation]);
		
		
		
	}
    return 0;
}

