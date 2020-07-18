rem build
"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 16 2019" ./ -B build/vs_2019
"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" --build D:\cam\c++\algorithm_cpp\build\vs_2019 --target algorithm_cpp --config Debug
build\vs_2019\Debug\algorithm_cpp.exe
pause
