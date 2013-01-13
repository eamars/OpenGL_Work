//
//  Calculator.h
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

/*
 The Calculator Brain only accepts NSNumber and NSString as the array stored in it's stack;
 Main Function:
 	1, Handle a set of numbers and operators, find the result of this equation.
 	2, Find the mean, max, standard deviation of a stack of number.
 
 Version 0.2
 Last update: 14-Jan-2013
 
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
 
 	- (BOOL) setCalculatorArgument:(NSString *)argu WithValue:(NSString *)value;
 		set the argument of calculator. eg: the radian and degree.
 		if not set, use the default configuration.
 		default keys and values
 			key = "angle"     value = "radian"
			key = "mode"      value = "math"
 			key = "frequency" value = "disable"
 
 	- (NSDictionary *) returnCalculatorSettings;
		return the configuration of calculator. if not set, use the default configuration.
 
 Update log:
	11-Jan-2013
 		Affect: - (NSMutableArray *) returnEquation;
 		Description: Return the copy of equation not the equation itself (an inmutable array).
 
		Add: - (BOOL) setCalculatorArgument:(NSString *)argu WithValue:(NSString *)value;
 			- (NSDictionary *) returnCalculatorSettings;
 
		Remove:
 			remove some verification check inside the core - now which is replaced by external methods
 	14-Jan-2013
 		Add: - (void) cleanStatisticsOperator;
 		Description: delete the operator of statistics stack.
 
 		Add: Statistics Function
		Description: the calculator can handle a stack of numbers with operator attached. Use setCalculatorArgument to set statistics avaliable. 
 */

#import <Foundation/Foundation.h>
@interface Calculator : NSObject

@property (nonatomic, strong) NSMutableArray *equation;

// Public methods

// done with equation
- (void) setEquation:(NSMutableArray *)equation;
- (void) pushToEquationStack: (id)operand;
- (void) cleanEquation;
- (void) cleanStatisticsOperator;
- (NSMutableArray *) returnEquation;
- (NSString *) returnEquationAsAString;

// done with calculation
- (NSNumber *) calculation;
- (BOOL) equationIsValid;
- (NSString *) getError;

// set parameters
- (BOOL) setCalculatorArgument:(NSString *)argu WithValue:(NSString *)value;
- (NSDictionary *) returnCalculatorSettings;

@end
