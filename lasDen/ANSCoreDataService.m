//
//  APCoreDataService.m
//  MyFriends
//
//  Created by Åsa Persson on 2013-01-01.
//
//

#import "ANSCoreDataService.h"
#import "Book.h"

@implementation ANSCoreDataService
{
    NSManagedObjectContext *context;
    NSManagedObjectModel *model;
}
+(void)addObject:(NSManagedObjectModel *)object dictionary:(NSMutableDictionary *)dictionary objectID:(NSString *)objectID
{
    [dictionary setObject:object forKey:objectID];
}

+(ANSCoreDataService*) sharedService
{
    static ANSCoreDataService *sharedService = nil;
    static dispatch_once_t once;
    
    dispatch_once(&once, ^{
        sharedService = [[self alloc]init];
    });
    return sharedService;
}

- (id)init
{
    if (self = [super init])
    {
        model = [NSManagedObjectModel mergedModelFromBundles:nil];
        
        NSPersistentStoreCoordinator *psc =
        [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel:model];
        
        NSString *path = [self path];
        NSURL *storageURL = [NSURL fileURLWithPath:path];
        
        NSError *error = nil;
        
        if (![psc addPersistentStoreWithType:NSSQLiteStoreType
                               configuration:nil
                                         URL:storageURL
                                     options:nil
                                       error:&error])
        {
            [NSException raise:@"Open failed"
                        format:@"Reason: %@", [error localizedDescription]];
        }
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(contextChanged:)
                                                     name:NSManagedObjectContextObjectsDidChangeNotification
                                                   object:nil];
        
        context = [[NSManagedObjectContext alloc] init];
        [context setPersistentStoreCoordinator:psc];
    }
    return self;
}

-(void) contextChanged:(NSNotification*) notification
{
    BOOL success = [self saveChanges];
    
    if(success)
    {
        NSLog(@"Saved all objects");
        
        NSNotification *not = [NSNotification notificationWithName:@"loadTable" object:nil];
        
        [[NSNotificationCenter defaultCenter] postNotification:not];
        
    } else {
        NSLog(@"Could not save objects");
    }
    
    
}

-(NSManagedObjectContext *)getContext
{
    return context;
}

-(NSManagedObjectModel *)getModel
{
    return model;
}

-(NSArray *)fetchDataWithEntity:(NSString *)entity
{
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    
    NSEntityDescription *e = [[[self getModel] entitiesByName] objectForKey:entity];
    [request setEntity:e];
    
    NSError *error;
    NSArray *result = [[self getContext] executeFetchRequest:request error:&error];
    if (!result)
    {
        [NSException raise:@"Fetch failed"
                    format:@"Reason: %@", [error localizedDescription]];
    }
    return result;
}

- (NSString *)path
{
    NSArray *documentDirectories =
    NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                        NSUserDomainMask, YES);
    NSString *documentDirectory = [documentDirectories objectAtIndex:0];
    
    return [documentDirectory stringByAppendingPathComponent:@"store.data"];
}

- (BOOL)saveChanges
{
    NSError *err = nil;
    BOOL successful = [context save:&err];
    if (!successful)
    {
        NSLog(@"Error saving: %@", [err localizedDescription]);
    }
    return successful;
}

@end

