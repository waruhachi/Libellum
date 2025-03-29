@import Cephei;
@import CepheiPrefs;

#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSListController.h>

#import "../Definitions/PreferencesColorDefinitions.h"

@interface PSListController (iOS12Methods)
    - (BOOL)containsSpecifier:(id)arg1;
@end

@interface LibellumColorsListController : HBRootListController
    @property (nonatomic, retain) NSMutableDictionary *savedSpecifiers;
@end
