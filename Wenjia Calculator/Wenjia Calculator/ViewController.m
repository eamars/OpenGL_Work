//
//  ViewController.m
//  Calculator
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

#import "ViewController.h"
#import "INTCalculatorBrain.h"

#define N(d) [NSNumber numberWithDouble:d]
#define C(d) [NSString stringWithFormat:@"%c", d]

@interface ViewController ()
@property (nonatomic) BOOL isInTheMiddleOfTyping;
@property (nonatomic, strong) INTCalculatorBrain *myCalculator;
@property (nonatomic, strong) NSString *numberString;
@property (nonatomic, strong) NSDictionary *defaultCalculatorSettings;
@property (nonatomic, strong) NSDictionary *myCalculatorSettings;
@property (nonatomic, strong) NSMutableArray *myEquation;

@property (nonatomic, strong) NSNumber *answerFromLastCalculation;

@property (weak, nonatomic) IBOutlet UITextField *nameOfCustomFunction;
@property (weak, nonatomic) IBOutlet UITextField *contentOfCustomFunction;


@end



@implementation ViewController

@synthesize display = _display;
@synthesize resultDisplay = _resultDisplay;
@synthesize configurationDisplay = _configurationDisplay;

@synthesize isInTheMiddleOfTyping = _isInTheMiddleOfTyping;
@synthesize myCalculator = _myCalculator;
@synthesize numberString = _numberString;
@synthesize myCalculatorSettings = _myCalculatorSettings;
@synthesize defaultCalculatorSettings = _defaultCalculatorSettings;
@synthesize answerFromLastCalculation = _answerFromLastCalculation;

@synthesize nameOfCustomFunction = _nameOfCustomFunction;
@synthesize contentOfCustomFunction = _contentOfCustomFunction;

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
	return YES;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	
	// Do any additional setup after loading the view, typically from a nib.
    [self updateConfigureStatus];
	self.display.text = @"0";
	self.resultDisplay.text = @"";
	
	// set background
	self.view.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"view_pattern_background_faded.png"]];
	
	self.display.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"display_background.png"]];
	self.resultDisplay.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"display_background.png"]];
	self.configurationDisplay.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"display_background.png"]];
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
	self.configurationDisplay.text = @" ";
	
	// angle mode display
	if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [DEG]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"radian"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [RAD]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"grad"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [GRA]"];
	}
	
	// calculator mode display
	if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"math"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [MTH]"];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"mode"] isEqualToString:@"stat"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [STA]"];
	}
	
	// if have ans in memory
	if ([[self.myCalculatorSettings objectForKey:@"ans"] isEqualToString:@"enable"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@" [ANS]"];
	}
	
	else if ([[self.myCalculatorSettings objectForKey:@"ans"] isEqualToString:@"disable"]) {
		self.configurationDisplay.text = [self.configurationDisplay.text stringByAppendingString:@""];
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

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)digitPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    NSString *digit = sender.currentTitle;
    // append digit to display string
    if (self.isInTheMiddleOfTyping) {
        self.display.text = [self.display.text stringByAppendingString:digit];
    }
    else{
        self.display.text = digit;
        self.isInTheMiddleOfTyping = YES;
    }
    
    // append digit to number string
    self.numberString = [self.numberString stringByAppendingString:digit];
    //NSLog(@"%f", [self.numberString doubleValue]);
    
}

- (IBAction)operationPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
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
    if ([sender.currentTitle isEqualToString:@"+"] == YES) {
        op = @"+";
    }
    else if ([sender.currentTitle isEqualToString:@"-"] == YES){
        op = @"-";
    }
    else if ([sender.currentTitle isEqualToString:@"×"] == YES){
        op = @"*";
    }
    else if ([sender.currentTitle isEqualToString:@"÷"] == YES){
        op = @"/";
    }
	else if ([sender.currentTitle isEqualToString:@"^"] == YES){
        op = @"^";
    }
	else
		op = sender.currentTitle;
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
	[self.myEquation addObject:op];
}

- (IBAction)internalFunctionPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
	
	if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
	
	//clean number string
    self.numberString = @"";
	
	
	// for RanInt, if, add a left bracket
	if ([sender.currentTitle isEqualToString:@"RanInt#"] || [sender.currentTitle isEqualToString:@"if"]) {
		self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
		self.display.text = [self.display.text stringByAppendingString:@"("];
		
		[self.myEquation addObject:sender.currentTitle];
		[self.myEquation addObject:@"("];
	}
	
	
	// for nCr, only append C and push C into stack
	else if ([sender.currentTitle isEqualToString:@"nCr"]) {
		self.display.text = [self.display.text stringByAppendingString:@"C"];
		[self.myEquation addObject:@"C"];
	}
	
	// for equal, only push 'equal' not '=='
	else if ([sender.currentTitle isEqualToString:@"=="]) {
		self.display.text = [self.display.text stringByAppendingString:@"=="];
		[self.myEquation addObject:@"equal"];
	}
	
	// and
	else if ([sender.currentTitle isEqualToString:@"∧"]) {
		self.display.text = [self.display.text stringByAppendingString:@"∧"];
		[self.myEquation addObject:@"and"];
	}
	
	else if ([sender.currentTitle isEqualToString:@"∨"]) {
		self.display.text = [self.display.text stringByAppendingString:@"∨"];
		[self.myEquation addObject:@"or"];
	}
	
	else if ([sender.currentTitle isEqualToString:@"⊻"]) {
		self.display.text = [self.display.text stringByAppendingString:@"⊻"];
		[self.myEquation addObject:@"xor"];
	}
	
	else {
		// append operator sign to display string
		self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
		
		// push operator to equation stack
		[self.myEquation addObject:sender.currentTitle];
	}

}


- (IBAction)specialOperationPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // convert symbol
    NSString *op;
    if ([sender.currentTitle isEqualToString:@"√"]) {
        op = @"sqrt";
    }
    else if ([sender.currentTitle isEqualToString:@"-"]){
        op = @"neg";
    }
	else if ([sender.currentTitle isEqualToString:@"sin"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"sind";
		}
		else
			op = @"sinr";
	}
	else if ([sender.currentTitle isEqualToString:@"cos"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"cosd";
		}
		else
			op = @"cosr";
	}
	else if ([sender.currentTitle isEqualToString:@"tan"]){
		if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"] == YES) {
			op = @"tand";
		}
		else
			op = @"tanr";
	}
    else
        op = sender.currentTitle;
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
	[self.myEquation addObject:op];
	
}

- (IBAction)bracketPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
	[self.myEquation addObject:sender.currentTitle];
}

- (IBAction)constantValuePressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if ([sender.currentTitle isEqualToString:@"e"] == YES) {
        // set current number string to constant value
        self.numberString = @"2.718281828";
        
        // append operator sign to display string
        self.display.text = [self.display.text stringByAppendingString:@"e"];
    }
    else if ([sender.currentTitle isEqualToString:@"π"] == YES){
        // set current number string to constant value
        self.numberString = @"3.141592654";
        
        // append operator sign to display string
        self.display.text = [self.display.text stringByAppendingString:@"π"];
    }
	else if ([sender.currentTitle isEqualToString:@"Ans"] == YES){
        // set current number string to constant value
        self.numberString = [self.answerFromLastCalculation stringValue];
        
        // append operator sign to display string
        self.display.text = [self.display.text stringByAppendingString:@"Ans"];
    }
	
	
	
}

- (IBAction)equalPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
	
	// push equation stack to calculator
	[self.myCalculator setINTEquation:self.myEquation];
	
	// convert to RPN equation
	if (![self.myCalculator transformToRPN]) {
		self.resultDisplay.text = [self.myCalculator getError];
	}
	
	// perform calculaton
	else {
		[self.myCalculator performCalculation];
		NSLog(@"func = %@", [self.myCalculator returnEquation]);
		// if failed
		if ([[self.myCalculator returnEquation] count] > 2) {
			self.resultDisplay.text = @"FAILED";
		}
		else {
			double result = [[[self.myCalculator returnEquation] lastObject] doubleValue];
			// save to ans
			self.answerFromLastCalculation = N(result);
			
			// display result
			self.resultDisplay.text = [NSString stringWithFormat:@"%0.8g", result];
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

- (IBAction)cleanPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
    // clean process
    
    // clean display string
    self.display.text = @"0";
    self.resultDisplay.text = @"";
    
    // set to default typing status
    self.isInTheMiddleOfTyping = NO;
    
    // set number string
    self.numberString = @"";
    
    // clean equation
    [self.myCalculator cleanEquation];
	[self.myEquation removeAllObjects];
    
}

- (IBAction)changeAnglePressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
	if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"radian"]) {
		[self setCalculatorArgument:@"angle" WithValue:@"degree"];
		[self updateConfigureStatus];
	}
	else if ([[self.myCalculatorSettings objectForKey:@"angle"] isEqualToString:@"degree"]) {
		[self setCalculatorArgument:@"angle" WithValue:@"radian"];
		[self updateConfigureStatus];
	}
}

- (IBAction)addPressed {
#ifdef DEBUG
	NSLog(@"key = %@", @"add");
#endif
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
	
    
    //clean number string
    self.numberString = @"";
	
	// function check
	BOOL isValid = YES;
	
	// if no name add
	if ([self.nameOfCustomFunction.text isEqualToString:@"F_"]) {
		self.resultDisplay.text = @"No name add";
		isValid = NO;
	}
	
	// invalid name
	if ([self.nameOfCustomFunction.text length] > 10) {
		self.resultDisplay.text = @"Name must shorter than 10 characters";
		isValid = NO;
	}
	
	// invalid name
	if ([self.nameOfCustomFunction.text characterAtIndex:0] != 'F' || [self.nameOfCustomFunction.text characterAtIndex:1] != '_') {
		self.resultDisplay.text = @"Name must start with F_";
		isValid = NO;
	}
	
	// if no function add
	if ([self.contentOfCustomFunction.text isEqualToString:@""]) {
		self.resultDisplay.text = @"No function add";
		isValid = NO;
	}
	
	if ([self.contentOfCustomFunction.text length] > 80) {
		self.resultDisplay.text = @"Function too long";
		isValid = NO;
	}
	
	// add function
	if (isValid ) {
		NSMutableArray *function = [[NSMutableArray alloc] initWithCapacity:50];
		/*
		 for (unsigned int i = 0; i < [self.contentOfCustomFunction.text length]; ++ i) {
		 [function addObject:C([self.contentOfCustomFunction.text characterAtIndex:i])];
		 }
		 */
		
		NSString *op = [[NSString alloc] init];
		for (unsigned int i = 0; i < [self.contentOfCustomFunction.text length]; ++ i) {
			if ([self.contentOfCustomFunction.text characterAtIndex:i] != ',') {
				op = [op stringByAppendingString:C([self.contentOfCustomFunction.text characterAtIndex:i])];
			}
			else {
				//NSLog(@"opValue = %g", [op doubleValue]);
				if ([op doubleValue]) {
					[function addObject:N([op doubleValue])];
				}
				else
					[function addObject:op];
				op = @"";
			}
		}
		if (![op isEqualToString:@""]) {
			[function addObject:op];
		}
		
		NSLog(@"func = %@", function);
		
		[self.myCalculator setCustomFunctions:self.nameOfCustomFunction.text withFunction:[function copy]];
		
		// append on string
		self.display.text = [self.display.text stringByAppendingString:self.nameOfCustomFunction.text];
		self.display.text = [self.display.text stringByAppendingString:@"("];
		
		// push operator to equation stack
		[self.myEquation addObject:self.nameOfCustomFunction.text];
		[self.myEquation addObject:@"("];
	}

}

- (IBAction)separaterPressed:(UIButton *)sender {
#ifdef DEBUG
	NSLog(@"key = %@", sender.currentTitle);
#endif
	if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if (![self.numberString isEqualToString:@""]) {
		[self.myEquation addObject:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
	
	// append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
	[self.myEquation addObject:sender.currentTitle];
}


@end
