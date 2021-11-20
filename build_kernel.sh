#!/bin/bash

rm -rf out
mkdir out

export CROSS_COMPILE=$(pwd)/toolchain/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-
export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out ARCH=arm64 KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y a9y18qlte_eur_open_defconfig
make -C $(pwd) O=$(pwd)/out ARCH=arm64 KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -j40

cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image

