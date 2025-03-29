#import <objc/runtime.h>
#import <Preferences/PSSpecifier.h>
#import <Preferences/PSSliderTableCell.h>

@interface PSSpecifier (PrivateMethods)
    - (id)performGetter;
    - (void)performSetterWithValue:(id)value;
@end

@interface UIView (PrivateMethods)
    - (UIViewController *)_viewControllerForAncestor;
@end

@interface LibellumLabeledSliderCell : PSSliderTableCell
@end
