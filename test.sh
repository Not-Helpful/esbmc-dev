use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

./build/latest/src/esbmc/esbmc ./suspects/lvalues.cpp 

# echo "HPX TEST"
# cd $HOME/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh

