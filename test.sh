set -euo pipefail

export ESBMC_VERSION=latest
cd build/latest/
ninja -v src/esbmc/esbmc
cd ./../../

# ./build/latest/src/esbmc/esbmc ./suspects/vptr_members.cpp \
#                                                     --no-library \
#                                                     --std=c++20

echo "HPX TEST"
cd $HOME/.repos/writing/hpx_memory_usage_bug/
# ./build.sh

./test.sh


# cd build/latest/

# ctest -R "$(sed 's/[][\/.^$*+?{}()|]/\\&/g' ../../suspects/ctest_fails.txt | paste -sd '|' | sed 's/^/^(/;s/$/)$/')"
