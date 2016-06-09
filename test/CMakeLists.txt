cmake_minimum_required(VERSION 3.5)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(test_SRC EdgeTest.cpp gtest.cpp NodeTest.cpp DiGraphTest.cpp Helper.h NavigatorTest.cpp)

add_executable(runUnitTests ${test_SRC})

add_executable(givenTest giventest.cpp)

target_link_libraries(givenTest core ${OpenCV_LIBS})

target_link_libraries(runUnitTests ${GTEST_BOTH_LIBRARIES} core ${OpenCV_LIBS})

add_test(runUnitTests runUnitTests)
