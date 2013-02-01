//
//  INTCalculatorBrain+ShuntingYardAlgorithm.m
//  PRN.Calculator.Brain.API
//
//  Created by Ran Bao on 1/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "INTCalculatorBrain+ShuntingYardAlgorithm.h"

@implementation INTCalculatorBrain (ShuntingYardAlgorithm)

- (int) getPrecedenceOfOperator:(NSString *) op
{
	if ([op isEqualToString:@"fac"]) {
		return 4;
	}
	else if ([op isEqualToString:@"^"]) {
		return 4;
	}
	else if ([op isEqualToString:@"sinr"]) {
		return 4;
	}
	else if ([op isEqualToString:@"cosr"]) {
		return 4;
	}
	else if ([op isEqualToString:@"tanr"]) {
		return 4;
	}
	else if ([op isEqualToString:@"sind"]) {
		return 4;
	}
	else if ([op isEqualToString:@"cosd"]) {
		return 4;
	}
	else if ([op isEqualToString:@"tand"]) {
		return 4;
	}
	else if ([op isEqualToString:@"*"]) {
		return 3;
	}
	else if ([op isEqualToString:@"/"]) {
		return 3;
	}
	else if ([op isEqualToString:@"%"]) {
		return 3;
	}
	else if ([op isEqualToString:@"+"]) {
		return 2;
	}
	else if ([op isEqualToString:@"-"]) {
		return 2;
	}
	else
		return 0;
}

- (BOOL) getLeftAssociativity:(NSString *) op
{
	if ([op isEqualToString:@"fac"]) {
		return NO;
	}
	else if ([op isEqualToString:@"^"]) {
		return NO;
	}
	else if ([op isEqualToString:@"sinr"]) {
		return NO;
	}
	else if ([op isEqualToString:@"cosr"]) {
		return NO;
	}
	else if ([op isEqualToString:@"tanr"]) {
		return NO;
	}
	else if ([op isEqualToString:@"sind"]) {
		return NO;
	}
	else if ([op isEqualToString:@"cosd"]) {
		return NO;
	}
	else if ([op isEqualToString:@"tand"]) {
		return NO;
	}
	else if ([op isEqualToString:@"*"]) {
		return YES;
	}
	else if ([op isEqualToString:@"/"]) {
		return YES;
	}
	else if ([op isEqualToString:@"%"]) {
		return YES;
	}
	else if ([op isEqualToString:@"+"]) {
		return YES;
	}
	else if ([op isEqualToString:@"-"]) {
		return YES;
	}
	else
		return NO;
}

- (BOOL) isKindOfFunctionMark:(id)functionMark
{
	if ([functionMark isKindOfClass:[NSString class]]) {
		if ([functionMark length] == 1) {
			if ([functionMark characterAtIndex:0] >= 'A' && [functionMark characterAtIndex:0] <= 'Z') {
				return YES;
			}
			return NO;
		}
		else
			return NO;
	}
	else
		return NO;
	
}

- (BOOL) isKindOfIdentifier:(id) identifier
{
	if ([identifier isKindOfClass:[NSString class]]) {
		if ([identifier length] == 1) {
			if ([identifier characterAtIndex:0] >= 'a' && [identifier characterAtIndex:0] <= 'z') {
				return YES;
			}
			return NO;
		}
		else
			return NO;
	}
	else
		return NO;
	
}

- (BOOL) isKindOfOperator:(id) op
{
	if ([op isKindOfClass:[NSString class]]) {
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
		else if ([op isEqualToString:@"sqrt"] == YES){
			return YES;
		}
		else if ([op isEqualToString:@"^"] == YES){
			return YES;
		}
		else if ([op isEqualToString:@"sinr"]) {
			return YES;
		}
		else if ([op isEqualToString:@"cosr"]) {
			return YES;
		}
		else if ([op isEqualToString:@"tanr"]) {
			return YES;
		}
		else if ([op isEqualToString:@"sind"]) {
			return YES;
		}
		else if ([op isEqualToString:@"cosd"]) {
			return YES;
		}
		else if ([op isEqualToString:@"tand"]) {
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
	else
		return NO;
    
}

- (BOOL) isLeftBracket:(id) op
{
	if ([op isKindOfClass:[NSString class]]) {
		if ([op isEqualToString:@"("]) {
			return YES;
		}
		else
			return NO;
	}
	else
		return NO;
}

- (BOOL) isRightBracket:(id) op
{
	if ([op isKindOfClass:[NSString class]]) {
		if ([op isEqualToString:@")"]) {
			return YES;
		}
		else
			return NO;
	}
	else
		return NO;
}

@end
