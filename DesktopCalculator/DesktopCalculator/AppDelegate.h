//
//  AppDelegate.h
//  DesktopCalculator
//
//  Created by Ran Bao on 3/02/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet NSTextField *configurationDisplay;
@property (weak) IBOutlet NSTextField *display;
@property (weak) IBOutlet NSTextField *resultDisplay;



@end
