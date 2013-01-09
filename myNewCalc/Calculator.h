//
//  Calculator.h
//  exercise_calculator
//
//  Created by eamars on 13/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DEFAULT_CAPACITY 60
#define FLOAT_NUM(d) [NSNumber numberWithDouble:d]
#define ERROR_INDEX -1
#define ERROR_PRIORITY -1



@interface Calculator : NSObject


- (id) initWithEquation: (NSMutableArray *)targetEquation;
- (NSMutableArray *) returnEquation;
- (BOOL) isKindOfOperator: (NSString *)op;
- (void) seekOperatorOfEquation;
- (NSInteger) seekIndexOfInterest;
- (unsigned int) getPriorityOfOperator: (NSString *)op;
- (double) processSingleEquation: (NSInteger) index;

- (BOOL) isMostSimpleFormat;

- (BOOL) replaceSingleEquation: (NSInteger) index;
- (NSNumber *) calculation;

@end


