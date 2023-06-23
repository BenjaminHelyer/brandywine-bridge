cmake_minimum_required(VERSION 3.14)
project(brandywine_bridge)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory (external)

add_subdirectory (src)

enable_testing ()
add_subdirectory (tests)