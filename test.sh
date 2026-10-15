use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

# echo "TEST ONE"
# ./build/latest/src/esbmc/esbmc ./suspects/test_concept_spec.cpp \
#                                --std=c++20
# echo "TEST TWO"
# ./build/latest/src/esbmc/esbmc ./suspects/test_requries_expr.cpp \
#                                --std=c++20
# echo "TEST ONE"
# ./build/latest/src/esbmc/esbmc ./suspects/stackoverflow.cpp  \
#                                --std=c++20


echo "HPX TEST"
cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
./build.sh

./test.sh

