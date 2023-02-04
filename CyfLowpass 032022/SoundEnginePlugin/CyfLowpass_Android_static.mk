LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := CyfLowpassFX
LOCAL_MODULE_FILENAME := libCyfLowpassFX

LOCAL_SRC_FILES := ButterworthFilter.cpp CyfLowpassFX.cpp CyfLowpassFXParams.cpp

ifeq ($(PM5_CONFIG),debug_android_armeabi-v7a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -D_DEBUG -mfloat-abi=softfp -mfpu=neon -ffast-math -fvisibility=hidden -fno-omit-frame-pointer -g
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),debug_android_x86)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -D_DEBUG -ffast-math -fvisibility=hidden -fno-omit-frame-pointer -g
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),debug_android_arm64-v8a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -D_DEBUG -ffast-math -fvisibility=hidden -fno-omit-frame-pointer -g
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),debug_android_x86_64)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -D_DEBUG -ffast-math -fvisibility=hidden -fno-omit-frame-pointer -g
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_android_armeabi-v7a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -mfloat-abi=softfp -mfpu=neon -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_android_x86)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_android_arm64-v8a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_android_x86_64)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_armeabi-v7a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_ENABLE_ASSERTS -mfloat-abi=softfp -mfpu=neon -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_x86)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_ENABLE_ASSERTS -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_arm64-v8a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_ENABLE_ASSERTS -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_x86_64)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_ENABLE_ASSERTS -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -fno-omit-frame-pointer -g -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  cmd-strip :=
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),release_android_armeabi-v7a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_OPTIMIZED -mfloat-abi=softfp -mfpu=neon -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),release_android_x86)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_OPTIMIZED -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),release_android_arm64-v8a)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_OPTIMIZED -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  include $(BUILD_STATIC_LIBRARY)
endif

ifeq ($(PM5_CONFIG),release_android_x86_64)
  LOCAL_C_INCLUDES := D:/Program\ Files/Wwise\ 2021.1.6.7774/SDK/include
  LOCAL_CFLAGS := -DNDEBUG -DAK_OPTIMIZED -ffast-math -fvisibility=hidden -ffunction-sections -fdata-sections -O3
  LOCAL_CPPFLAGS := -Wno-invalid-offsetof -fvisibility=hidden -fno-rtti -fno-exceptions -std=c++14
  LOCAL_CONLYFLAGS := -std=c11
  include $(BUILD_STATIC_LIBRARY)
endif


all: $(LOCAL_INSTALLED)