use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

echo "SUSPECT TEST"
 ./build/latest/src/esbmc/esbmc /home/helpful/.repos/esbmc-dev/regression/esbmc-cpp/cpp/vector_reserve_realloc/main.cpp  \
                                   --std=c++20

# echo "HPX TEST"
# cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh

