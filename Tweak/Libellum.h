#import <UIKit/UIKit.h>

@interface CSScrollView : UIScrollView
@end

@interface CSQuickActionsViewController : UIViewController
@end

@interface CSNotificationAdjunctListViewController : UIViewController
    @property (nonatomic, assign) CGSize sizeToMimic;
    @property (nonatomic, retain) UIStackView *stackView;

    - (id)_stackView;
    - (void)_updateItemsSizeToMimic;
@end

@interface SBPagedScrollView : UIScrollView
@end

@interface SBDashBoardQuickActionsViewController : UIViewController
@end

@interface SBDashBoardNotificationAdjunctListViewController : UIViewController
    @property (nonatomic, assign) CGSize sizeToMimic;
    @property (nonatomic, retain) UIStackView *stackView;
@end

@interface NCNotificationListSectionRevealHintView : UIView
@end

@interface UISUserInterfaceStyleMode : NSObject
    @property (nonatomic, assign) long long modeValue;
@end
