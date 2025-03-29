#import <UIKit/UIKit.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSSpecifier.h>

#import "../Views/LibellumStyleOptionView.h"

@interface LibellumStylePickerCell : PSTableCell <LibellumStyleOptionViewDelegate>
@end

@interface UIView (PrivateMethods)
    - (UIViewController *)_viewControllerForAncestor;
@end

@interface PSSpecifier (PrivateMethods)
    - (id)performGetter;
    - (void)performSetterWithValue:(id)value;
@end
