//
//  INTCalculatorBrain.h
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INTCalculatorBrain : NSObject

@property (nonatomic, strong) NSMutableArray *INTEquation;

- (void) setINTEquation:(NSMutableArray *)INTEquation;

- (void) cleanEquation;

- (NSMutableArray *) returnEquation;

- (NSString *) getError;

- (BOOL) transformToRPN;

- (void) performCalculation;

@end
