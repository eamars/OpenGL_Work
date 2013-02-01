//
//  RPNCalculatorBrain+OperatorSet.m
//  RPN.calculato.brain.api
//
//  Created by Ran Bao on 31/01/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "RPNCalculatorBrain+OperatorSet.h"

@implementation RPNCalculatorBrain (OperatorSet)

- (BOOL) isKindOfOperatorSet1:(NSString *)op
{
    if ([op isEqualToString:@"+"] == YES) {
        return YES;
    }
    else if ([op isEqualToString:@"-"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"*"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"/"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"^"] == YES){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isKindOfOperatorSet2:(NSString *)op
{
    if ([op isEqualToString:@"sqrt"] == YES) {
        return YES;
    }
    else if ([op isEqualToString:@"sinr"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"cosr"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"tanr"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"sind"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"cosd"] == YES){
        return YES;
    }
    else if ([op isEqualToString:@"tand"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"log"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"ln"] == YES){
        return YES;
    }
	else if ([op isEqualToString:@"fac"] == YES){
        return YES;
    }
    else
        return NO;
}

@end
