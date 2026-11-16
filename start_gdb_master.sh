use.hs llvm bootstrap
cd build/master/
ninja -v src/esbmc/esbmc
cd ./../../


gdb \
  -ex "run" \
  --args $HOME/.repos/esbmc-dev/build/master/src/esbmc/esbmc \
    ../writing/hpx_memory_usage_bug/bug.cpp \
    -I $INSTALLS/hpx/built-with-clang-24/include/ \
    --no-abstracted-cpp-includes \
    --no-library \
    -fsized-deallocation \
    --std=c++23
