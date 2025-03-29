#import <UIKit/UIKit.h>

@interface LibellumStyleCheckView : UIView
    @property (nonatomic, assign) BOOL selected;

    - (void)updateSelectedState;
@end

@interface UIImage (PrivateMethod)
    + (instancetype)kitImageNamed:(id)arg1;
@end
