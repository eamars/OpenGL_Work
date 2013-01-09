//
//  ViewController.m
//  Calculator
//
//  Created by eamars on 9/01/13.
//  Copyright (c) 2013 RanBao. All rights reserved.
//

#import "ViewController.h"
#import "Calculator.h"

@interface ViewController ()
@property (nonatomic) BOOL isInTheMiddleOfTyping;
@property (nonatomic, strong) Calculator *myCalculator;
@property (nonatomic, strong) NSString *numberString;
@end



@implementation ViewController

@synthesize display = _display;
@synthesize resultDisplay = _resultDisplay;
@synthesize statusBar = _statusBar;

@synthesize isInTheMiddleOfTyping = _isInTheMiddleOfTyping;
@synthesize myCalculator = _myCalculator;
@synthesize numberString = _numberString;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    //self.numberString = [[NSString alloc] init];
}

- (Calculator *) myCalculator
{
    if (!_myCalculator) {
        _myCalculator = [[Calculator alloc] init];
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
    
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
        [self.myCalculator pushToEquationStack:N([self.numberString doubleValue])];
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
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
    [self.myCalculator pushToEquationStack:op];
}

- (IBAction)specialOperationPressed:(UIButton *)sender {
    
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    if ([self.numberString isEqualToString:@""] == NO) {
        [self.myCalculator pushToEquationStack:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // convert symbol
    NSString *op;
    if ([sender.currentTitle isEqualToString:@"√"] == YES) {
        op = @"sqrt";
    }
    else if ([sender.currentTitle isEqualToString:@"-"] == YES){
        op = @"neg";
    }
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
    [self.myCalculator pushToEquationStack:op];

}

- (IBAction)bracketPressed:(UIButton *)sender {
    
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
        [self.myCalculator pushToEquationStack:N([self.numberString doubleValue])];
    }
    
    //clean number string
    self.numberString = @"";
    
    // append operator sign to display string
    self.display.text = [self.display.text stringByAppendingString:sender.currentTitle];
    
    // push operator to equation stack
    [self.myCalculator pushToEquationStack:sender.currentTitle];
}

- (IBAction)constantValuePressed:(UIButton *)sender {
    
    if (self.isInTheMiddleOfTyping == NO) {
        self.display.text = @"";
        self.isInTheMiddleOfTyping = YES;
    }
    
    
    
    
    if ([sender.currentTitle isEqualToString:@"e"] == YES) {
        // set current number string to constant value
        self.numberString = @"2.718281828";
        
        // append operator sign to display string
        self.display.text = [self.display.text stringByAppendingString:@"2.718281828"];
    }
    else if ([sender.currentTitle isEqualToString:@"pi"] == YES){
        // set current number string to constant value
        self.numberString = @"3.141592654";
        
        // append operator sign to display string
        self.display.text = [self.display.text stringByAppendingString:@"3.141592654"];
    }
}

- (IBAction)equalPressed:(UIButton *)sender {
    // push number(double value) to equation stack
    if ([self.numberString isEqualToString:@""] == NO) {
        [self.myCalculator pushToEquationStack:N([self.numberString doubleValue])];
    }
    
    // verify the equation validation, in case the crash
    if ([self.myCalculator equationIsValid] == YES) {
        // do calculation
        double result = [[self.myCalculator calculation] doubleValue];
        
        // display result
        self.resultDisplay.text = [NSString stringWithFormat:@"%0.8g", result];
    }
    else{
        NSLog(@"%@", [self.myCalculator returnEquation]);
        // display error
        self.resultDisplay.text = [self.myCalculator getError];
    }
    
    
    
    // clean equation
    [self.myCalculator cleanEquation];
    
    // set to default typing status
    self.isInTheMiddleOfTyping = NO;

}

- (IBAction)cleanPressed:(UIButton *)sender {
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
    
}

@end
