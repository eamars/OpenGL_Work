//
//  Calculation.h
//  exercise_calculator
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Calculation : NSObject

@property double number;

// Misc. Methods
- (void)setNum: (double)value;
- (void)clear;
- (double)value;
- (id)init;
- (id)initWithNum: (double)value;

// Convert
- (NSString *)convertToString;

// Arithmetic Methods
- (Calculation *)add: (Calculation *)value;
- (Calculation *)subtract: (Calculation *)value;
- (Calculation *)multiply: (Calculation *)value;
- (Calculation *)divide: (Calculation *)value;



@end
