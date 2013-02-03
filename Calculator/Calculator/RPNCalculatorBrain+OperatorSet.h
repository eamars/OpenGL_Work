//
//  RPNCalculatorBrain+OperatorSet.h
//  RPN.calculato.brain.api
//
//  Created by Ran Bao on 31/01/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "RPNCalculatorBrain.h"

@interface RPNCalculatorBrain (OperatorSet)

- (BOOL) isKindOfOperatorSet1:(NSString *) op;
- (BOOL) isKindOfOperatorSet2:(NSString *) op;

@end