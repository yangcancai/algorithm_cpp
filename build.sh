cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/usr/bin/make.exe -DCMAKE_C_COMPILER=/usr/bin/gcc.exe -DCMAKE_CXX_COMPILER=/usr/bin/g++.exe -G "CodeBlocks - Unix Makefiles" ./
cmake --build ./build/linux --target algorithm_cpp -- -j 8
