@import Cephei;

#import <spawn.h>
#import <roothide.h>
#import <UIKit/UIKit.h>

#import "../Definitions/PreferencesColorDefinitions.h"

@interface UIColor (iOS13)
    + (UIColor *)labelColor;
    + (UIColor *)secondaryLabelColor;
@end

@interface UIViewController (iOS13)
    - (void)setModalInPresentation:(BOOL)arg1;
@end

@interface LibellumNoteBackupViewController : UIViewController
@end
