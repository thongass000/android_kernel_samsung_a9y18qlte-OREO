#!/bin/bash

FUNC_CLEAN(){
rm -rf out
mkdir out
}

FUNC_COMPILE(){
export CROSS_COMPILE=$(pwd)/toolchain/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-
export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out ARCH=arm64 KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y a9y18qlte_eur_open_defconfig
make -C $(pwd) O=$(pwd)/out ARCH=arm64 KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -j40
cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image
}

START_TIME=`date +%s`
FUNC_CLEAN
FUNC_COMPILE
END_TIME=`date +%s`

let "ELAPSED_TIME=$END_TIME-$START_TIME"
echo "Total compile time is $ELAPSED_TIME seconds"


