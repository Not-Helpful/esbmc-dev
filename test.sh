use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

echo "SUSPECT TEST1"
./build/latest/src/esbmc/esbmc ./suspects/stackoverflow.cpp \
                               -DCASE=1 \
                               --std=c++20
# echo "SUSPECT TEST2"
# ./build/latest/src/esbmc/esbmc ./suspects/stackoverflow.cpp \
#                                -DCASE=2 \
#                                --std=c++20
echo "SUSPECT TEST3"
./build/latest/src/esbmc/esbmc ./suspects/stackoverflow.cpp \
                               -DCASE=3 \
                               --std=c++20

# echo "CONTROL TEST"
# ./build/latest/src/esbmc/esbmc ./suspects/pass.cpp \
#                                --std=c++20



# echo "HPX TEST"
# cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh

