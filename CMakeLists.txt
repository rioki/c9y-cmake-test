cmake_minimum_required(VERSION 3.8)
project(rsig-cmake-test CXX)

find_package(c9y CONFIG REQUIRED)

set(CMAKE_SHARED_LIBRARY_PREFIX)
set(CMAKE_STATIC_LIBRARY_PREFIX)

set(SOURCES
  main.cpp
)

add_executable(c9y-cmake-test ${SOURCES})

target_link_libraries(c9y-cmake-test PRIVATE c9y::c9y)

set_target_properties(c9y-cmake-test PROPERTIES
  CXX_STANDARD 20
)
