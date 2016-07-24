//
//  SUUpdateAlert.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/12/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUUPDATEALERT_H
#define SUUPDATEALERT_H

#import <Cocoa/Cocoa.h>
#import "SUVersionDisplayProtocol.h"
#import "SUStatusCompletionResults.h"

@protocol SUUpdateAlertDelegate;

@class SUAppcastItem, SUHost;
@interface SUUpdateAlert : NSWindowController

@property (nonatomic, weak, readonly) id <SUVersionDisplay> versionDisplayer;

- (instancetype)initWithAppcastItem:(SUAppcastItem *)item alreadyDownloaded:(BOOL)alreadyDownloaded host:(SUHost *)aHost versionDisplayer:(id <SUVersionDisplay>)aVersionDisplayer completionBlock:(void (^)(SUUpdateAlertChoice))block;

- (instancetype)initWithAppcastItem:(SUAppcastItem *)item host:(SUHost *)aHost versionDisplayer:(id <SUVersionDisplay>)aVersionDisplayer resumableCompletionBlock:(void (^)(SUInstallUpdateStatus))block;

- (void)showReleaseNotes:(NSData *)releaseNotes;
- (void)showReleaseNotesFailedToDownload;

- (IBAction)installUpdate:sender;
- (IBAction)skipThisVersion:sender;
- (IBAction)remindMeLater:sender;

@end

#endif
