cmake_minimum_required(VERSION 3.16)
project(algorithm_cpp)
set(CMAKE_CXX_STANDARD 11)
aux_source_directory(sort SORT_SRC)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(algorithm_cpp
        main.cpp
        ${SORT_SRC})