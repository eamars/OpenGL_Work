//
//  INTCalculatorBrain.h
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef DEBUG
#define API_VERSION @"1.2.1A"
#else
#define API_VERSION @"1.2.1B"
#endif

@interface INTCalculatorBrain : NSObject

@property (nonatomic, strong) NSMutableArray *INTEquation;


// push INT equation into stack
- (void) setINTEquation:(NSMutableArray *)INTEquation;

// clean the elements in stack
- (void) cleanEquation;

// return the equation as an array
- (NSMutableArray *) returnEquation;

// get error when transforming from INTEquation to RPNEquation
- (NSString *) getError;

// convert to RPN equation
- (BOOL) transformToRPN;

// do the calculation
- (void) performCalculation;

// EXPERIMENT: set the custom function
- (void) setCustomFunctions:(NSString *) name withFunction:(NSArray *) function;

// return the custom function stack
- (NSMutableDictionary *) returnCustomFunctions;

@end
