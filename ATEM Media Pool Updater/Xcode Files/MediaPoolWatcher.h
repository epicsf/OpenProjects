//
//  MediaPoolWatcher.h
//  ATEM Media Pool Updater
//
//  Created by Filip Sandborg-Olsen on 31/01/14.
//  Copyright (c) 2014 Learninglab DTU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CallbackMonitors.h"
#import "BMDSwitcherAPI.h"


@class SwitcherMediaPoolAppDelegate;

@interface MediaPoolWatcher : NSObject {
    NSString* mIP;
    NSString* mPath;
    
    IBMDSwitcherDiscovery* switcherDiscovery;
    IBMDSwitcher* switcher;
    IBMDSwitcherMediaPool* mediaPool;
    IBMDSwitcherStills* stills;
    IBMDSwitcherClip* clip; // TODO: array of clips
    SwitcherMonitor* switcherMonitor;
    StillsMonitor* stillsMonitor;
    ClipMonitor* clipMonitor; // TODO: array of clip monitors
    SwitcherMonitor* monitor;
    LockCallback* lockCallbackStills;
    LockCallback* lockCallbackClips;

    NSString* downloadPath;
    
    uint32_t currentIndex;
    uint32_t stillsCount;
    uint32_t clipsCount;
    
    NSString* JSONFile;
    
    NSMutableDictionary* JSONData;
    
    NSMutableArray* updateList;
    NSOperationQueue* updateQueue;

    SwitcherMediaPoolAppDelegate* mUIDelegate;
    
    NSString* statusString;
    
    bool terminating;
    bool connected;
}

-(MediaPoolWatcher*) initWithIP:(NSString*) ip andBaseDir: (NSString*) path withDelegate:(SwitcherMediaPoolAppDelegate*) uiDelegate;

-(void) onStillsLockObtained;
-(void) onStillsTransferEnded: (NSDictionary*) data;
-(void) switcherDisconnected;
-(void) pullStills;
-(void) pushStills;
-(void) connectToSwitcher;
-(void) isTerminating;
-(bool) isBusy;
-(void) autoUpdateStills;
-(bool) stillsAreValid;
-(bool) isConnected;
-(void) cleanupConnection;
-(bool) localStillsExist;

@property (retain) NSString* mIP;
@property (retain) NSString* mPath;
@property bool terminating;

@end
