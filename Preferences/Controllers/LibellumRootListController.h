@import Cephei;
@import CepheiPrefs;

#import <Preferences/PSSpecifier.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSliderTableCell.h>

#import "LibellumBackupViewController.h"

#import "../Views/LibellumHeaderView.h"
#import "../Views/LibellumAnimatedTitleView.h"
#import "../Definitions/PreferencesColorDefinitions.h"

@interface PSListController (iOS12Methods)
    - (BOOL)containsSpecifier:(id)arg1;
@end

@interface LibellumRootListController : HBRootListController
    @property (nonatomic, retain) NSMutableDictionary *savedSpecifiers;
@end
