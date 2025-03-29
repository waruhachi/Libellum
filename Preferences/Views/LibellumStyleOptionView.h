#import <UIKit/UIKit.h>

#import "LibellumStyleCheckView.h"

@class LibellumStyleOptionView;
    @protocol LibellumStyleOptionViewDelegate <NSObject>

    - (void)selectedOption:(LibellumStyleOptionView *)option;
@end

@interface LibellumStyleOptionView : UIView
    @property (nonatomic, assign) BOOL enabled;
    @property (nonatomic, assign) BOOL highlighted;
    @property (nonatomic, retain) UIImage *previewImage;
    @property (nonatomic, retain) UIImageView *previewImageView;
    @property (nonatomic, retain) UILabel *label;
    @property (nonatomic, retain) id appearanceOption;
    @property (nonatomic, weak) id<LibellumStyleOptionViewDelegate> delegate;

    - (void)updateViewForStyle:(NSString *)style;
    - (instancetype)initWithFrame:(CGRect)frame appearanceOption:(id)option;
@end
