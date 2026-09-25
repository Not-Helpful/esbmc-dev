use.hs llvm 24
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

echo "SUSPECT TEST"
 ./build/latest/src/esbmc/esbmc ./suspects/vtable_bug.cpp  \
                                   --std=c++20

# echo "HPX TEST"
# cd /home/helpful/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

# ./test.sh

# struct &$&$&$&hpx::lcos::detail::future_data_base<hpx::traits::detail::future_data_void>
