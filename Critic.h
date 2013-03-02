//
//  Critic.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Critic : NSManagedObject

@property (nonatomic, retain) NSString * email;
@property (nonatomic, retain) NSString * firstName;
@property (nonatomic, retain) NSString * lastName;
@property (nonatomic, retain) NSString * password;
@property (nonatomic, retain) NSString * criticID;
@property (nonatomic, retain) NSSet *hasWrittenReview;
@end

@interface Critic (CoreDataGeneratedAccessors)

- (void)addHasWrittenReviewObject:(NSManagedObject *)value;
- (void)removeHasWrittenReviewObject:(NSManagedObject *)value;
- (void)addHasWrittenReview:(NSSet *)values;
- (void)removeHasWrittenReview:(NSSet *)values;

@end
