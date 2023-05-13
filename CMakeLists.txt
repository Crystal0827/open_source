# Time: 12:03 2021.1.22
# Author: ysApollo 
# This is a file - "CMakeLists.txt" for OpenCV Project
cmake_minimum_required ( VERSION 3.15 )

set(PROJECT_NAME Lambda)
set(SRC Lambda.cpp)

project(${PROJECT_NAME})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIRS})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
