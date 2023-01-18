cmake_minimum_required(VERSION 3.15)
project(c9y-cmake-test
        VERSION 0.1.0
        DESCRIPTION "CMake build test for c9y"
        LANGUAGES CXX
)

find_package(c9y CONFIG REQUIRED)

add_executable(c9y-cmake-test   
  main.cpp
)
target_compile_features(c9y-cmake-test PRIVATE cxx_std_20)
target_link_libraries(c9y-cmake-test PRIVATE c9y::c9y)
