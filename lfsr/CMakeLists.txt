cmake_minimum_required(VERSION 3.10)
project(lfsr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/lfsr/src)

set(SOURCES
    ${SOURCE_DIR}/lfsr_32.cpp
    ${SOURCE_DIR}/lfsr_128.cpp
)

find_package(Boost CONFIG REQUIRED COMPONENTS multiprecision)

add_library(LFSR STATIC ${SOURCES})

target_include_directories(LFSR PUBLIC ${SOURCE_DIR})
target_link_libraries(LFSR PUBLIC Boost::multiprecision)