cd build/debug/
ninja -v src/esbmc/esbmc
cd ./../../

./build/debug/src/esbmc/esbmc ./suspects/USRfails.cpp \
   --std=c++20

# cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh
