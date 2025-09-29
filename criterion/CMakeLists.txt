cmake_minimum_required(VERSION 3.10)
project(random_series_criterion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/criterion/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/criterion/main)

set(SOURCES
    ${SOURCE_DIR}/criterion.cpp
    ${SOURCE_DIR}/io_management.cpp
)

add_executable(random_series_test ${MAIN_DIR}/driver.cpp ${SOURCES})

target_include_directories(random_series_test PRIVATE ${SOURCE_DIR})