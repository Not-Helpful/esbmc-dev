#!/bin/sh
use.hs llvm 22-with-rtti 
VERSION=no-USR-patch
BUILD=./build/${VERSION}

rm -rf $BUILD
mkdir -p build
mkdir -p $BUILD

LLVM_PREFIX=$(llvm-config --prefix)
LLVM_FLAGS=$(llvm-config --ldflags --libs all | xargs)

# -DLLVM_DIR=/home/helpful/.installs/llvm/16/ .
# -DClang_DIR=/home/helpful/.installs/llvm/16/ \
    
CXX=clang++ CC=clang cmake -B $BUILD -G Ninja \
            -DCMAKE_INSTALL_PREFIX=$INSTALLS/esbmc/$VERSION \
            -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
            -DCMAKE_CXX_FLAGS="-O0 -g3 -ggdb -w" \
            -DCMAKE_C_FLAGS="-O0 -g3 -ggdb -w" \
            -DCMAKE_BUILD_TYPE=Debug \
            -DCLANG_LINK_CLANG_DYLIB="ON" \
            -DBUILD_TESTING=OFF \
            -DCMAKE_CXX_STANDARD=23 \
            -DENABLE_Z3="ON" \
            -DLLVM_DIR=$LLVM_PREFIX/lib/cmake/llvm \
            -DClang_DIR=$LLVM_PREFIX/lib/cmake/clang \
            -DClang_ROOT=$LLVM_PREFIX \
            -DOVERRIDE_CLANG_HEADER_DIR=$LLVM_PREFIX/include/clang .

cd $BUILD
ninja -v
ninja install
cd ../..

clang++ --version
use.hs llvm USR-patch
