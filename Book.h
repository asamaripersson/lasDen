//
//  Book.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Book : NSManagedObject

@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSNumber * score;
@property (nonatomic, retain) NSString * isbn;
@property (nonatomic, retain) NSString * genre;
@property (nonatomic, retain) NSManagedObject *isWrittenBy;
@property (nonatomic, retain) NSSet *hasReviews;
@end

@interface Book (CoreDataGeneratedAccessors)

- (void)addHasReviewsObject:(NSManagedObject *)value;
- (void)removeHasReviewsObject:(NSManagedObject *)value;
- (void)addHasReviews:(NSSet *)values;
- (void)removeHasReviews:(NSSet *)values;

@end
