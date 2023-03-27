cmake_minimum_required(VERSION 3.10)
project(ceres_powell_function_demo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Ceres REQUIRED)

include_directories(${CERES_INCLUDE_DIRS})


add_executable(${PROJECT_NAME}_powell main.cpp)

target_link_libraries(${PROJECT_NAME}_powell ${CERES_LIBRARIES} )
