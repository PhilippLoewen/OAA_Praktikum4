cmake_minimum_required(VERSION 3.5)
project(Praktikum3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

find_package(OpenCV REQUIRED)

include_directories(include)

add_subdirectory(test)

set(PRAKTIKUM3_SRC
        src/DiGraph.cpp src/Node.cpp src/Edge.cpp src/Navigator.cpp
        include/Priorityqueue.h include/liste.h include/DiGraph.h include/Node.h include/Edge.h
        include/OpenCVGraphVisualizer.h include/SimpleException.h include/GraphVisualizer.h
        include/Navigator.h include/Bicycle.h include/Car.h include/Motorcycle.h include/Vehicle.h)


add_library(core ${PRAKTIKUM3_SRC})

add_executable(Praktikum3 main.cpp)

target_link_libraries(Praktikum3 core ${OpenCV_LIBS})