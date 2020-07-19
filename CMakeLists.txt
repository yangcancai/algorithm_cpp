cmake_minimum_required(VERSION 3.16)
project(algorithm_cpp)
set(CMAKE_CXX_STANDARD 11)
aux_source_directory(sort SORT_SRC)
aux_source_directory(test TEST_SRC)
include_directories(${PROJECT_SOURCE_DIR})
if (MSVC)
    include_directories(${PROJECT_SOURCE_DIR}/Deps/vcpkg/installed/x64-windows-static/include)
elseif(APPLE)
    include_directories(${PROJECT_SOURCE_DIR}/Deps/vcpkg/installed/x64-os/include)
    else()
    include_directories(${PROJECT_SOURCE_DIR}/Deps/vcpkg/installed/x64-linux/include)
endif ()
if(CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(DepsLib ${PROJECT_SOURCE_DIR}/Deps/lib/Debug ${PROJECT_SOURCE_DIR}/Deps/lib/Debug/manual-link)
else()
    set(DepsLib ${PROJECT_SOURCE_DIR}/Deps/lib/Release ${PROJECT_SOURCE_DIR}/Deps/lib/Release/manual-link)
endif()
link_directories(${DepsLib})

if (MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELWITHDEBINFO
        )
foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
   # set(${CompilerFlag} "${${CompilerFlag}}" CACHE STRING "msvc compiler flags" FORCE)
    message("MSVC flags: ${CompilerFlag}:${${CompilerFlag}}")
endforeach()
else()
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -g -ggdb -DDEBUG -fPIC")
else()
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11 -O3 -Wall")
endif()
endif()
add_executable(algorithm_cpp
        main.cpp
        ${TEST_SRC}
        ${SORT_SRC})
if (MSVC)
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        # equal to #pragma comment(lib,"gtestd.lib")
    target_link_libraries(algorithm_cpp gtestd.lib)
        else()
    target_link_libraries(algorithm_cpp gtest.lib)
        endif()
endif()