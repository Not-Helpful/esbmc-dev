use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

# ./build/latest/src/esbmc/esbmc ./suspects/vtable_bug.cpp  \
#                                   --std=c++20

cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
./build.sh

./test.sh
