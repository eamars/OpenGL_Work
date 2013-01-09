//
//  ViewController.m
//  MyFirstApp
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

{
    char op;
    int currentNumber;
    BOOL firstOperand, isAfterDot;
    Calculator *myCalculator;
    NSMutableString *displayString;
    
}

@synthesize display;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    firstOperand = YES;
    isAfterDot = NO;
    displayString = [NSMutableString stringWithCapacity: 40];
    myCalculator = [[Calculator alloc] init];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)processDigit:(int)digit
{
    //
    currentNumber = currentNumber * 10 + digit;
    
    [displayString appendString:[NSString stringWithFormat:@"%d", digit]];
    display.text = displayString;
}

- (IBAction)clickDigit:(UIButton *)sender
{
    int digit = sender.tag;
    
    [self processDigit:digit];
}

- (void) processOp:(char)theOp
{
    NSString *opStr;
    
    op = theOp;
    
    switch (theOp) {
        case '+':
            opStr = @"+";
            break;
            
        case '-':
            opStr = @"-";
            break;
            
        case '*':
            opStr = @"×";
            break;
            
        case '/':
            opStr = @"÷";
            break;
            
        default:
            opStr = @"INVALID_OPERATOR";
            break;
    }
    
    [self storeValue];
    firstOperand = NO;
    [displayString appendString:opStr];
    display.text = displayString;
}

- (IBAction)clickPlus
{
    [self processDigit:'+'];
}
- (IBAction)clickMinus
{
    [self processDigit:'-'];
}
- (IBAction)clickMultiply
{
    [self processDigit:'*'];
}
- (IBAction)clickDivide
{
    [self processDigit:'/'];
}
- (IBAction)clickDot
{
    [self storeValue];
    [displayString appendString:@"."];
    display.text = displayString;
}

- (void)storeValue
{
    if (firstOperand) {
        myCalculator.operand1.number = currentNumber;
    }
    else{
        myCalculator.operand2.number = currentNumber;
        firstOperand = YES;
    }
        
    
    currentNumber = 0;
}

// Misc.
- (IBAction)clickEquals
{
    if (firstOperand == NO) {
        [self storeValue];
        [myCalculator performOperation:op];
        [displayString appendString:@" = "];
        [displayString appendString:[myCalculator.accumulator convertToString]];
        display.text = displayString;
        currentNumber = 0;
        firstOperand = YES;
        isAfterDot = NO;
        [displayString setString:@""];
        
    }
}

- (IBAction)clickClear
{
    currentNumber = 0;
    firstOperand = YES;
    isAfterDot = NO;
    [myCalculator clear];
    [displayString setString:@""];
    display.text = displayString;
}



@end
