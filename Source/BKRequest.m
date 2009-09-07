//
// BKRequest.m
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

#import "BKRequest.h"
#import "BKRequest+ProtectedMethods.h"
#import "BKPrivateUtilities.h"


@implementation BKRequest
- (void)dealloc
{
    target = nil;
    actionOnSuccess = NULL;
    actionOnFailure = NULL;
    [userInfo release];
    [HTTPRequestMethod release];
    [APIContext release];
    [requestParameterDict release];
    [response release];
    [error release];
    [creationDate release];
    [super dealloc];
}

- (NSURL *)requestURL
{
    
}

- (NSData *)requestData
{
    
}

@synthesize target;
@synthesize actionOnSuccess;
@synthesize actionOnFailure;
@synthesize userInfo;
@synthesize HTTPRequestMethod;
@synthesize APIContext;
@synthesize requestParameterDict;
@synthesize response;
@synthesize error;
@synthesize creationDate;
@end

@implementation BKRequest (ProtectedMethods)
- (void)requestQueue:(BKRequestQueue *)inQueue didCompleteWithData:(NSData *)inData
{
    
}

- (void)requestQueue:(BKRequestQueue *)inQueue didFailWithError:(NSString *)inHTTPRequestError
{
    
}
@end
