// Copyright (c) 2017-2020 Lars Fröder

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef SIMJECT
#import <rocketbootstrap/rocketbootstrap.h>
#endif
#import <AppSupport/CPDistributedMessagingCenter.h>

@interface CPNotification : NSObject
+ (void)showAlertWithTitle:(NSString*)title message:(NSString*)message userInfo:(NSDictionary*)userInfo badgeCount:(int)badgeCount soundName:(NSString*)soundName delay:(double)delay repeats:(BOOL)repeats bundleId:(NSString*)bundleId;
@end

@interface SBApplicationInfo : NSObject
@property (nonatomic,retain,readonly) NSURL* executableURL;
@property (nonatomic,retain,readonly) NSURL* bundleContainerURL;
@property (nonatomic,retain,readonly) NSURL* dataContainerURL;
@property (nonatomic,retain,readonly) NSURL* sandboxURL;
@property (nonatomic,copy,readonly) NSString* displayName;
@end

@interface SBApplication : NSObject
@property (nonatomic, readonly) SBApplicationInfo* info;//iOS 11 and above
- (SBApplicationInfo*)_appInfo;	//iOS 10 and below
@end

@interface SBApplicationController : NSObject
+ (instancetype)sharedInstance;
- (NSArray<SBApplication*>*)allApplications;
@end
