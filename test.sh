use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

echo "TEST ONE"
./build/latest/src/esbmc/esbmc ./suspects/self-ctor-arg-forward/main.py  
echo "TEST TWO"
./build/latest/src/esbmc/esbmc ./suspects/self-ctor-arg-forward_fail/main.py  

# echo "HPX TEST"
# cd $HOME/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh

