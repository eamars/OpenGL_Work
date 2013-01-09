//
//  Calculator.m
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//


#import <math.h>
#import "Calculator.h"

@interface Calculator ()

// private
- (void) seekOperatorOfEquation;
- (NSInteger) seekIndexOfInterest;
- (unsigned int) getPriorityOfOperator: (NSString *)op;
- (double) processSingleEquation: (NSInteger) index;

- (BOOL) isKindOfOperator: (NSString *)op;
- (BOOL) isKindOfSpecialOperator: (NSString *)op;
- (BOOL) isMostSimpleFormat;
- (BOOL) replaceSingleEquation: (NSInteger) index;

@end

@implementation Calculator
{
    NSMutableArray *operators;
    NSNumber *result;
}

@synthesize equation = _equation;

- (id) init
{
    return [self initWithEquation:[NSMutableArray array]];
}


- (id) initWithEquation: (NSMutableArray *)targetEquation
{
    self = [super init];
    if (self) {
        self.equation = [NSMutableArray arrayWithCapacity:DEFAULT_CAPACITY];
        operators = [NSMutableArray arrayWithCapacity:DEFAULT_CAPACITY];
        self.equation = targetEquation;
    }
    return self;
    
}

- (NSMutableArray *) returnEquation
{
    return self.equation;
}

- (void) pushEquation:(NSMutableArray *)targetEquation
{
    self.equation = targetEquation;
}

- (void) setEquation:(NSMutableArray *)equation
{
    _equation = equation;
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
    else if ([op isEqualToString:@"sqrt"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"^"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"sin"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"cos"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"tan"] == YES){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isKindOfSpecialOperator:(NSString *)op
{
    if ([op isEqualToString:@"sqrt"] == YES) {
        return YES;
    }
    else if ([op isEqualToString:@"sin"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"cos"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"tan"] == YES){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isMostSimpleFormat
{
    if ([self.equation count] == 1) {
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
    for (id object in self.equation) {
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
    /* priority list
     0:
     "(", ")"
     
     1:
     "+", "-"
     
     2:
     "*", "/"
     
     3:
     "sqrt", "sin", "cos", "tan"
     
     4:
     "^"
     */
    
    if ([op isEqualToString:@"("] || [op isEqualToString:@")"]) {
        return 0;
    }
    else if ([op isEqualToString:@"^"] == YES){
        return 4;
    }
    else if ([op isEqualToString:@"sqrt"] == YES){
        return 3;
    }
    else if ([op isEqualToString:@"sin"] == YES){
        return 3;
    }
    else if ([op isEqualToString:@"cos"] == YES){
        return 3;
    }
    else if ([op isEqualToString:@"tan"] == YES){
        return 3;
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
    unsigned int leftBracketCount = 0, rightBracketCount = 0;
    for (NSString *op in operators) {
        if ([op isEqualToString:@"("] == YES) {
            ++ leftBracketCount;
        }
        if ([op isEqualToString:@")"] == YES) {
            ++ rightBracketCount;
        }
    }
    if (leftBracketCount != rightBracketCount) {
        /* when the equation is invalid
         such as the miss of one bracket, return an error value
         */
        return ERROR_INDEX;
    }
    
    //NSLog(@"left = %u, right = %u", leftBracket, rightBracket);
    
    /* get marks of each operator
     Operator "("         = 10 * n
     Operator "sqrt"      = 3
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
    for (id object in self.equation) {
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
    if ([[self.equation objectAtIndex:index - 1] isKindOfClass:[NSString class]] == NO) {
        return INFINITY;
    }
    
    op = [NSString stringWithString:[self.equation objectAtIndex:index - 1]];
    //NSLog(@"index %ld is %@",index, op);
    
    // Check if it's special operator
    if ([self isKindOfSpecialOperator:op] == NO) {
        
        /* Process with the normal operator
         eg: +, -, *, /
         return f1 op f2
         */
        
        //process
        n1 = [self.equation objectAtIndex:index - 2];
        n2 = [self.equation objectAtIndex:index];
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
        else if ([op isEqualToString:@"^"] == YES){
            return pow(f1, f2);
        }
        else
            return INFINITY;
    }
    else{
        
        /* Process with special operator
         eg: sqrt
         return sqrt f1
         */
        
        // process
        n1 = [self.equation objectAtIndex:index];
        f1 = [n1 doubleValue];
        
        // sqrt
        if ([op isEqualToString:@"sqrt"] == YES) {
            return sqrt(f1);
        }
        else if ([op isEqualToString:@"sin"] == YES){
            return sin(f1);
        }
        else if ([op isEqualToString:@"cos"] == YES){
            return cos(f1);
        }
        else if ([op isEqualToString:@"tan"] == YES){
            return tan(f1);
        }
        else
            return INFINITY;
        
    }
    
    
}

- (BOOL) replaceSingleEquation:(NSInteger) index
{
    
    result = [NSNumber numberWithDouble:[self processSingleEquation:index]];
    BOOL isEnclosedBracket = NO;
    
    //NSLog(@"%@", equation);
    
    // Check if special operator
    NSString *op;
    op = [NSString stringWithString:[self.equation objectAtIndex:index - 1]];
    
    if ([self isKindOfSpecialOperator:op] == NO) {
        
        // check if the equation is in bracket
        if (index > 2 && index < [self.equation count] + 1) {
            if ([[self.equation objectAtIndex:index - 3] isEqualToString:@"("] == YES) {
                if ([[self.equation objectAtIndex:index + 1] isEqualToString:@")"] == YES) {
                    isEnclosedBracket = YES;
                }
            }
        }
        
        
        //remove previous equation
        if (isEnclosedBracket == YES) {
            for (int i = 0; i < 5; i++) {
                [self.equation removeObjectAtIndex:index - 3];
            }
            [self.equation insertObject:result atIndex:index - 3];
        }
        else{
            for (int i = 0; i < 3; i++) {
                [self.equation removeObjectAtIndex:index - 2];
            }
            [self.equation insertObject:result atIndex:index - 2];
        }
    }
    else{
        if (index > 1 && index < [self.equation count]) {
            if ([[self.equation objectAtIndex:index - 2] isEqualToString:@"("] == YES) {
                if ([[self.equation objectAtIndex:index + 1] isEqualToString:@")"] == YES) {
                    isEnclosedBracket = YES;
                }
            }
        }
        
        //remove previous equation
        if (isEnclosedBracket == YES) {
            for (int i = 0; i < 4; i++) {
                [self.equation removeObjectAtIndex:index - 2];
            }
            [self.equation insertObject:result atIndex:index - 2];
        }
        else{
            for (int i = 0; i < 2; i++) {
                [self.equation removeObjectAtIndex:index - 1];
            }
            [self.equation insertObject:result atIndex:index - 1];
        }
        
    }
    //NSLog(@"%@", equation);
    return YES;
    
}

- (NSNumber *) calculation
{
    NSInteger index;
    while ([self isMostSimpleFormat] == NO) {
        index = [self seekIndexOfInterest];
        if (index == ERROR_INDEX) {
            NSLog(@"ERROR_INDEX");
            return nil;
        }
        [self replaceSingleEquation:index];
    }
    return result;
}



@end
