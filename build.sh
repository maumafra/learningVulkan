rm -rf CMakeCache.txt CMakeFiles/ build

mkdir build
cd build
cmake --preset "release" ..
#cmake --build .