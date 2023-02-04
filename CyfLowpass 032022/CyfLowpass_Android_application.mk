APP_BUILD_SCRIPT := $(call my-dir)/CyfLowpass_Android.mk
PM5_HELP := true

ifeq ($(PM5_CONFIG),debug_android_armeabi-v7a)
  APP_OPTIM := debug
  NDK_DEBUG := 1
  APP_ABI := armeabi-v7a
  CONFIGURATION := Debug
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),debug_android_x86)
  APP_OPTIM := debug
  NDK_DEBUG := 1
  APP_ABI := x86
  CONFIGURATION := Debug
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),debug_android_arm64-v8a)
  APP_OPTIM := debug
  NDK_DEBUG := 1
  APP_ABI := arm64-v8a
  CONFIGURATION := Debug
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),debug_android_x86_64)
  APP_OPTIM := debug
  NDK_DEBUG := 1
  APP_ABI := x86_64
  CONFIGURATION := Debug
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_android_armeabi-v7a)
  APP_OPTIM := release
  APP_ABI := armeabi-v7a
  CONFIGURATION := Profile
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_android_x86)
  APP_OPTIM := release
  APP_ABI := x86
  CONFIGURATION := Profile
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_android_arm64-v8a)
  APP_OPTIM := release
  APP_ABI := arm64-v8a
  CONFIGURATION := Profile
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_android_x86_64)
  APP_OPTIM := release
  APP_ABI := x86_64
  CONFIGURATION := Profile
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_armeabi-v7a)
  APP_OPTIM := release
  APP_ABI := armeabi-v7a
  CONFIGURATION := Profile_EnableAsserts
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_x86)
  APP_OPTIM := release
  APP_ABI := x86
  CONFIGURATION := Profile_EnableAsserts
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_arm64-v8a)
  APP_OPTIM := release
  APP_ABI := arm64-v8a
  CONFIGURATION := Profile_EnableAsserts
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),profile_enableasserts_android_x86_64)
  APP_OPTIM := release
  APP_ABI := x86_64
  CONFIGURATION := Profile_EnableAsserts
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  cmd-strip :=
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),release_android_armeabi-v7a)
  APP_OPTIM := release
  APP_ABI := armeabi-v7a
  CONFIGURATION := Release
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),release_android_x86)
  APP_OPTIM := release
  APP_ABI := x86
  CONFIGURATION := Release
  APP_PLATFORM := android-16
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),release_android_arm64-v8a)
  APP_OPTIM := release
  APP_ABI := arm64-v8a
  CONFIGURATION := Release
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  PM5_HELP := false
endif

ifeq ($(PM5_CONFIG),release_android_x86_64)
  APP_OPTIM := release
  APP_ABI := x86_64
  CONFIGURATION := Release
  APP_PLATFORM := android-21
  APP_STL := c++_static
  NDK_TOOLCHAIN_VERSION := 4.9
  PM5_HELP := false
endif

ifeq ($(PM5_HELP),true)
  $(info )
  $(info Usage:)
  $(info $()  ndk-build PM5_CONFIG=<config>)
  $(info )
  $(info CONFIGURATIONS:)
  $(info $()  debug_android_armeabi-v7a)
  $(info $()  debug_android_x86)
  $(info $()  debug_android_arm64-v8a)
  $(info $()  debug_android_x86_64)
  $(info $()  profile_android_armeabi-v7a)
  $(info $()  profile_android_x86)
  $(info $()  profile_android_arm64-v8a)
  $(info $()  profile_android_x86_64)
  $(info $()  profile_enableasserts_android_armeabi-v7a)
  $(info $()  profile_enableasserts_android_x86)
  $(info $()  profile_enableasserts_android_arm64-v8a)
  $(info $()  profile_enableasserts_android_x86_64)
  $(info $()  release_android_armeabi-v7a)
  $(info $()  release_android_x86)
  $(info $()  release_android_arm64-v8a)
  $(info $()  release_android_x86_64)
  $(info )
  $(info For more ndk-build options, see https://developer.android.com/ndk/guides/ndk-build.html)
  $(info )
  $(error Set PM5_CONFIG and try again)
endif