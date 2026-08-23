use.hs llvm USR-patch
cd build/USR-patch/
ninja -v src/esbmc/esbmc
cd ./../../

# cd build/no-patch/
# ninja -v src/esbmc/esbmc
# cd ./../../

# ./build/USR-patch/src/esbmc/esbmc ./suspects/USRfails.cpp \
#                               --std=c++20

# ./build/no-USR-patch/src/esbmc/esbmc ./suspects/USRfails.cpp \
#                               --std=c++20

use.hs llvm default

cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
./build.sh

./test.sh
