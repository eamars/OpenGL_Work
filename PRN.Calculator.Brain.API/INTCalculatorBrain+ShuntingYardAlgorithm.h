//
//  INTCalculatorBrain+ShuntingYardAlgorithm.h
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "INTCalculatorBrain.h"

@interface INTCalculatorBrain (ShuntingYardAlgorithm)

- (int) getPrecedenceOfOperator:(NSString *) op;

- (BOOL) getLeftAssociativity:(NSString *) op;

- (BOOL) isKindOfFunctionMark:(id) functionMark;

- (BOOL) isKindOfIdentifier:(id) identifier;

- (BOOL) isKindOfOperator:(id) op;

- (BOOL) isLeftBracket:(id) op;

- (BOOL) isRightBracket:(id) op;

- (BOOL) isKindOfFunctionSeparator:(id) op;

@end
