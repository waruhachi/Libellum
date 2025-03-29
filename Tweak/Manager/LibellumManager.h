#import <roothide.h>
#import <UIKit/UIKit.h>
#import <Cephei/HBPreferences.h>
#import <AudioToolbox/AudioToolbox.h>

#import "../Controller/LibellumViewController.h"

@interface UIApplication (Private)
    - (UIInterfaceOrientation)activeInterfaceOrientation;
@end

@interface CSCoverSheetViewController : UIViewController
    - (BOOL)_isMainPageShowing;
@end

@interface SBLockScreenViewControllerBase : UIViewController
    - (BOOL)isMainPageVisible;
@end

@interface SBLockScreenManager : NSObject
    @property (nonatomic, readonly) CSCoverSheetViewController *coverSheetViewController;       // iOS 13
    @property (nonatomic, readonly) SBLockScreenViewControllerBase *lockScreenViewController;   // iOS 12
@end

@protocol SBSystemGestureRecognizerDelegate <UIGestureRecognizerDelegate>
@required
    - (UIView *)viewForSystemGestureRecognizer:(UIGestureRecognizer *)gesture;
@end

@interface SBMainDisplaySystemGestureManager : NSObject
    + (instancetype)sharedInstance;

    - (void)addGestureRecognizer:(id)arg1 withType:(NSUInteger)arg2;
@end

@interface SBSystemGestureManager : NSObject
    + (instancetype)mainDisplayManager;
@end

@interface FBSystemGestureManager : NSObject
    + (instancetype)sharedInstance;

    - (void)addGestureRecognizer:(id)arg1 toDisplayWithIdentity:(id)arg2;
@end

@interface SBScreenEdgePanGestureRecognizer : UIPanGestureRecognizer
    @property (nonatomic, assign) NSInteger edges;

    - (instancetype)initWithTarget:(id)arg1 action:(SEL)arg2;
@end

@interface SBLockStateAggregator : NSObject
    - (NSUInteger)lockState;

    + (instancetype)sharedInstance;
@end

@interface SBIdleTimerGlobalCoordinator : NSObject
    - (void)resetIdleTimer;

    + (instancetype)sharedInstance;
@end

@interface KalmAPI : NSObject
    + (UIColor *)getColor;
@end

@interface LibellumManager : NSObject <UIPageViewControllerDataSource, UITextViewDelegate, SBSystemGestureRecognizerDelegate>
    @property (nonatomic, assign) BOOL isDarkMode;

    @property (nonatomic, retain) UIToolbar *toolBar;
    @property (nonatomic, retain) UITextView *activeTextView;
    @property (nonatomic, retain) HBPreferences *preferences;
    @property (nonatomic, retain) UITapGestureRecognizer *tapGesture;
    @property (nonatomic, retain) UIPageViewController *pageController;
    @property (nonatomic, retain) NSLayoutConstraint *heightConstraint;

    @property (nonatomic, readonly) UISwipeGestureRecognizer *swipeGesture;
    @property (nonatomic, readonly) SBScreenEdgePanGestureRecognizer *edgeGesture;

    @property (nonatomic, retain, readonly) NSMutableArray *pages;
    @property (nonatomic, retain, readonly) NSMutableDictionary *notesByIndex;

    + (instancetype)sharedManager;

    - (instancetype)init;
    - (void)addPage;
    - (void)saveNotes;
    - (void)removePage;
    - (void)createPages;
    - (void)backupNotes;
    - (void)preferencesChanged;
    - (void)forceLockScreenStackViewLayout;
    - (void)disablePageScroll:(BOOL)pageScroll;
    - (void)setToolBarButtons:(BOOL)showPageManagement;
    - (void)toggleLibellum:(UIGestureRecognizer *)gesture;
    - (void)authenticationStatusFromAggregator:(id)aggregator;
    - (void)notifyViewControllersOfInterfaceChange:(NSInteger)style;

    - (BOOL)isDarkMode;
    - (UIColor *)getTintColor;
@end
