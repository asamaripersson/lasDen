//
//  ANSBookStorage.m
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import "ANSBookStorage.h"
#import "ANSCoreDataService.h"

@implementation ANSBookStorage

{
    NSManagedObjectContext *context;
    NSManagedObjectModel *model;
}
+(ANSBookStorage *)sharedStorage
{
    static ANSBookStorage *sharedStorage;
    static dispatch_once_t once;
    
    dispatch_once(&once, ^{
    });
    return sharedStorage;
}
- (id)init
{
    self = [super init];
    if(self)
    {
        model = [[ANSCoreDataService  sharedService] getModel];
        context = [[ANSCoreDataService sharedService] getContext];
        
    }
    return self;
}
-(ANSBook *)addBookWithTitle:(NSString *)title Author:(ANSAuthor *)author
{
//    ANSBook *book = [NSEntityDescription insertNewObjectForEntityForName:@"ANSBook"
//                                              inManagedObjectContext:context];
//    book.title = title;
//    book.author = author;
    return nil;
}
@end
