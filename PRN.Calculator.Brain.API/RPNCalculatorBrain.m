//
//  RPNCalculatorBrain.m
//  RPN.calculato.brain.api
//
//  Created by Ran Bao on 31/01/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "RPNCalculatorBrain.h"
#import "RPNCalculatorBrain+OperatorSet.h"
#import "math.h"
#import "INTCalculatorBrain.h"

#define N(d) [NSNumber numberWithDouble:d]
#define X(d) [[self.RPNEquation objectAtIndex:d] doubleValue]

@interface RPNCalculatorBrain ()

- (BOOL) popOffOperand:(NSMutableArray *) targetEquation;


@end

@implementation RPNCalculatorBrain

@synthesize RPNEquation = _RPNEquation;
@synthesize customFunctions = _customFunctions;

- (NSMutableDictionary *) customFunctions
{
	if (!_customFunctions) {
		_customFunctions = [[NSMutableDictionary alloc] init];
	}
	return _customFunctions;
}

- (NSMutableArray *) RPNEquation
{
	if (!_RPNEquation) {
		_RPNEquation = [[NSMutableArray alloc] init];
	}
	return _RPNEquation;
}


- (void) setRPNEquation:(NSMutableArray *)RPNEquation
{
	_RPNEquation = RPNEquation;
}

- (void) setCustomFunctions:(NSMutableDictionary *)customFunctions
{
	_customFunctions = customFunctions;
}

- (NSMutableArray *) returnEquation
{
	return [self.RPNEquation mutableCopy];
}

- (void) cleanRPNEquation
{
	if (self.RPNEquation) {
		[self.RPNEquation removeAllObjects];
	}
}

- (void) performCalculation
{
	for (; ![self popOffOperand:self.RPNEquation]; ) {}
}



- (BOOL) popOffOperand:targetEquation
{
	NSString *op;
	NSInteger index = 0;
	
	
	for (id object in targetEquation) {
		if ([object isKindOfClass:[NSString class]]) {
			op = object;
			break;
		}
		++ index;
	}
	
	// no more operand in equation stack, finish calculaton
	if (!op) {
		return YES;
	}
	
	// do the calculation
	double result = 0;
	
	// basic operator
	int numberOfOperand = 0;
	
	if ([self isKindOfOperatorSet1:op]) {
		numberOfOperand = 2;
		if ([op isEqualToString:@"+"]) {
			result = X(index - 1) + X(index - 2);
		}
		else if ([op isEqualToString:@"*"]) {
			result = X(index - 1) * X(index - 2);
		}
		else if ([op isEqualToString:@"^"]) {
			result = pow(X(index - 2), X(index - 1));
		}
		else if ([op isEqualToString:@"-"]) {
			result = X(index - 2) - X(index - 1);
		}
		else if ([op isEqualToString:@"/"]) {
			result = X(index - 2) / X(index - 1);
		}
	}
	else if ([self isKindOfOperatorSet2:op])
	{
		numberOfOperand = 1;
		if ([op isEqualToString:@"sqrt"]) {
			result = sqrt(X(index - 1));
		}
		else if ([op isEqualToString:@"sinr"])
		{
			result = sin(X(index - 1));
		}
		else if ([op isEqualToString:@"sind"])
		{
			result = sin(X(index - 1) * (M_PI / 180.0));
		}
		else if ([op isEqualToString:@"cosr"])
		{
			result = cos(X(index - 1));
		}
		else if ([op isEqualToString:@"cosd"])
		{
			result = cos(X(index - 1) * (M_PI / 180.0));
		}
		else if ([op isEqualToString:@"tanr"])
		{
			result = tan(X(index - 1));
		}
		else if ([op isEqualToString:@"tand"])
		{
			result = tan(X(index - 1) * (M_PI / 180.0));
		}
		else if ([op isEqualToString:@"log"])
		{
			result = log10(X(index - 1));
		}
		else if ([op isEqualToString:@"ln"])
		{
			result = log(X(index - 1));
		}
		else if ([op isEqualToString:@"fac"])
		{
			long product = 1;
			for (register long i = 1; i < X(index - 1); ++i) {
				product = product * i + product;
			}
			result = product;
		}
		else if ([op isEqualToString:@"neg"]) {
			result = - X(index - 1);
		}
	}
	else if ([self isKindOfCustomFunction:op])
	{
		// get custom function
		NSMutableArray *customFunction = [[self.customFunctions valueForKey:op] mutableCopy];
		
		// get number of arguments
		numberOfOperand = (int)[self numberOfArgument:customFunction];
		
		// assign value
		NSInteger count = [customFunction count];
		for (NSInteger i = count - 1, j = numberOfOperand; i >= 0; --i, --j) {
			if ([self isKindOfArgument:[customFunction objectAtIndex:i]]) {
				[customFunction replaceObjectAtIndex:i withObject:[targetEquation objectAtIndex:j]];
			}
		}
		
		
		// perform on custom function
		RPNCalculatorBrain *customCalc = [[RPNCalculatorBrain alloc] init];
		[customCalc setRPNEquation:customFunction];
		[customCalc performCalculation];
		result = [[[customCalc returnEquation] objectAtIndex:0] doubleValue];
		
	}
	
	
	// remove operand, f1, f2
	for (short i = 0; i < numberOfOperand + 1; ++ i) {
		if (self.RPNEquation) {
			[self.RPNEquation removeObjectAtIndex:(index - numberOfOperand)];
		}
	}
	// push result to stack
	[self.RPNEquation insertObject:N(result) atIndex:index -numberOfOperand];
	return NO;
}



@end
