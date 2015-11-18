LOCAL_PATH	:= $(call my-dir)

# Include LuaJIT static library
include $(CLEAR_VARS)
LOCAL_MODULE			:= libluajit
LOCAL_SRC_FILES			:= .build/$(TARGET_ARCH_ABI)/lib/libluajit-5.1.a
LOCAL_EXPORT_C_INCLUDES	:= $(LOCAL_PATH)/.build/$(TARGET_ARCH_ABI)/include/luajit-2.1
include $(PREBUILT_STATIC_LIBRARY)


# Main executable
include $(CLEAR_VARS)

LOCAL_MODULE			:= androluajit

# Include the luajit library
LOCAL_STATIC_LIBRARIES	:= libluajit

# Android lollipop
LOCAL_CFLAGS			+= -fPIE
LOCAL_LDFLAGS			+= -fPIE -pie

# Log
LOCAL_LDLIBS			:= -llog

LOCAL_C_INCLUDES		:= $(LOCAL_PATH)/lanes/src

FILE_LIST				:= $(wildcard $(LOCAL_PATH)/lanes/src/*.c)

LOCAL_SRC_FILES			+= main.c client.c
LOCAL_SRC_FILES			+= $(FILE_LIST:$(LOCAL_PATH)/%=%)

include $(BUILD_EXECUTABLE)