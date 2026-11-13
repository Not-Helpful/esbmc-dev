export ESBMC_VERSION=master-gcc
VERSION=master-gcc
use.hs llvm 24
cd build/$VERSION/
ninja -v src/esbmc/esbmc
cd ./../../

# echo "SUSPECT TEST"
#  ./build/$VERSION/src/esbmc/esbmc /home/helpful/.repos/esbmc-dev/regression/esbmc-cpp/cpp/vector_reserve_realloc/main.cpp  \
#                                    --std=c++20

echo "HPX TEST"
cd ~/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

./test.sh

