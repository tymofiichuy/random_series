cmake_minimum_required(VERSION 3.10)
project(random_series_generator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/generator/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/generator/main)

# set(SOURCES
    
# )

find_package(Boost CONFIG REQUIRED COMPONENTS multiprecision)

# add_executable()

# target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR})

# target_link_libraries(${PROJECT_NAME} PRIVATE Boost::multiprecision)