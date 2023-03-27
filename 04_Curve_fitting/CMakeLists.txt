cmake_minimum_required(VERSION 3.10)
project(ceres_curve_fitting_demo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Ceres REQUIRED)

include_directories(${CERES_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} curve_fitting.cpp)
add_executable(robost_${PROJECT_NAME} robost_curve_fitting.cpp)
target_link_libraries(${PROJECT_NAME} ${CERES_LIBRARIES} )
target_link_libraries(robost_${PROJECT_NAME} ${CERES_LIBRARIES} )