cmake_minimum_required(VERSION 2.8.12.2)

project(lab5)

add_library(func ./src/func.cpp)

target_include_directories(func PUBLIC ./hdr)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable (kmp ./src/kmp.cpp)
add_executable (shift ./src/shift.cpp)
add_executable (NAIVEvsKMP ./src/NAIVEvsKMP.cpp)


target_link_libraries(kmp func)
target_link_libraries(NAIVEvsKMP func)
target_link_libraries(shift func)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests test/test.cpp)
target_link_libraries(tests func)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)