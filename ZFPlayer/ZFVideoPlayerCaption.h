//
//  Created by Viki.
//  Copyright (c) 2014 Viki Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
  // There was an error fetching the caption from the server.
  kCaptionErrorFetchError = 1000,
  
  // There was an error parsing the caption.
  kCaptionErrorParseError,
  
  // There were invalid segments in the caption.
  kCaptionErrorInvalidSegmentsError,
  
  // There was an unknown error.
  kCaptionErrorUnknown,
  
} VKCaptionErrorCode;

@protocol ZFVideoPlayerCaptionProtocol <NSObject>

@property (nonatomic, readonly) NSArray* segments;

- (NSArray*)boundryTimes;
- (NSString*)contentAtTime:(NSInteger)time;
+ (NSString*)captionType;

@end

@interface ZFVideoPlayerCaption : NSObject<ZFVideoPlayerCaptionProtocol>

@property (nonatomic, strong) NSString* languageCode;
@property (nonatomic, strong) NSArray* segments;
@property (nonatomic, strong) NSArray* boundryTimes;
@property (nonatomic, strong) NSArray* preferredAdSlotTimes;
@property (nonatomic, strong) NSArray* invalidSegments;

- (id)initWithRawString:(NSString *)subtitleRawData;
- (void)parseSubtitleRaw:(NSString *)string completion:(void (^)(NSMutableArray *segments, NSMutableArray *invalidSegments))completion;

@end
