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
    if ([op isEqualToString:@"+"]) {
        return YES;
    }
    else if ([op isEqualToString:@"-"]){
        return YES;
    }
    else if ([op isEqualToString:@"*"]){
        return YES;
    }
    else if ([op isEqualToString:@"/"]){
        return YES;
    }
	else if ([op isEqualToString:@"^"]){
        return YES;
    }
    else
        return NO;
}

- (BOOL) isKindOfOperatorSet2:(NSString *)op
{
    if ([op isEqualToString:@"sqrt"]) {
        return YES;
    }
    else if ([op isEqualToString:@"sinr"]){
        return YES;
    }
    else if ([op isEqualToString:@"cosr"]){
        return YES;
    }
    else if ([op isEqualToString:@"tanr"]){
        return YES;
    }
	else if ([op isEqualToString:@"sind"]){
        return YES;
    }
    else if ([op isEqualToString:@"cosd"]){
        return YES;
    }
    else if ([op isEqualToString:@"tand"]){
        return YES;
    }
	else if ([op isEqualToString:@"log"]){
        return YES;
    }
	else if ([op isEqualToString:@"ln"]) {
        return YES;
    }
	else if ([op isEqualToString:@"fac"]) {
        return YES;
    }
	else if ([op isEqualToString:@"neg"]) {
		return YES;
	}
    else
        return NO;
}


- (BOOL) isKindOfCustomFunction:(NSString *)op
{
	NSArray *allKeys = [self.customFunctions allKeys];
	for (NSString *key in allKeys) {
		if ([op isEqualToString:key]) {
			return YES;
		}
	}
	return NO;
}

- (NSInteger) numberOfArgument:(NSArray *)function
{
	NSInteger n = 0;
	for (id object in function) {
		if ([object isKindOfClass:[NSString class]]) {
			if ([object characterAtIndex:0] >= 'a' && [object characterAtIndex:0] <= 'z') {
				++ n;
			}
		}
	}
	return n;
}

- (BOOL) isKindOfArgument:(id)ag
{
	if ([ag isKindOfClass:[NSString class]]) {
		if ([ag characterAtIndex:0] >= 'a' && [ag characterAtIndex:0] <= 'z') {
			return YES;
		}
		else
			return NO;
	}
	else
		return NO;
}


@end
