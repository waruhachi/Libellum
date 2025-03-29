#import <roothide.h>
#import <UIKit/UIKit.h>

#import "../../Tweak/Vendor/MTMaterialView.h"
#import "../Definitions/PreferencesColorDefinitions.h"

@interface LibellumHeaderView : UIView
    - (instancetype)initWithTitle:(NSString *)title subtitles:(NSArray *)subtitles bundle:(NSBundle *)bundle;
@end

@interface SBWallpaperController : NSObject
    @property (nonatomic) NSInteger activeVariant;

    + (id)sharedInstance;
    - (id)_wallpaperViewForVariant:(NSInteger)arg0;
@end

@interface PBUIWallpaperViewController : UIViewController
@end

@interface PBUIPosterWallpaperViewController: UIViewController
@end

@interface PBUIPosterWallpaperRemoteViewController: UIViewController
@end

@interface NSObject (Undocumented)
    - (id)safeValueForKey:(NSString *)key;
@end
