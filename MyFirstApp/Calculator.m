//
//  Calculator.m
//  exercise_calculator
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import "Calculator.h"

@implementation Calculator

@synthesize operand1, operand2, accumulator;

- (id)init
{
    self = [super init];
    if (self) {
        operand1 = [[Calculation alloc] init];
        operand2 = [[Calculation alloc] init];
        accumulator = [[Calculation alloc] init];
    }
    
    return self;
}


- (void) clear
{
    accumulator.number = 0;
}

- (Calculation *)performOperation:(char)op
{
    Calculation *result;
    
    switch (op) {
        case '+':
            result = [operand1 add:operand2];
            break;
            
        case '-':
            result = [operand1 subtract:operand2];
            break;
            
        case '*':
            result = [operand1 multiply:operand2];
            break;
            
        case '/':
            result = [operand1 divide:operand2];
            break;
            
        default:
            break;
            
    }
    return result;
}
@end
