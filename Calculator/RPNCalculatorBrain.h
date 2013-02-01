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

// push the RPN equation into the stack
- (void) setRPNEquation:(NSMutableArray *)RPNEquation;

// clean elements in stack
- (void) cleanRPNEquation;

// return a RPN equation
- (NSMutableArray *) returnEquation;

// perform calculation
- (void) performCalculation;

@end
