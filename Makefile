
AND_ARCH += armeabi, armeabi-v7a, mips, x86

all: luajit android_ndk android
	
luajit:
	./build_luajit armeabi
luajit_clean:
	./build_luajit clean

android:
	cd app && ./gradlew assembleDebug
android_clean:
	cd app && rm -rf build

android_ndk:
	cd app && ndk-build -C src/main
android_ndk_clean:
	cd app && ndk-build clean

install:
	cd app && ./gradlew installArmDebug
install_ndk:
	adb push app/src/main/libs/armeabi/androluajit /data/local/tmp/

.PHONY: clean
clean: luajit_clean android_clean android_ndk_clean