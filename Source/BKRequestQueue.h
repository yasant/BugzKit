//
// BKRequestQueue.h
//
// Copyright (c) 2009 Lukhnos D. Liu (http://lukhnos.org)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//

#import "BKAPIContext.h"
#import "BKRequest.h"
#import "LFWebAPIKit.h"

@class BKRequestQueue;

@protocol BKRequestQueueCachePolicy <NSObject>
- (void)requestQueue:(BKRequestQueue *)inRequestQueue storeData:(NSData *)inData ofRequest:(BKRequest *)inRequest;
- (NSData *)requestQueue:(BKRequestQueue *)inRequestQueue cachedDataOfRequest:(BKRequest *)inRequest;
@end


@interface BKRequestQueue : NSObject
{
    NSMutableArray *queue;
    LFHTTPRequest *HTTPRequest;
    BOOL paused;
		
	NSOperationQueue *dispatchQueue;
	id<BKRequestQueueCachePolicy> cachePolicy;
}

- (void)addRequest:(BKRequest *)inRequest;
- (void)addRequest:(BKRequest *)inRequest deferred:(BOOL)inDeferred;

- (NSArray *)queuedRequestsWithPredicate:(NSPredicate *)inPredicate;

- (void)cancelAllRequests;
- (void)cancelRequest:(BKRequest *)inRequest;
- (void)cancelRequestsOfTarget:(id)inTarget;
- (void)cancelRequestsWithPredicate:(NSPredicate *)inPredicate;
- (void)cancelRequestsWithBlock:(BOOL (^)(BKRequest *))inFilter;

@property (assign) BOOL paused;
@property (assign) BOOL shouldWaitUntilDone;
@property (readonly) BOOL isRunning;
@property (retain) id<BKRequestQueueCachePolicy> cachePolicy;
@end
