cmake_minimum_required(VERSION 3.27)
project(percolation)

set(CMAKE_CXX_STANDARD 20)

include_directories(libraries/Percolation/include)

add_executable(percolation
        libraries/Percolation/include/Percolation.hpp
        libraries/Percolation/include/PercolationStats.hpp
        libraries/Percolation/src/Percolation.cpp
        libraries/Percolation/src/PercolationStats.cpp
        src/main.cpp
)
