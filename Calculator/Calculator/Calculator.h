//
//  Calculator.h
//  calculator.brain.api
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DEFAULT_CAPACITY 60

// old version
#define FLOAT_NUM(d) [NSNumber numberWithDouble:d]

// new version
#define N(d) [NSNumber numberWithDouble:d]

#define ERROR_INDEX -1
#define ERROR_PRIORITY -1



@interface Calculator : NSObject

@property (nonatomic, strong) NSMutableArray *equation;

- (id) initWithEquation: (NSMutableArray *)targetEquation;
- (void) setEquation:(NSMutableArray *)equation;
- (NSMutableArray *) returnEquation;
- (NSNumber *) calculation;

@end
