//
//  Jason.h
//  Jasonette
//
//  Copyright © 2016 gliechtenstein. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RussianDollView.h"
#import "REMenu.h"
#import <SDWebImage/UIImageView+WebCache.h>
#import "JasonHelper.h"
#import "JasonMemory.h"
#import "JasonParser.h"
#import "JasonViewController.h"
#import "BBBadgeBarButtonItem.h"
#import "AFNetworking.h"
#import <SafariServices/SafariServices.h>
#import <NSHash/NSString+NSHash.h>
#import <FreeStreamer/FSAudioStream.h>
#import <PBJVision/PBJVision.h>
#import "MBProgressHud.h"
#if DEBUG
#include <FLEX/FLEX.h>
#endif

@import MediaPlayer;

@interface Jason : NSObject <UINavigationControllerDelegate, UIImagePickerControllerDelegate, UITabBarControllerDelegate, PBJVisionDelegate, UIWebViewDelegate>

@property (strong, nonatomic) NSDictionary *parser;
@property (strong, nonatomic) NSDictionary *data;
@property (strong, nonatomic) NSDictionary *options;
@property (strong, nonatomic) NSDictionary *rendered;
@property (strong, nonatomic) NSDictionary *global;
@property (strong, nonatomic) NSMutableArray *playing;
@property (nonatomic, assign) BOOL touching;
@property (nonatomic, assign) BOOL searchMode;
@property (nonatomic, assign) BOOL oauth_in_process;
@property (strong, nonatomic) NSMutableDictionary *services;

- (UIViewController *)getVC;


+ (Jason*)client;
- (Jason*)attach:(UIViewController<RussianDollView>*)viewController;
- (Jason*)detach:(UIViewController<RussianDollView>*)viewController;

- (void)cancel;
- (void)ok;
- (void)ok:(NSDictionary *)result;
- (void)finish;

- (void)error:(id)result withOriginalUrl:(NSString*)url;
- (void)error:(id)result;
- (void)error;

- (void)success:(id)result withOriginalUrl:(NSString*)url;
- (void)success:(id)result;
- (void)success;

- (void)go:(NSDictionary *)href;
- (void)call: (NSDictionary*)action;
- (void)call: (id)action with: (NSDictionary *)data;

- (void)loading:(BOOL)turnon;
- (void)networkLoading:(BOOL)turnon with: (NSDictionary *)options;
- (void)search;
- (void)snapshot;

- (void)reload;

- (void)start:(NSDictionary *)href;

- (void)loadViewByFile: (NSString *)url asFinal: (BOOL)final;
- (NSDictionary *)variables;
@end

