//
//  Author.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Book;

@interface Author : NSManagedObject

@property (nonatomic, retain) NSString * firstName;
@property (nonatomic, retain) NSString * lastName;
@property (nonatomic, retain) NSSet *hasWritten;
@end

@interface Author (CoreDataGeneratedAccessors)

- (void)addHasWrittenObject:(Book *)value;
- (void)removeHasWrittenObject:(Book *)value;
- (void)addHasWritten:(NSSet *)values;
- (void)removeHasWritten:(NSSet *)values;

@end
