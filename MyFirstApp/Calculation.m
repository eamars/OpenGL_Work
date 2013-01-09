//
//  Calculation.m
//  exercise_calculator
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import "Calculation.h"

@implementation Calculation

@synthesize number;


- (void)setNum:(double)value
{
    number = value;
}

- (void)clear
{
    number = 0;
}

- (double)value
{
    return number;
}

- (id)initWithNum:(double)value
{
    self = [super self];
    if (self) {
        [self setNum:value];
    }
    return self;
}

- (id)init
{
    return [self initWithNum:0];
}

- (NSString *)convertToString
{
    return [NSString stringWithFormat:@"%f", number];
}

- (Calculation *)add:(Calculation *)value
{
    Calculation *result = [[Calculation alloc] init];
    result.number = number + value.number;
    return result;
}

- (Calculation *)subtract:(Calculation *)value
{
    Calculation *result = [[Calculation alloc] init];
    result.number = number - value.number;
    return result;
}

- (Calculation *)multiply:(Calculation *)value
{
    Calculation *result = [[Calculation alloc] init];
    result.number = number * value.number;
    return result;
}

- (Calculation *)divide:(Calculation *)value
{
    Calculation *result = [[Calculation alloc] init];
    result.number = number / value.number;
    return result;
}


@end
