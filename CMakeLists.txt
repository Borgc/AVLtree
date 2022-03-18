cmake_minimum_required(VERSION 3.17)
project(bintree)

set(CMAKE_CXX_STANDARD 14)

add_library(library.cpp library.h main.cpp)
add_executable(main main.cpp library.cpp)