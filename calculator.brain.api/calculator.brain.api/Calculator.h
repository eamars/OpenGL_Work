//
//  Calculator.h
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

/*
 The Calculator Brain only accepts NSNumber and NSString as the array stored in it's stack;
 
 Pubic Methods:
 	N(d): 
 		convert a double value into a NSNumber type.
 
 	- (void) setEquation:(NSMutableArray *)equation
 		set the equation with a given set of array.
 
 	- (void) pushToEquationStack: (id)operand
        push a single element into equation stack.
 
 	- (NSMutableArray *) returnEquation;
 		return the equation as a set of array.
 
 	- (NSNumber *) calculation;
 		do the calculation steps, must have an equation in stack.
 
 	- (void) cleanEquation;
 		remove all objects in equation.
 
 	- (BOOL) equationIsValid;
 		verify if the equation is valid, return an boolean value.
 
 	- (NSString *) getError;
 		return the reason for why the equation is invalid.
 */

#import <Foundation/Foundation.h>

#define DEFAULT_CAPACITY 60

// old version
#define FLOAT_NUM(d) [NSNumber numberWithDouble:d]

// new version
#define N(d) [NSNumber numberWithDouble:d]

#define ERROR_INDEX -1
#define ERROR_PRIORITY -1


@interface Calculator : NSObject

@property (nonatomic, strong) NSMutableArray *equation;

- (void) setEquation:(NSMutableArray *)equation;
- (void) pushToEquationStack: (id)operand;
- (void) cleanEquation;
- (NSMutableArray *) returnEquation;
- (NSNumber *) calculation;
- (BOOL) equationIsValid;
- (NSString *) getError;
- (void) set:(NSString *) argu :(NSString *) param;

@end
