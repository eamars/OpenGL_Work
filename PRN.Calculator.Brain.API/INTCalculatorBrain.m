//
//  INTCalculatorBrain.m
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "INTCalculatorBrain.h"
#import "RPNCalculatorBrain.h"
#import "INTCalculatorBrain+ShuntingYardAlgorithm.h"

@interface INTCalculatorBrain ()

@property (nonatomic, strong) RPNCalculatorBrain *RPNCalculator;
@property (nonatomic, strong) NSString *errorInfo;


@end

@implementation INTCalculatorBrain

@synthesize INTEquation = _INTEquation;
@synthesize RPNCalculator = _RPNCalculator;

- (NSMutableArray *) INTEquation
{
	if (!_INTEquation) {
		_INTEquation = [[NSMutableArray alloc] initWithCapacity:80];
	}
	return _INTEquation;
}

- (NSString *) errorInfo
{
	if (!_errorInfo) {
		_errorInfo = [[NSString alloc] init];
		_errorInfo = @"no error";
	}
	return _errorInfo;
}

- (RPNCalculatorBrain *) RPNCalculator
{
	if (!_RPNCalculator) {
		_RPNCalculator = [[RPNCalculatorBrain alloc] init];
	}
	return _RPNCalculator;
}

- (void) setINTEquation:(NSMutableArray *)INTEquation
{
	_INTEquation = INTEquation;
}

- (void) cleanEquation
{
	if (self.INTEquation) {
		[self.INTEquation removeAllObjects];
	}
}

- (NSMutableArray *) returnEquation
{
	return [self.INTEquation copy];
}

- (void) performCalculation
{
	[self.RPNCalculator setRPNEquation:self.INTEquation];
	[self.RPNCalculator performCalculation];
	self.INTEquation = [self.RPNCalculator returnEquation];
}

- (BOOL) transformToRPN
{
	
	NSMutableArray *outputQueue, *operatorStack;
	outputQueue = [[NSMutableArray alloc] initWithCapacity:80];
	operatorStack = [[NSMutableArray alloc] initWithCapacity:80];
	
	for (id object in self.INTEquation) {
		// token is a number, push to output queue
		if ([object isKindOfClass:[NSNumber class]]) {
			[outputQueue addObject:object];
		}
		
		// token is a identifier mark, push to output queue
		else if ([self isKindOfIdentifier:object]) {
			[outputQueue addObject:object];
		}
		
		// token is a function mark: eg: F_SUM (a, b, c)
		else if ([self isKindOfFunctionMark:object]) {
			[operatorStack addObject:object];
		}
		
		// If the token is a function argument separator (e.g., a comma):
		else if ([self isKindOfFunctionSeparator:object]) {
			NSString *op;
			
			for (op = [operatorStack lastObject]; ![self isLeftBracket:op]; op = [operatorStack lastObject]) {
				if ([operatorStack count] == 0) {
					self.errorInfo = @"#ERROR03:unpaired bracket";
					return NO;
				}
				[operatorStack removeLastObject];
				[outputQueue addObject:op];
			}
			
		}
		
		
		
		// token is an operator
		else if ([self isKindOfOperator:object]) {
			NSString *op1, *op2;
			op1 = object;
			/*
			op2 = [operatorStack lastObject];
			if (op2) {
				if (([self getLeftAssociativity:op1] && [self getPrecedenceOfOperator:op1] <= [self getPrecedenceOfOperator:op2]) || (![self getLeftAssociativity:op1] && [self getPrecedenceOfOperator:op1] < [self getPrecedenceOfOperator:op2])) {
					[operatorStack removeLastObject];
					[outputQueue addObject:op2];
				}
			}
			*/
			do {
				op2 = [operatorStack lastObject];
				
				if (([self getLeftAssociativity:op1] && [self getPrecedenceOfOperator:op1] <= [self getPrecedenceOfOperator:op2]) || (![self getLeftAssociativity:op1] && [self getPrecedenceOfOperator:op1] < [self getPrecedenceOfOperator:op2])) {
					[operatorStack removeLastObject];
					[outputQueue addObject:op2];
				}
				else
					break;
				
			} while (op2);
			
			// push op1 to top of stack
			[operatorStack addObject:op1];
			
		}
		
		//token is a left bracket
		else if ([self isLeftBracket:object]) {
			[operatorStack addObject:object];
		}
		
		// token is a right bracket
		else if ([self isRightBracket:object]) {
			// secure check need to be done here
			if ([self isLeftBracket:[operatorStack lastObject]]) {
				self.errorInfo = @"#WARNING01:insecure bracket";
			}
			
			NSString *op;
			
			for (op = [operatorStack lastObject]; ![self isLeftBracket:op]; op = [operatorStack lastObject]) {
				if (operatorStack) {
					[operatorStack removeLastObject];
				}
				else
					return YES;
				if (op) {
					[outputQueue addObject:op];
				}
				else
					return YES;
			}
			
			// remove left bracket
			if ([self isLeftBracket:op]) {
				[operatorStack removeLastObject];
			}
			else {
				self.errorInfo = @"#ERROR01:failed to remove left bracket";
				return NO;
			}
				
			
			/*
			while (![self isLeftBracket:[operatorStack lastObject]] && !operatorStack) {
				op = [operatorStack lastObject];
				[operatorStack removeLastObject];
				NSLog(@"op = %@", op);
				[outputQueue addObject:op];
				
			}
			// remove left bracket
			NSLog(@"la = %@", [operatorStack lastObject]);
			[operatorStack removeLastObject];
			*/
			
			// if is a function mark, move to output queue
			op = [operatorStack lastObject];
			if ([self isKindOfFunctionMark:op]) {
				[operatorStack removeLastObject];
				[outputQueue addObject:op];
			}
		}
	}
	
	// error check
	
	if ([self isLeftBracket:[operatorStack lastObject]] || [self isRightBracket:[operatorStack lastObject]]) {
		self.errorInfo = @"#ERROR02:unpaired bracket";
		return NO;
	}
	
	if ([operatorStack count] > 0) {
		NSString *op;
		for (NSInteger i = [operatorStack count]; i > 0; --i) {
			op = [operatorStack lastObject];
			[operatorStack removeLastObject];
			[outputQueue addObject:op];
		}
	}
	
	// replace equation by output queue
	self.INTEquation = [outputQueue mutableCopy];
	
	return YES;
}

- (NSString *) getError
{
	return self.errorInfo;
}

- (void) setCustomFunctions:(NSString *)name withFunction:(NSArray *)function
{
	//NSLog(@"name = %@, func = %@", name, function);
	[[self.RPNCalculator customFunctions] setValue:function forKey:name];
	
}

- (NSMutableDictionary *) returnCustomFunctions
{
	return [[self.RPNCalculator customFunctions] copy];
}

@end
