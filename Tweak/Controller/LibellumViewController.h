#import <UIKit/UIKit.h>
#import <GcUniversal/GcColorPickerUtils.h>

#import "../Vendor/MTMaterialView.h"
#import "../Manager/LibellumManager.h"

@interface UIImage (Private)
    + (instancetype)kitImageNamed:(NSString *)arg1;
@end

@interface UIUserInterfaceStyleArbiter : NSObject
    - (long long)currentStyle;

    + (instancetype)sharedInstance;
@end

@interface CSCoverSheetViewControllerBase : UIViewController
@end

@interface LibellumViewController : CSCoverSheetViewControllerBase <UITextViewDelegate>
    @property (nonatomic, retain) NSAttributedString *text;
    @property (nonatomic, retain) MTMaterialView *blurView;
    @property (nonatomic, retain) UITextView *noteTextView;
    @property (nonatomic, retain) UIImageView *lockImageView;
    @property (nonatomic, retain) HBPreferences *preferences;

    @property (nonatomic, assign) BOOL isDarkMode;
    @property (nonatomic, assign) NSInteger index;

    // Preferences
    @property (nonatomic, copy) NSString *blurStyle;
    @property (nonatomic, copy) UIColor *lockColor;
    @property (nonatomic, copy) UIColor *borderColor;
    @property (nonatomic, copy) UIColor *customTintColor;
    @property (nonatomic, copy) UIColor *customTextColor;
    @property (nonatomic, copy) UIColor *customBackgroundColor;

    @property (nonatomic, assign) CGFloat borderWidth;
    @property (nonatomic, assign) CGFloat cornerRadius;
    @property (nonatomic, assign) NSInteger noteSize;
    @property (nonatomic, assign) NSInteger textAlignment;
    @property (nonatomic, assign) BOOL useKalmTintColor;
    @property (nonatomic, assign) BOOL enableEndlessLines;
    @property (nonatomic, assign) BOOL ignoreAdaptiveColors;
    @property (nonatomic, assign) BOOL requireAuthentication;

    - (void)updateViews;
    - (void)setNumberOfLines;
    - (void)updatePreferences;
    - (void)authenticationStatus:(BOOL)unlocked;
    - (void)interfaceStyleDidChange:(BOOL)darkMode;

    - (BOOL)isDarkMode;
    - (UIColor *)getTintColor;
@end
