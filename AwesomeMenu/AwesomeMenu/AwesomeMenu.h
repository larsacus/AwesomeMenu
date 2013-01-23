//
//  AwesomeMenu.h
//  AwesomeMenu
//
//  Created by Levey on 11/30/11.
//  Copyright (c) 2011 Levey & Other Contributors. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AwesomeMenuItem.h"

@protocol AwesomeMenuDelegate;


@interface AwesomeMenu : UIView <AwesomeMenuItemDelegate>
{
    int _flag;
}
@property (nonatomic, copy) NSArray *menusArray;
@property (nonatomic, getter = isExpanding) BOOL expanding;
@property (nonatomic, weak) id<AwesomeMenuDelegate> delegate;

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *highlightedImage;
@property (nonatomic, strong) UIImage *contentImage;
@property (nonatomic, strong) UIImage *highlightedContentImage;

@property (nonatomic) CGFloat nearRadius;
@property (nonatomic) CGFloat endRadius;
@property (nonatomic) CGFloat farRadius;
@property (nonatomic) CGPoint startPoint;
@property (nonatomic) CGFloat timeOffset;
@property (nonatomic) CGFloat rotateAngle;
@property (nonatomic) CGFloat menuWholeAngle;
@property (nonatomic) CGFloat expandRotation;
@property (nonatomic) CGFloat closeRotation;

@property (nonatomic, strong) NSTimer *timer;

@property (nonatomic, strong) AwesomeMenuItem *addButton;
@property (nonatomic, getter = isAnimating) BOOL animating;

- (id)initWithFrame:(CGRect)frame menus:(NSArray *)aMenusArray;
@end

@protocol AwesomeMenuDelegate <NSObject>
- (void)AwesomeMenu:(AwesomeMenu *)menu didSelectIndex:(NSInteger)idx;
@optional
- (void)AwesomeMenuDidFinishAnimationClose:(AwesomeMenu *)menu;
- (void)AwesomeMenuDidFinishAnimationOpen:(AwesomeMenu *)menu;
@end