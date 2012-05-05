//
//  MPTypes.h
//  MasterPassword
//
//  Created by Maarten Billemont on 02/01/12.
//  Copyright (c) 2012 Lyndir. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MPPersistentStoreDidChangeNotification @"MPPersistentStoreDidChange"

typedef enum {
    MPElementContentTypePassword,
    MPElementContentTypeNote,
    MPElementContentTypePicture,
} MPElementContentType;

typedef enum {
    MPElementTypeClassCalculated = 2 << 7,
    MPElementTypeClassStored     = 2 << 8,
} MPElementTypeClass;

typedef enum {
    MPElementTypeCalculatedLong         = MPElementTypeClassCalculated  | 0x01,
    MPElementTypeCalculatedMedium       = MPElementTypeClassCalculated  | 0x02,
    MPElementTypeCalculatedShort        = MPElementTypeClassCalculated  | 0x03,
    MPElementTypeCalculatedBasic        = MPElementTypeClassCalculated  | 0x04,
    MPElementTypeCalculatedPIN          = MPElementTypeClassCalculated  | 0x05,
    
    MPElementTypeStoredPersonal         = MPElementTypeClassStored      | 0x01,
    MPElementTypeStoredDevicePrivate    = MPElementTypeClassStored      | 0x02,
} MPElementType;

#define MPTestFlightCheckpointAction                    @"MPTestFlightCheckpointAction"
#define MPTestFlightCheckpointHelpChapter               @"MPTestFlightCheckpointHelpChapter_%@"
#define MPTestFlightCheckpointCopyToPasteboard          @"MPTestFlightCheckpointCopyToPasteboard"
#define MPTestFlightCheckpointResetPasswordCounter      @"MPTestFlightCheckpointResetPasswordCounter"
#define MPTestFlightCheckpointIncrementPasswordCounter  @"MPTestFlightCheckpointIncrementPasswordCounter"
#define MPTestFlightCheckpointEditPassword              @"MPTestFlightCheckpointEditPassword"
#define MPTestFlightCheckpointCloseAlert                @"MPTestFlightCheckpointCloseAlert"
#define MPTestFlightCheckpointSelectType                @"MPTestFlightCheckpointSelectType_%@"
#define MPTestFlightCheckpointSelectElement             @"MPTestFlightCheckpointSelectElement"
#define MPTestFlightCheckpointDeleteElement             @"MPTestFlightCheckpointDeleteElement"
#define MPTestFlightCheckpointCancelSearch              @"MPTestFlightCheckpointCancelSearch"
#define MPTestFlightCheckpointExternalLink              @"MPTestFlightCheckpointExternalLink"
#define MPTestFlightCheckpointLaunched                  @"MPTestFlightCheckpointLaunched"
#define MPTestFlightCheckpointActivated                 @"MPTestFlightCheckpointActivated"
#define MPTestFlightCheckpointDeactivated               @"MPTestFlightCheckpointDeactivated"
#define MPTestFlightCheckpointTerminated                @"MPTestFlightCheckpointTerminated"
#define MPTestFlightCheckpointShowGuide                 @"MPTestFlightCheckpointShowGuide"
#define MPTestFlightCheckpointMPForgotten               @"MPTestFlightCheckpointMPForgotten"
#define MPTestFlightCheckpointMPChanged                 @"MPTestFlightCheckpointMPChanged"
#define MPTestFlightCheckpointMPUnstored                @"MPTestFlightCheckpointMPUnstored"
#define MPTestFlightCheckpointMPMismatch                @"MPTestFlightCheckpointMPMismatch"
#define MPTestFlightCheckpointMPAsked                   @"MPTestFlightCheckpointMPAsked"
#define MPTestFlightCheckpointStoreIncompatible         @"MPTestFlightCheckpointStoreIncompatible"
#define MPTestFlightCheckpointSetKeyphraseLength        @"MPTestFlightCheckpointSetKeyphraseLength_%d"

#define MPNotificationStoreUpdated                      @"MPNotificationStoreUpdated"
#define MPNotificationKeySet                            @"MPNotificationKeySet"
#define MPNotificationKeyUnset                          @"MPNotificationKeyUnset"
#define MPNotificationKeyForgotten                      @"MPNotificationKeyForgotten"

NSData *keyForPassword(NSString *password);
NSData *keyHashForPassword(NSString *password);
NSData *keyHashForKey(NSData *key);
NSString *NSStringFromMPElementType(MPElementType type);
NSString *ClassNameFromMPElementType(MPElementType type);
Class ClassFromMPElementType(MPElementType type);
NSString *MPCalculateContent(MPElementType type, NSString *name, NSData *key, int16_t counter);