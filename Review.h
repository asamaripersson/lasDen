//
//  Review.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Book, Critic;

@interface Review : NSManagedObject

@property (nonatomic, retain) NSString * reviewText;
@property (nonatomic, retain) Critic *isWrittenBy;
@property (nonatomic, retain) Book *reviewsBook;

@end
