@import Cephei;
@import CepheiPrefs;

#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSliderTableCell.h>

#import "../Definitions/PreferencesColorDefinitions.h"

@interface LibellumCreditsListController : HBRootListController
    @property (nonatomic, retain) NSMutableDictionary *savedSpecifiers;
@end
