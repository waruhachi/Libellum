TWEAK_NAME = Libellum

$(TWEAK_NAME)_FILES = $(TWEAK_NAME).x $(wildcard Controller/*.m Manager/*.m)
$(TWEAK_NAME)_CFLAGS = -fobjc-arc
$(TWEAK_NAME)_FRAMEWORKS = EventKit
$(TWEAK_NAME)_PRIVATE_FRAMEWORKS = CoverSheet
$(TWEAK_NAME)_EXTRA_FRAMEWORKS = Cephei
$(TWEAK_NAME)_LIBRARIES = gcuniversal


include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/tweak.mk
