rm -rf CMakeCache.txt CMakeFiles/ build

mkdir build
cd build
cmake --preset "clang-debug" ..
#cmake --build .