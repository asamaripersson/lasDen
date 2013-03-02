//
//  ANSBookStorage.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ANSBook, ANSAuthor;
@interface ANSBookStorage : NSObject

+(ANSBookStorage *)sharedStorage;

//add year???!!!
-(ANSBook*)addBookWithTitle:(NSString*)title Author:(ANSAuthor*)author;

-(NSArray *)allBooksWrittenBy:(ANSAuthor*)author;

-(NSArray*)allBooksBelongsToGengre:(NSString*)genre;

-(void)removeFriend:(ANSBook *)book;
@end
