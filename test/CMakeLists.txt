cmake_minimum_required(VERSION 3.5)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(test_SRC EdgeTest.cpp gtest.cpp NodeTest.cpp DiGraphTest.cpp Helper.h)

add_executable(runUnitTests ${test_SRC})

target_link_libraries(runUnitTests ${GTEST_BOTH_LIBRARIES} core)

add_test(runUnitTests runUnitTests)
