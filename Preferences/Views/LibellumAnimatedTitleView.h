#import <UIKit/UIKit.h>

#import "../Definitions/PreferencesColorDefinitions.h"

@interface LibellumAnimatedTitleView : UIView
    - (void)adjustLabelPositionToScrollOffset:(CGFloat)offset;
    - (instancetype)initWithTitle:(NSString *)title minimumScrollOffsetRequired:(CGFloat)minimumOffset;
@end
