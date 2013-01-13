//
//  main.m
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Calculator.h"
#import "Math_Extented.h"
#define N(d) [NSNumber numberWithDouble:d]

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        /*
        NSMutableArray *myEquation = [NSMutableArray alloc];
        NSMutableArray *myEquation2 = [NSMutableArray alloc];
        NSMutableArray *myEquation3 = [NSMutableArray alloc];
        NSMutableArray *myEquation4 = [NSMutableArray alloc];
        NSMutableArray *myEquation5 = [NSMutableArray alloc];
        
        myEquation = [NSMutableArray arrayWithObjects:FLOAT_NUM(3.0), @"+", FLOAT_NUM(5), @"*", @"(", FLOAT_NUM(2), @"*", @"(", FLOAT_NUM(3), @"/", FLOAT_NUM(6), @")", @")", nil];
        
        myEquation2 = [NSMutableArray arrayWithObjects:@"(", FLOAT_NUM(3), @"+", FLOAT_NUM(4), @")", nil];
        
        myEquation3 = [NSMutableArray arrayWithObjects:@"(", @"sqrt", FLOAT_NUM(4), @")", nil];
        
        myEquation4 = [NSMutableArray arrayWithObjects:FLOAT_NUM(3), @"^", FLOAT_NUM(2), nil];
        
        myEquation5 = [NSMutableArray arrayWithObjects:@"sin", FLOAT_NUM(1), @"+", @"sin", FLOAT_NUM(1), @"*", FLOAT_NUM(3), nil];
        
        
        Calculator *myCalc = [[Calculator alloc] init];
        [myCalc setEquation:myEquation];
        NSLog(@"%@", [myCalc calculation]);
        */
        /*
        Calculator *myCalc2 = [[Calculator alloc] init];
        [myCalc2 setCalculatorArgument:@"angle" WithValue:@"degree"];
		
		[myCalc2 pushToEquationStack:@"ln"];
		[myCalc2 pushToEquationStack:N(5)];
		
		NSLog(@"%@", [myCalc2 returnEquation]);
		
		NSLog(@"%@", [myCalc2 returnCalculatorSettings]);
		
		if ([myCalc2 equationIsValid]) {
			double result = [[myCalc2 calculation] doubleValue];
			NSLog(@"result %0.8f", result);
		}
		else
			NSLog(@"%@", [myCalc2 getError]);
		
		[myCalc2 cleanEquation];
		*/
		
		Calculator *myCalc3 = [[Calculator alloc] init];
		[myCalc3 setCalculatorArgument:@"mode" WithValue:@"stat"];
		[myCalc3 setCalculatorArgument:@"frequency" WithValue:@"enable"];
		NSLog(@"%@", [myCalc3 returnCalculatorSettings]);
		
		[myCalc3 pushToEquationStack:N(1)];
		[myCalc3 pushToEquationStack:N(2)];
		[myCalc3 pushToEquationStack:N(3)];
		[myCalc3 pushToEquationStack:N(4)];
		[myCalc3 pushToEquationStack:@"sd"];
		if ([myCalc3 equationIsValid] == YES) {
			NSLog(@"valid");
			NSLog(@"result = %g", [[myCalc3 calculation] doubleValue]);
		}
		else {
			NSLog(@"%@", [myCalc3 getError]);
			NSLog(@"invalid");
		}
    }
    return 0;
}

