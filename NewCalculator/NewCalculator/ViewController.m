//
//  ViewController.m
//  NewCalculator
//
//  Created by eamars on 18/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
{
    char op;
    int decimalPlace;
    float currentNumber;
    BOOL firstOperand, isDecimal;
    Calculator *myCalculator;
    NSMutableString *displayString;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
