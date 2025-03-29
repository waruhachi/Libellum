BUNDLE_NAME = LibellumPreferences
$(BUNDLE_NAME)_FILES = $(wildcard Controllers/*.m Cells/*.m Views/*.m)
$(BUNDLE_NAME)_CFLAGS = -fobjc-arc -Wno-deprecated-declarations
$(BUNDLE_NAME)_INSTALL_PATH = /Library/PreferenceBundles
$(BUNDLE_NAME)_FRAMEWORKS = UIKit AVFoundation
$(BUNDLE_NAME)_PRIVATE_FRAMEWORKS = Preferences AppSupport
$(BUNDLE_NAME)_EXTRA_FRAMEWORKS = Cephei CepheiPrefs
$(BUNDLE_NAME)_LIBRARIES = gcuniversal

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/bundle.mk
