#include "LibellumColorsListController.h"

@implementation LibellumColorsListController
	- (id)init {
        self = [super init];

        if(self) {
            HBAppearanceSettings *appearanceSettings = [[HBAppearanceSettings alloc] init];
            appearanceSettings.navigationBarBackgroundColor = SecondaryColor;
            appearanceSettings.navigationBarTintColor = PrimaryColor;
            appearanceSettings.showsNavigationBarShadow = NO;
            appearanceSettings.tableViewCellSeparatorColor = [UIColor clearColor];
            appearanceSettings.tintColor = PrimaryColor;
            self.hb_appearanceSettings = appearanceSettings;
        }

		return self;
	}

	- (NSArray *)specifiers {
		if(!_specifiers) {
			_specifiers = [self loadSpecifiersFromPlistName:@"Colors" target:self];

			NSArray *chosenIDs = @[@"SET_TINT_COLOR"];
			self.savedSpecifiers = (self.savedSpecifiers) ?: [[NSMutableDictionary alloc] init];

            for(PSSpecifier *specifier in _specifiers) {
				if([chosenIDs containsObject:[specifier propertyForKey:@"id"]]) {
					[self.savedSpecifiers setObject:specifier forKey:[specifier propertyForKey:@"id"]];
				}
			}
		}

		return _specifiers;
	}

	- (void)setPreferenceValue:(id)value specifier:(PSSpecifier *)specifier {
		[super setPreferenceValue:value specifier:specifier];

		[self toggleSpecifiersVisibility:YES];
	}

	- (void)reloadSpecifiers {
		[super reloadSpecifiers];

		[self toggleSpecifiersVisibility:NO];
	}

	- (void)toggleSpecifiersVisibility:(BOOL)animated {
		HBPreferences *preferences = [HBPreferences preferencesForIdentifier:@"com.lacertosusrepo.libellumpreferences"];

		if(![[preferences objectForKey:@"blurStyle"] isEqualToString:@"adaptive"]) {
			[self removeSpecifier:[self specifierForID:@"IGNORE_ADAPTIVE_PRESET_COLORS"] animated:animated];
		}

		if(![[preferences objectForKey:@"blurStyle"] isEqualToString:@"colorized"]) {
			[self removeSpecifier:[self specifierForID:@"SET_BACKGROUND_COLOR"] animated:animated];
		}

		if([preferences boolForKey:@"useKalmTintColor"]) {
			[self removeSpecifier:self.savedSpecifiers[@"SET_TINT_COLOR"] animated:animated];
		} else if(![self containsSpecifier:self.savedSpecifiers[@"SET_TINT_COLOR"]]) {
			[self insertSpecifier:self.savedSpecifiers[@"SET_TINT_COLOR"] afterSpecifierID:@"SET_LOCK_ICON_COLOR" animated:animated];
		}
	}

	- (void)viewDidLoad {
		[super viewDidLoad];

		self.navigationController.navigationBar.prefersLargeTitles = NO;
		self.navigationItem.largeTitleDisplayMode = UINavigationItemLargeTitleDisplayModeNever;

		// Adds respring button in top right of preference pane and hide any cells
		[self respringStateFromButton:nil];
		[self toggleSpecifiersVisibility:NO];
	}

	- (void)respringStateFromButton:(UIBarButtonItem *)button {
		switch (button.tag) {
			case 0: // Apply
                {
                    UIBarButtonItem *applyButton = [[UIBarButtonItem alloc] initWithTitle:@"Apply" style:UIBarButtonItemStyleDone target:self action:@selector(respringStateFromButton:)];
                    applyButton.tintColor = PrimaryColor;
                    applyButton.tag = 1;
                    [self.navigationItem setRightBarButtonItem:applyButton animated:YES];
                }
                break;

			case 1:	// Are you sure?
                {
                    UIBarButtonItem *respringButton = [[UIBarButtonItem alloc] initWithTitle:@"Are you sure?" style:UIBarButtonItemStyleDone target:[HBRespringController class] action:@selector(respring)];
                    respringButton.tintColor = [UIColor colorWithRed:0.90 green:0.23 blue:0.23 alpha:1.00];
                    respringButton.tag = 0;
                    [self.navigationItem setRightBarButtonItem:respringButton animated:YES];

                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                        [self respringStateFromButton:respringButton];
                    });
                }
                break;
		}
	}

	- (void)viewDidAppear:(BOOL)animated {
		[super viewDidAppear:animated];

		// Adds icon to center of preferences
		if(!self.navigationItem.titleView) {
			UIImageView *iconView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"icons/colors.png" inBundle:[self bundle] compatibleWithTraitCollection:nil]];
			self.navigationItem.titleView = iconView;
			self.navigationItem.titleView.alpha = 0;

			[UIView animateWithDuration:0.2 animations:^{
				self.navigationItem.titleView.alpha = 1;
			}];
		}
	}

	- (UIUserInterfaceStyle)overrideUserInterfaceStyle {
		return UIUserInterfaceStyleDark;
	}

@end
