/*
 * Based off of Boo-dev's libstylepicker
 * https://github.com/boo-dev/libstylepicker
 */
#import "LibellumStylePickerCell.h"

@implementation LibellumStylePickerCell {
    UIStackView *_stackView;
}
    - (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier specifier:(PSSpecifier *)specifier {
        self = [super initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier specifier:specifier];

        if(self) {
            [specifier setProperty:@210 forKey:@"height"];

            NSMutableArray *optionViewArray = [[NSMutableArray alloc] init];
            NSBundle *bundle = [specifier.target bundle];
            NSArray *options = [specifier propertyForKey:@"options"];

            for(NSDictionary *stylesWithProperties in options) {
                LibellumStyleOptionView *optionView = [[LibellumStyleOptionView alloc] initWithFrame:CGRectZero appearanceOption:[stylesWithProperties objectForKey:@"appearanceOption"]];
                optionView.delegate = self;
                optionView.label.text = [stylesWithProperties objectForKey:@"label"];
                optionView.previewImage = [UIImage imageNamed:[stylesWithProperties objectForKey:@"image"] inBundle:bundle compatibleWithTraitCollection:nil];
                optionView.enabled = [optionView.appearanceOption isEqual:[specifier performGetter]];
                optionView.highlighted = [optionView.appearanceOption isEqual:[specifier performGetter]];
                optionView.translatesAutoresizingMaskIntoConstraints = NO;

                [optionViewArray addObject:optionView];
            }

            _stackView = [[UIStackView alloc] initWithArrangedSubviews:optionViewArray];
            _stackView.alignment = UIStackViewAlignmentCenter;
            _stackView.axis = UILayoutConstraintAxisHorizontal;
            _stackView.distribution = UIStackViewDistributionFillEqually;
            _stackView.spacing = 0;
            _stackView.translatesAutoresizingMaskIntoConstraints = NO;
            [self.contentView addSubview:_stackView];

            [NSLayoutConstraint activateConstraints:@[
            [_stackView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
            [_stackView.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor],
            [_stackView.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor],
            [_stackView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
            ]];
        }

        return self;
    }

    - (void)selectedOption:(LibellumStyleOptionView *)option {
        [self.specifier performSetterWithValue:option.appearanceOption];

        for(LibellumStyleOptionView *view in _stackView.arrangedSubviews) {
            [view updateViewForStyle:option.appearanceOption];
        }
    }
@end
