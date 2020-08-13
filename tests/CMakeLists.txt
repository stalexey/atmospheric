cmake_minimum_required(VERSION 3.5)

add_compile_options(-std=c++14)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories("/opt/local/include/libomp")
add_definitions("-Xpreprocessor -fopenmp")

link_directories("/opt/local/lib/libomp")
add_link_options("-lomp")

add_executable(run run.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/plot.sh
    ${CMAKE_CURRENT_BINARY_DIR}/plot.sh COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/display.gnu
    ${CMAKE_CURRENT_BINARY_DIR}/display.gnu COPYONLY)
