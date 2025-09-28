cmake_minimum_required(VERSION 3.10)
project(random_series_generator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/generator/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/generator/main)

set(SOURCES
    ${SOURCE_DIR}/exp_generators.cpp 
    ${SOURCE_DIR}/L_generators.cpp
    ${SOURCE_DIR}/lehmer_32.cpp
    ${SOURCE_DIR}/librarian.cpp
    ${SOURCE_DIR}/wolfram.cpp
    ${MAIN_DIR}/generator.cpp
)

add_executable(random_series_generator ${MAIN_DIR}/driver.cpp ${SOURCES})

target_link_libraries(random_series_generator PRIVATE LFSR)
target_include_directories(random_series_generator PRIVATE ${SOURCE_DIR})