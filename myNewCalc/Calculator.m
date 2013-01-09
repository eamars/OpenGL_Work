//
//  Calculator.m
//  exercise_calculator
//
//  Created by eamars on 13/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//
#import <math.h>
#import "Calculator.h"

@implementation Calculator
{
    NSMutableArray *equation;
    NSMutableArray *operators;
    NSNumber *result;
}

- (id) initWithEquation: (NSMutableArray *)targetEquation
{
    self = [super init];
    if (self) {
        equation = [NSMutableArray arrayWithCapacity:DEFAULT_CAPACITY];
        operators = [NSMutableArray arrayWithCapacity:DEFAULT_CAPACITY];
        equation = targetEquation;
    }
    return self;
    
}

- (NSMutableArray *) returnEquation
{
    return equation;
}

- (BOOL) isKindOfOperator:(NSString *)op
{
    if ([op isEqualToString:@"+"] == YES) {
        return YES;
    }
    else if ([op isEqualToString:@"-"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"*"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"/"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"("] == YES){
        return YES;
    }
    else if ([op isEqualToString:@")"] == YES){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isMostSimpleFormat
{
    if ([equation count] == 1) {
        //NSLog(@"The most simple format");
        return YES;
    }
    else
        return NO;
}

- (void) seekOperatorOfEquation
{
    /*
     only NSString object and is also an operator can be received
     */
    operators = [NSMutableArray array];
    for (id object in equation) {
        if ([object isKindOfClass:[NSString class]] == YES ) {
            if ([self isKindOfOperator:object] == YES) {
                [operators addObject:object];
            }
            
            //NSLog(@"%@", object);
        }
    }
}

- (unsigned int) getPriorityOfOperator:(NSString *)op
{
    if ([op isEqualToString:@"("] || [op isEqualToString:@")"]) {
        return 0;
    }
    else if ([op isEqualToString:@"*"] || [op isEqualToString:@"/"]){
        return 2;
    }
	else if ([op isEqualToString:@"+"] || [op isEqualToString:@"-"]){
    	return 1;
	}
	else
		return ERROR_PRIORITY;
}

- (NSInteger) seekIndexOfInterest
{
    unsigned int isInsideBracket = 0;
    
    // get signs in equation
    [self seekOperatorOfEquation];
    
    // check if the bracket is valid
    unsigned int leftBracket = 0, rightBracket = 0;
    for (NSString *op in operators) {
        if ([op isEqualToString:@"("] == YES) {
            ++ leftBracket;
        }
        if ([op isEqualToString:@")"] == YES) {
            ++ rightBracket;
        }
    }
    if (leftBracket != rightBracket) {
        /* when the equation is invalid
         such as the miss of one bracket, return an error value
         */
        return ERROR_INDEX;
    }
    
    //NSLog(@"left = %u, right = %u", leftBracket, rightBracket);
    
    
    /* get marks of each operator
     Operator "("         = 10 * n
     Operator "*" or "/"  = 2
     Operator "+" or "-"  = 1
     */
    NSInteger index = 0;
    unsigned int mark;
    unsigned int maxMark = 0;
    NSInteger maxMarkIndex = 0;
    
    for (NSString *op in operators) {
        ++ index;
        
        if ([op isEqualToString:@"("] == YES) {
            ++ isInsideBracket;
        }
        if ([op isEqualToString:@")"] == YES) {
            -- isInsideBracket;
        }
        if ([op isEqualToString:@"("] || [op isEqualToString:@")"]) {
            continue; // skip if operator is bracket
        }
        
        mark = [self getPriorityOfOperator:op] + isInsideBracket * 10;
        //NSLog(@"%d", mark);
        if (mark > maxMark) {
            maxMark = mark;
            maxMarkIndex = index;
        }
        
    }
    
    //NSLog(@"MAXMARK = %d at index = %ld is %@", maxMark, maxMarkIndex, [operators objectAtIndex:maxMarkIndex - 1]); // index starts at 0
    
    
    index = 0;
    NSInteger indexInEquation = 0;
    for (id object in equation) {
        ++ indexInEquation;
        if ([object isKindOfClass:[NSString class]] == YES) {
            ++ index;
        }
        if (index == maxMarkIndex) {
            break;
        }
    }
    //NSLog(@"index = %ld is %@", indexInEquation, [equation objectAtIndex:indexInEquation - 1]);
    
    return indexInEquation;
}

- (double) processSingleEquation:(NSInteger)index
{
    double f1, f2;
    NSNumber *n1, *n2;
    NSString *op;
    
    //check if operator is valid
    if ([[equation objectAtIndex:index - 1] isKindOfClass:[NSString class]] == NO) {
        return INFINITY;
    }
    
	op = [NSString stringWithString:[equation objectAtIndex:index - 1]];
    //NSLog(@"index %ld is %@",index, op);
    
    
    //process
    n1 = [equation objectAtIndex:index - 2];
    n2 = [equation objectAtIndex:index];
    //NSLog(@"n1 = %@ n2 = %@", n1, n2);
    
    f1 = [n1 doubleValue];
    f2 = [n2 doubleValue];
    
    //add
    if ([op isEqualToString:@"+"] == YES) {
        return f1 + f2;
    }
    //subtract
    else if ([op isEqualToString:@"-"] == YES){
        return f1 - f2;
    }
	else if ([op isEqualToString:@"*"] == YES){
    	return f1 * f2;
	}
	else if ([op isEqualToString:@"/"] == YES){
    	return f1 / f2;
	}
	else
		return INFINITY;
}

- (BOOL) replaceSingleEquation:(NSInteger) index
{
    
    result = [NSNumber numberWithDouble:[self processSingleEquation:index]];
    
    // check if the equation is in bracket
    BOOL isEnclosedBracket = NO;
    if (index > 2 && index < [equation count] + 1) {
        if ([[equation objectAtIndex:index - 3] isEqualToString:@"("] == YES) {
            if ([[equation objectAtIndex:index + 1] isEqualToString:@")"] == YES) {
                isEnclosedBracket = YES;
            }
        }
    }
    
    //NSLog(@"%@", equation);
    
    //remove previous equation
    if (isEnclosedBracket == YES) {
        for (int i = 0; i < 5; i++) {
            [equation removeObjectAtIndex:index - 3];
        }
        [equation insertObject:result atIndex:index - 3];
    }
    else{
        for (int i = 0; i < 3; i++) {
            [equation removeObjectAtIndex:index - 2];
        }
		[equation insertObject:result atIndex:index - 2];
    }

    //NSLog(@"%@", equation);
    return YES;
    
}

- (NSNumber *) calculation
{
    NSInteger index;
    while ([self isMostSimpleFormat] == NO) {
        index = [self seekIndexOfInterest];
        [self replaceSingleEquation:index];
    }
    return result;
}



@end
