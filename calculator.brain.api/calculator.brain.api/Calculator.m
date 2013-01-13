//
//  Calculator.m
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//


#import <math.h>
#import "Math_Extented.h"
#import "Calculator.h"

#define PI 3.141592654
#define EXP 2.718281828
#define DEFAULT_CAPACITY 60

// old version
#define FLOAT_NUM(d) [NSNumber numberWithDouble:d]

// new version
#define N(d) [NSNumber numberWithDouble:d]
#define X(d) [[self.equation objectAtIndex:d] doubleValue]

#define ERROR_INDEX -1
#define ERROR_PRIORITY -1

@interface Calculator ()

// private methods
- (void) seekOperatorOfEquation;
- (NSInteger) seekIndexOfInterest;
- (unsigned int) getPriorityOfOperator: (NSString *)op;
- (double) processSingleEquation: (NSInteger) index;

- (void) processEquationByOperatorForStatOnly;

- (BOOL) isKindOfOperator: (NSString *)op;
- (BOOL) isKindOfSpecialOperator: (NSString *)op;
- (BOOL) isKindOfBasicOperator: (NSString *)op;
- (BOOL) isKindOfBracket: (NSString *)op;
- (BOOL) isMostSimpleFormat;
- (BOOL) replaceSingleEquation: (NSInteger) index;

// Output misc.
@property (nonatomic, strong) NSString *errorInfo;
@property (nonatomic, strong) NSString *equationString;

// Math misc.
/* 
 degree YES
 radian NO
 */
@property (readonly, strong) NSDictionary *defaultCalculatorSettings;
@property (nonatomic, strong) NSMutableDictionary *myCalculatorSettings;

@end




@implementation Calculator
{
    NSMutableArray *operators;
    NSNumber *result;
}

@synthesize equation = _equation;
@synthesize myCalculatorSettings = _myCalculatorSettings;
@synthesize errorInfo = _errorInfo;
@synthesize equationString = _equationString;
@synthesize defaultCalculatorSettings = _defaultCalculatorSettings;

- (NSDictionary *) defaultCalculatorSettings
{
	if (!_defaultCalculatorSettings) {
		_defaultCalculatorSettings = [[NSDictionary alloc] initWithObjectsAndKeys:@"radian", @"angle", @"math", @"mode", @"disable", @"frequency", nil];
		
	}
	return _defaultCalculatorSettings;
}

- (NSDictionary *) myCalculatorSettings
{
	if (!_myCalculatorSettings) {
		_myCalculatorSettings = [[NSMutableDictionary alloc] initWithDictionary:self.defaultCalculatorSettings copyItems:YES];
	}
	return _myCalculatorSettings;
}

- (BOOL) setCalculatorArgument:(NSString *)argu WithValue:(NSString *)value
{
	NSArray *allKeys = [self.myCalculatorSettings allKeys];
	for (NSString *key in allKeys) {
		if ([argu isEqualToString:key]) {
			[self.myCalculatorSettings setValue:value forKey:argu];
			return YES;
		}
	}
	return NO;
}

- (NSDictionary *) returnCalculatorSettings
{
	return [self.myCalculatorSettings copy];
}

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
	// the returned equation cannot be modified
    return [self.equation copy];
}

- (NSString *) equationString
{
    if (!_equationString) {
        _equationString = [[NSString alloc] init];
    }
    return _equationString;
}

- (NSString *) returnEquationAsAString
{
    return self.equationString;
}

- (void) setEquation:(NSMutableArray *)equation
{
    _equation = equation;
}

- (void) pushToEquationStack:(id)operand
{
    [self.equation addObject:operand];
}

- (void) cleanEquation
{
    if (self.equation != nil) {
        // clean stack
        [self.equation removeAllObjects];
        
        // clean string
        self.equationString = @"";
        
    }
}

- (void) cleanStatisticsOperator
{
	if (self.equation != nil) {
		if (self.equation.count > 0) {
			if ([self.equation.lastObject isKindOfClass:[NSString class]] == YES) {
				[self.equation removeLastObject];
			}
		}
	}
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
    else if ([op isEqualToString:@"neg"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"log"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"ln"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"fac"] == YES){
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
    else if ([op isEqualToString:@"neg"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"log"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"ln"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"fac"] == YES){
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
     "sqrt", "sin", "cos", "tan", "neg", "log", "ln", "fac"
     
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
    else if ([op isEqualToString:@"neg"] == YES){
        return 3;
    }
	else if ([op isEqualToString:@"log"] == YES){
        return 3;
    }
	else if ([op isEqualToString:@"ln"] == YES){
        return 3;
    }
	else if ([op isEqualToString:@"fac"] == YES){
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
	if (index >= 1) {
		if ([[self.equation objectAtIndex:index - 1] isKindOfClass:[NSString class]] == NO) {
			return INFINITY;
		}
		op = [NSString stringWithString:[self.equation objectAtIndex:index - 1]];
	}
	else
		return INFINITY;
    
    // Check if it's special operator
    if ([self isKindOfSpecialOperator:op] == NO) {
        
        /* Process with the normal operator
         eg: +, -, *, /
         return f1 op f2
         */
        
        //process
		if (index >= 2) {
			n1 = [self.equation objectAtIndex:index - 2];
			n2 = [self.equation objectAtIndex:index];
		}
		else
			return INFINITY;
        
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
		if (index >= 0) {
			n1 = [self.equation objectAtIndex:index];
			f1 = [n1 doubleValue];
		}
		else
			return INFINITY;
        
        // sqrt
        if ([op isEqualToString:@"sqrt"] == YES) {
            return sqrt(f1);
        }
		
		// negative
		else if ([op isEqualToString:@"neg"] == YES){
            return - f1;
        }
		
		// log2(f1)
		else if ([op isEqualToString:@"log"] == YES){
			return log10(f1);
		}
		
		// loge(f1)
		else if ([op isEqualToString:@"ln"] == YES){
			return log(f1);
		}
		
		// fac(f1)
		else if ([op isEqualToString:@"fac"] == YES){
			return fac(f1);
		}
		
		// trigonometric function
        else if ([op isEqualToString:@"sin"] == YES){
			if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
				// convert f1 to degrees
				f1 = f1 * (PI / 180.0);
			}
			else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"grad"] == YES) {
				// convert f1 to grads
				f1 = f1 * (PI / 200.0);
			}
			return sin(f1);
        }
        else if ([op isEqualToString:@"cos"] == YES){
			if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
				// convert f1 to degrees
				f1 = f1 * (PI / 180.0);
			}
			else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"grad"] == YES) {
				// convert f1 to grads
				f1 = f1 * (PI / 200.0);
			}
            return cos(f1);
        }
        else if ([op isEqualToString:@"tan"] == YES){
			if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
				// convert f1 to degrees
				f1 = f1 * (PI / 180.0);
			}
			else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"grad"] == YES) {
				// convert f1 to grads
				f1 = f1 * (PI / 200.0);
			}
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
	if (index >= 1) {
		op = [NSString stringWithString:[self.equation objectAtIndex:index - 1]];
	}
	else
		return NO;
    
    
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
				if (index >= 3) {
					[self.equation removeObjectAtIndex:index - 3];
				}
				else
					return NO;
            
            }
            [self.equation insertObject:result atIndex:index - 3];
        }
        else{
            for (int i = 0; i < 3; i++) {
				if (index >= 2) {
					[self.equation removeObjectAtIndex:index - 2];
				}
				else
					return NO;
            
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
				if (index >= 2) {
					[self.equation removeObjectAtIndex:index - 2];
				}
				else
					return NO;
            
            }
            [self.equation insertObject:result atIndex:index - 2];
        }
        else{
            for (int i = 0; i < 2; i++) {
				if (index >= 1) {
					[self.equation removeObjectAtIndex:index - 1];
				}
				else
					return NO;
            
            }
            [self.equation insertObject:result atIndex:index - 1];
        }
        
    }
    //NSLog(@"%@", equation);
    return YES;
    
}

- (void) processEquationByOperatorForStatOnly
{
	// we assume lastObject is a NSString Class
	// can be verified by equationIsValid method
	NSString *op = self.equation.lastObject;
	
	// find sum and sum for freq for general use
	double sumValue = 0;
	double sumOfFreq = 0;
	double meanValue = 0;
	
	if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"disable"] == YES) {
		for (NSInteger i = 0; i < self.equation.count - 1; i += 1) {
			sumValue = sumValue + X(i);
		}
		sumOfFreq = self.equation.count - 1;
	}
	else if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"enable"] == YES) {
		for (NSInteger i = 0; i < self.equation.count - 1; i += 2) {
			sumValue = sumValue + X(i) * X(i + 1);
			sumOfFreq = sumOfFreq + X(i + 1);
		}
	}
	
	meanValue = sumValue / sumOfFreq;
	
	if ([op isEqualToString:@"min"] == YES) {
		double minValue = X(0);
		if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"disable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 1) {
				if (minValue > X(i)) {
					minValue = X(i);
				}
			}
		}
		else if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"enable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 2) {
				if (minValue > X(i)) {
					minValue = X(i);
				}
			}
		}
		
		
		result = [NSNumber numberWithDouble:minValue];
	}
	
	else if ([op isEqualToString:@"max"] == YES) {
		double maxValue = X(0);
		if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"disable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 1) {
				if (maxValue < X(i)) {
					maxValue = X(i);
				}
			}
		}
		else if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"enable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 2) {
				if (maxValue < X(i)) {
					maxValue = X(i);
				}
			}
		}
		
		result = N(maxValue);
	}
	
	else if ([op isEqualToString:@"sum"] == YES) {
		result = N(sumValue);
	}
	
	else if ([op isEqualToString:@"mean"] == YES) {
		result = N(meanValue);
	}
	
	else if ([op isEqualToString:@"sd"] == YES) {
		// find sum of (xn - u)^2
		double sdValue = 0;
		double sumValue2 = 0;
		
		if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"disable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 1) {
				for (NSInteger i = 0; i < self.equation.count - 1; i += 1) {
					sumValue2 = sumValue2 + (X(i) - meanValue) * (X(i) - meanValue);
				}
			}
		}
		else if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"enable"] == YES) {
			for (NSInteger i = 0; i < self.equation.count - 1; i += 2) {
				for (NSInteger i = 0; i < self.equation.count - 1; i += 2) {
					sumValue2 = sumValue2 + (X(i) - meanValue) * (X(i) - meanValue);
				}
			}
		}
		
		sdValue = sqrt(sumValue2 / sumOfFreq);
		result = N(sdValue);
	}
	else
		result = nil;
	
}

- (NSNumber *) calculation
{
    if (self.equation == nil) {
        return nil;
    }
    
	// Math calculation
	if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"math"] == YES)
	{
		NSInteger index;
		while ([self isMostSimpleFormat] == NO) {
			index = [self seekIndexOfInterest];
			if (index == ERROR_INDEX) {
				NSLog(@"ERROR_INDEX");
				return nil;
			}
			if (![self replaceSingleEquation:index]) {
				NSLog(@"ERROR ARRAY");
				return nil;
			}
		}
	}
	
	
	// Statistics calculation
    else if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"stat"] == YES) {
		// incompletement
		[self processEquationByOperatorForStatOnly];
	}
	
		
	
    return result;
}

- (BOOL) isKindOfBasicOperator:(NSString *)op
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
    else if ([op isEqualToString:@"^"] == YES){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isKindOfBracket:(NSString *)op
{
    //NSLog(@"op is %@", op);
    if ([op isEqualToString:@"("] == YES){
        return YES;
    }
    else if ([op isEqualToString:@")"] == YES){
        return YES;
    }
    else
        return NO;
}

- (NSString *) errorInfo
{
    if (!_errorInfo) {
        _errorInfo = [[NSString alloc] init];
        _errorInfo = @"#0:NO ERROR";
    }
    return _errorInfo;
}

- (BOOL) isKindOfSet1: (id)object
{
    if ([object isKindOfClass:[NSNumber class]] == YES) {
        return YES;
    }
    else if ([object isKindOfClass:[NSString class]] == YES){
        if ([object isEqualToString:@"("] == YES) {
            return YES;
        }
        else if ([object isEqualToString:@")"] == YES) {
            return YES;
        }
        else
            return NO;
    }
    else
        return NO;
}

- (BOOL) isKindOfStatisticsOperator: (NSString *) op
{
	if ([op isEqualToString:@"sum"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"max"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"min"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"mean"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"sd"] == YES){
        return YES;
    }
	
	return NO;
}

- (BOOL) equationIsValid
{
	/* Math part
	 verify the validation of equation
	 Math equation structure
	 Number, Operator, Number, Operator ... , Number
	 */
	if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"math"] == YES) {
		// make string copy
		for (id object in self.equation) {
			self.equationString = [self.equationString stringByAppendingFormat:@"%@ ", object];
		}
		
		// have equation in stack
		if ([self.equation count] == 0) {
			self.errorInfo = @"#1:no target equation";
			return NO;
		}
		// equal bracket
		unsigned short int leftBracketCount = 0, rightBracketCount = 0;
		for (id object in self.equation) {
			if ([object isKindOfClass:[NSString class]]) {
				if ([object isEqualToString:@"("] == YES) {
					++ leftBracketCount;
				}
				if ([object isEqualToString:@")"] == YES) {
					++ rightBracketCount;
				}
			}
		}
		if (leftBracketCount != rightBracketCount) {
			self.errorInfo = @"#2:unpaired bracket";
			return NO;
		}
		
		NSInteger leftIndex = 0, rightIndex = 0, localIndex = 0;
		
		// no sign in paired bracket
		for (id object in self.equation) {
			++ localIndex;
			if ([object isKindOfClass:[NSString class]]) {
				if ([object isEqualToString:@"("] == YES) {
					leftIndex = localIndex;
				}
				if ([object isEqualToString:@")"] == YES) {
					rightIndex = localIndex;
				}
				if (rightIndex - leftIndex < 4 && rightIndex - leftIndex > 0) {
					self.errorInfo = @"#3:sign error";
					return NO;
				}
			}
		}
		
		// connected signs
		leftIndex = 0;
		rightIndex = 0;
		localIndex = 0;
		
		for (id object in self.equation) {
			++ localIndex;
			if ([object isKindOfClass:[NSString class]]) {
				if ([self isKindOfBasicOperator:object]) {
					leftIndex = localIndex;
					if (leftIndex - rightIndex < 2) {
						self.errorInfo = @"#4:sign error";
						return NO;
					}
					rightIndex = leftIndex;
				}
			}
		}
		
		// no argument for special operator
		localIndex = 0;
		
		for (id object in self.equation) {
			++ localIndex;
			if ([object isKindOfClass:[NSString class]]) {
				if ([self isKindOfSpecialOperator:object]) {
					if ([self isKindOfSet1:[self.equation objectAtIndex:localIndex]] == NO) {
						self.errorInfo = @"#5:no argument";
						return NO;
					}
				}
			}
		}
		
		
		// pass
		NSInteger numberCount = 0, basicOperatorCount = 0;
		for (id object in self.equation) {
			if ([object isKindOfClass:[NSNumber class]] == YES) {
				++ numberCount;
			}
			else if ([object isKindOfClass:[NSString class]] == YES) {
				if ([self isKindOfBasicOperator:object] == YES) {
					++ basicOperatorCount;
				}
			}
		}
		if (numberCount - basicOperatorCount == 1) {
			return YES;
		}

	}
	
	/* Statistics Part
	 Statistics equation structure
	 Number, Freq, Number, Freq, Number, Freq, Operator
	 */
	else if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"stat"] == YES) {
		// have equation in stack
		if ([self.equation count] == 0) {
			self.errorInfo = @"#6:no target stack";
			return NO;
		}
		
		// have operator at the end of stack
		if ([self.equation.lastObject isKindOfClass:[NSString class]] == YES) {
			if ([self isKindOfStatisticsOperator:self.equation.lastObject] == NO) {
				self.errorInfo = @"#7:unrecognized operator";
				return NO;
			}
		}
		else {
			self.errorInfo = @"#8:unrecognized operator";
			return NO;
		}
		
		
		// have at least on number
		if ([[self.equation objectAtIndex:0] isKindOfClass:[NSNumber class]] == NO) {
			self.errorInfo = @"#9:no number in stack";
			return NO;
		}
		
		// Have number|frequency mathched(for frequency enabled only)
		if ([[self.myCalculatorSettings objectForKey:@"frequency"] isEqualToString:@"enabled"] == YES) {
			if ((self.equation.count - 1) % 2 != 0) {
				self.errorInfo = @"#10:number and frequency not matched";
				return NO;
			}
		}
		
		
		// pass
		BOOL allAreNumbers = YES;
		for (NSInteger i = 0; i < self.equation.count - 1; ++ i) {
			if ([[self.equation objectAtIndex:i] isKindOfClass:[NSNumber class]] == NO) {
				allAreNumbers = NO;
			}
		}
		if (allAreNumbers == YES) {
			return YES;
		}
		else{
			self.errorInfo = @"#11:not a statistics equation";
			return NO;
		}
	}
    
    
    self.errorInfo = @"#-1:unknown error";
    return NO;
}

- (NSString *) getError
{
    return self.errorInfo;
}

@end
