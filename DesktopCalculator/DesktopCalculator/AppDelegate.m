//
//  AppDelegate.m
//  DesktopCalculator
//
//  Created by Ran Bao on 3/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import "AppDelegate.h"
#import "INTCalculatorBrain.h"
#define N(d) [NSNumber numberWithDouble:d]

@interface AppDelegate ()

@property (nonatomic) BOOL isInTheMiddleOfTyping;
@property (nonatomic, strong) INTCalculatorBrain *myCalculator;
@property (nonatomic, strong) NSString *numberString;
@property (nonatomic, strong) NSDictionary *defaultCalculatorSettings;
@property (nonatomic, strong) NSDictionary *myCalculatorSettings;
@property (nonatomic, strong) NSMutableArray *myEquation;

@property (nonatomic, strong) NSNumber *answerFromLastCalculation;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
	[self updateConfigureStatus];
	
	self.display.stringValue = @"0";
	self.resultDisplay.stringValue = @"";
	
}

@synthesize display = _display;
@synthesize resultDisplay = _resultDisplay;
@synthesize configurationDisplay = _configurationDisplay;

@synthesize isInTheMiddleOfTyping = _isInTheMiddleOfTyping;
@synthesize myCalculator = _myCalculator;
@synthesize numberString = _numberString;
@synthesize myCalculatorSettings = _myCalculatorSettings;
@synthesize defaultCalculatorSettings = _defaultCalculatorSettings;
@synthesize answerFromLastCalculation = _answerFromLastCalculation;


- (IBAction)digitPressed:(NSButton *)sender {
	NSString *digit = sender.title;
	// append digit to display string
    if (self.isInTheMiddleOfTyping) {
        self.display.stringValue = [self.display.stringValue stringByAppendingString:digit];
    }
    else{
        self.display.stringValue = digit;
        self.isInTheMiddleOfTyping = YES;
    }
    
    // append digit to number string
    self.numberString = [self.numberString stringByAppendingString:digit];
    //NSLog(@"%f", [self.numberString doubleValue]);
    
}

- (IBAction)operationPressed:(NSButton *)sender {
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.stringValue = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // convert symbol
    NSString *op;
    if ([sender.title isEqualToString:@"+"] == YES) {
        op = @"+";
    }
    else if ([sender.title isEqualToString:@"-"] == YES){
        op = @"-";
    }
    else if ([sender.title isEqualToString:@"×"] == YES){
        op = @"*";
    }
    else if ([sender.title isEqualToString:@"÷"] == YES){
        op = @"/";
    }
	else if ([sender.title isEqualToString:@"^"] == YES){
        op = @"^";
    }
	else
		op = sender.title;
    
    // append operator sign to display string
    self.display.stringValue = [self.display.stringValue stringByAppendingString:sender.title];
    
    // push operator to equation stack
	[self.myEquation addObject:op];
}

- (IBAction)specialOperationPressed:(NSButton *)sender {
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.stringValue = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // convert symbol
    NSString *op;
    if ([sender.title isEqualToString:@"√"]) {
        op = @"sqrt";
    }
    else if ([sender.title isEqualToString:@"-"]){
        op = @"neg";
    }
	else if ([sender.title isEqualToString:@"sin"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"sind";
		}
		else
			op = @"sinr";
	}
	else if ([sender.title isEqualToString:@"cos"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"cosd";
		}
		else
			op = @"cosr";
	}
	else if ([sender.title isEqualToString:@"tan"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"tand";
		}
		else
			op = @"tanr";
	}
    else
        op = sender.title;
    
    // append operator sign to display string
    self.display.stringValue = [self.display.stringValue stringByAppendingString:sender.title];
    
    // push operator to equation stack
	[self.myEquation addObject:op];
}

- (IBAction)bracketPressed:(NSButton *)sender {
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.stringValue = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // append operator sign to display string
    self.display.stringValue = [self.display.stringValue stringByAppendingString:sender.title];
    
    // push operator to equation stack
	[self.myEquation addObject:sender.title];
}

- (IBAction)constantValuePressed:(NSButton *)sender {
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.stringValue = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if ([sender.title isEqualToString:@"e"] == YES) {
        // set current number string to constant value
        self.numberString = @"2.718281828";
        
        // append operator sign to display string
        self.display.stringValue = [self.display.stringValue stringByAppendingString:@"e"];
    }
    else if ([sender.title isEqualToString:@"π"] == YES){
        // set current number string to constant value
        self.numberString = @"3.141592654";
        
        // append operator sign to display string
        self.display.stringValue = [self.display.stringValue stringByAppendingString:@"π"];
    }
	else if ([sender.title isEqualToString:@"Ans"] == YES){
        // set current number string to constant value
        self.numberString = [self.answerFromLastCalculation stringValue];
        
        // append operator sign to display string
        self.display.stringValue = [self.display.stringValue stringByAppendingString:@"Ans"];
    }
}

- (IBAction)equalPressed:(NSButton *)sender {
	// push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
	
	// push equation stack to calculator
	[self.myCalculator setINTEquation:self.myEquation];
	
	// convert to RPN equation
	if (![self.myCalculator transformToRPN]) {
		self.resultDisplay.stringValue = [self.myCalculator getError];
	}
	
	// perform calculaton
	else {
		[self.myCalculator performCalculation];
		
		// if failed
		if ([[self.myCalculator returnEquation] count] > 2) {
			self.resultDisplay.stringValue = @"FAILED";
		}
		else {
			double result = [[[self.myCalculator returnEquation] lastObject] doubleValue];
			// save to ans
			self.answerFromLastCalculation = N(result);
			
			// display result
			self.resultDisplay.stringValue = [NSString stringWithFormat:@"%0.8g", result];
		}
		
	}
    // change status of ANS
	[self setCalculatorArgument:@"ans" WithValue:@"enable"];
	[self updateConfigureStatus];
    
    // clean equation
    [self.myCalculator cleanEquation];
    
    // set to default typing status
    self.isInTheMiddleOfTyping = NO;
}

- (IBAction)cleanPressed:(NSButton *)sender {
	// clean process
    
    // clean display string
    self.display.stringValue = @"0";
    self.resultDisplay.stringValue = @"";
    
    // set to default typing status
    self.isInTheMiddleOfTyping = NO;
    
    // set number string
    self.numberString = @"";
    
    // clean equation
    [self.myCalculator cleanEquation];
	[self.myEquation removeAllObjects];
}

- (IBAction)changeAnglePressed:(NSButton *)sender {
	if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"radian"]) {
		[self setCalculatorArgument:@"angle" WithValue:@"degree"];
		[self updateConfigureStatus];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"]) {
		[self setCalculatorArgument:@"angle" WithValue:@"radian"];
		[self updateConfigureStatus];
	}
}

- (NSNumber *) answerFromLastCalculation
{
	if (!_answerFromLastCalculation) {
		_answerFromLastCalculation = [[NSNumber alloc] initWithDouble:0];
	}
	return _answerFromLastCalculation;
}

- (NSDictionary *) defaultCalculatorSettings
{
	if (!_defaultCalculatorSettings) {
		_defaultCalculatorSettings = [[NSDictionary alloc] initWithObjectsAndKeys:@"radian", @"angle", @"math", @"mode", @"disable", @"frequency", @"disable", @"ans", nil];
		
	}
	return _defaultCalculatorSettings;
}

- (NSDictionary *) myCalculatorSettings
{
	if (!_myCalculatorSettings) {
		_myCalculatorSettings = [[NSMutableDictionary alloc] initWithDictionary:self.defaultCalculatorSettings copyItems:YES];
	}
	return _myCalculatorSettings;
}

- (BOOL) setCalculatorArgument:(NSString *)argu WithValue:(NSString *)value
{
	NSArray *allKeys = [self.myCalculatorSettings allKeys];
	for (NSString *key in allKeys) {
		if ([argu isEqualToString:key]) {
			[self.myCalculatorSettings setValue:value forKey:argu];
			return YES;
		}
	}
	return NO;
}

- (NSMutableArray *) myEquation
{
	if (!_myEquation) {
		_myEquation = [[NSMutableArray alloc] initWithCapacity:80];
	}
	return _myEquation;
}

- (void) updateConfigureStatus
{
	self.configurationDisplay.stringValue = @" ";
	
	// angle mode display
	if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [DEG]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"radian"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [RAD]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"grad"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [GRA]"];
	}
	
	// calculator mode display
	if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"math"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [MTH]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"stat"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [STA]"];
	}
	
	// if have ans in memory
	if ([[self.myCalculatorSettings objectForKey:@"ans"] isEqualToString:@"enable"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@" [ANS]"];
	}
	
	else if ([[self.myCalculatorSettings objectForKey:@"ans"] isEqualToString:@"disable"]) {
		self.configurationDisplay.stringValue = [self.configurationDisplay.stringValue stringByAppendingString:@""];
	}
}

- (INTCalculatorBrain *) myCalculator
{
    if (!_myCalculator) {
        _myCalculator = [[INTCalculatorBrain alloc] init];
    }
    return _myCalculator;
}

- (NSString *) numberString
{
    if (!_numberString) {
        _numberString = [[NSString alloc] init];
    }
    return _numberString;
}


@end
