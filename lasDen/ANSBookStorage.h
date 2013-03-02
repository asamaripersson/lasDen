//
//  ANSBookStorage.h
//  lasDen
//
//  Created by Åsa Persson on 2013-03-02.
//  Copyright (c) 2013 asaNsara. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Book, Author;
@interface ANSBookStorage : NSObject

+(ANSBookStorage *)sharedStorage;

//add year???!!!
-(Book*)addBookWithTitle:(NSString*)title Author:(Author*)author;

-(NSArray *)allBooksWrittenBy:(Author*)author;

-(NSArray*)allBooksBelongsToGengre:(NSString*)genre;

-(void)removeBook:(Book *)book;
@end
