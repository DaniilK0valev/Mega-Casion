cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mega-Casion main.cpp)

enable_testing()
add_subdirectory(doctest)

add_executable(Mega-Casion_test test/test.cpp)
target_link_libraries(Mega-Casion_test doctest)