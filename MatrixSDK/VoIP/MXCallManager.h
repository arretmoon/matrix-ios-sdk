/*
 Copyright 2015 OpenMarket Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "MXCall.h"

@class MXSession;

/**
 Posted when the user is receiving an incoming call.
 The notification object is the `MXKCall` object representing the call.
 */
extern NSString *const kMXCallManagerDidReceiveCallInvite;

/**
 The `MXCallManager` object manages calls for a given Matrix session.
 It manages call signaling over Matrix (@see http://matrix.org/docs/spec/#id9) and then opens
 a stream between peers devices using a third party VoIP library.
 */
@interface MXCallManager : NSObject

/**
 Create the `MXCallManager` instance.

 @param mxSession the mxSession to the home server.
 @return the newly created MXCallManager instance.
 */
- (instancetype)initWithMatrixSession:(MXSession*)mxSession;

/**
 Stop the call manager.
 Call in progress will be interupted.
 */
- (void)close;

/**
 The related matrix session.
 */
@property (nonatomic, readonly) MXSession *mxSession;

@end
