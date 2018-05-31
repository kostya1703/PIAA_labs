cmake_minimum_required(VERSION 2.8.12.2)

project(lab6)

add_library(func ./src/func.cpp)


target_include_directories(func PUBLIC ./hdr)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable (Standart src/stand_alg.cpp)
add_executable (Joker src/joker_alg.cpp)

target_link_libraries(Standart func)
target_link_libraries(Joker func)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests test/test.cpp)
target_link_libraries(tests func)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
