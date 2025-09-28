cmake_minimum_required(VERSION 3.10)
project(random_series)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lfsr)
add_subdirectory(generator)
add_subdirectory(criterion)