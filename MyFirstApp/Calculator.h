//
//  Calculator.h
//  exercise_calculator
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Calculation.h"

@interface Calculator : NSObject
@property (strong, nonatomic) Calculation *operand1, *operand2, *accumulator;

- (Calculation *)performOperation: (char)op;
- (void)clear;



@end
