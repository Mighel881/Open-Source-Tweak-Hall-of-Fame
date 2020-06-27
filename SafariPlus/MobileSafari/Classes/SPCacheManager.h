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

@interface SPCacheManager : NSObject
{
	NSURL* _cacheURL;
	NSMutableDictionary* _miscPlist;
	NSMutableDictionary* _desktopButtonStates;
	NSMutableDictionary* _tabStateAdditions;
}

+ (instancetype)sharedInstance;

- (void)updateExcludedFromBackup;

- (void)loadMiscPlist;
- (void)saveMiscPlist;
- (BOOL)firstStart;
- (void)firstStartDidSucceed;

- (NSInteger)downloadStorageRevision;
- (void)setDownloadStorageRevision:(NSInteger)revision;
- (NSDictionary*)loadDownloadCache;
- (void)saveDownloadCache:(NSDictionary*)downloadCache;
- (void)clearDownloadCache;

- (void)loadDesktopButtonStates;
- (void)saveDesktopButtonStates;
- (void)setDesktopButtonState:(BOOL)state forUUID:(NSUUID*)UUID;
- (BOOL)desktopButtonStateForUUID:(NSUUID*)UUID;

- (void)loadTabStateAdditions;
- (void)saveTabStateAdditions;
- (BOOL)isTabWithUUIDLocked:(NSUUID*)UUID;
- (void)setLocked:(BOOL)locked forTabWithUUID:(NSUUID*)UUID;
- (void)cleanUpTabStateAdditions;
- (BOOL)tabExistsWithUUID:(NSUUID*)UUID;

@end
