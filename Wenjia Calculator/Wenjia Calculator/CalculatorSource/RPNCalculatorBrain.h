//
//  RPNCalculatorBrain.h
//  RPN.calculato.brain.api
//
//  Created by Ran Bao on 31/01/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RPNCalculatorBrain : NSObject 

@property (nonatomic, strong) NSMutableArray *RPNEquation;
@property (nonatomic, strong) NSMutableDictionary *customFunctions;

// push the RPN equation into the stack
- (void) setRPNEquation:(NSMutableArray *)RPNEquation;

// push custom functions into function set
- (void) setCustomFunctions:(NSMutableDictionary *)customFunctions;

// clean elements in stack
- (void) cleanRPNEquation;

// return a RPN equation
- (NSMutableArray *) returnEquation;

// perform calculation
- (void) performCalculation;

@end
