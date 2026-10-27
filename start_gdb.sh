use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../


gdb \
  -ex "break clang_cpp_convert_vft.cpp:54" \
  -ex "run" \
  --args $HOME/.repos/esbmc-dev/build/latest/src/esbmc/esbmc \
    ../writing/hpx_memory_usage_bug/bug.cpp \
    -I $INSTALLS/hpx/built-with-clang-24/include/ \
    --no-abstracted-cpp-includes \
    --no-library \
    -fsized-deallocation \
    --std=c++23
