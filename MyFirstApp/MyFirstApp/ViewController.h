//
//  ViewController.h
//  MyFirstApp
//
//  Created by eamars on 8/12/12.
//  Copyright (c) 2012 eamars. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Calculator.h"

@interface ViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *display;

- (void)processDigit: (int)digit;
- (void)processOp: (char)theOp;
- (void)storeValue;

// Numeric keys
- (IBAction)clickDigit: (UIButton *)sender;

// Arithmetic keys
- (IBAction)clickPlus;
- (IBAction)clickMinus;
- (IBAction)clickMultiply;
- (IBAction)clickDivide;

// Misc keys
- (IBAction)clickEquals;
- (IBAction)clickClear;
- (IBAction)clickDot;

@end
