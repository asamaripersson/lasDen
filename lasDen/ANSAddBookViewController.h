//
//  ANSAddBookViewController.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ANSAddBookViewController : UITableViewController
@property (weak, nonatomic) IBOutlet UITextField *title;
@property (weak, nonatomic) IBOutlet UITextField *author;
@property (weak, nonatomic) IBOutlet UITextField *isbn;
- (IBAction)addBook:(id)sender;

@end
