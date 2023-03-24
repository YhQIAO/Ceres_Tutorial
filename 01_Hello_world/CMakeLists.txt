cmake_minimum_required(VERSION 3.10)
project(ceres_hello_world_demo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Ceres REQUIRED)

include_directories(${CERES_INCLUDE_DIRS})
include_directories(.)

add_executable(${PROJECT_NAME} hello_world_main.cpp hello_world.cpp)

# 定义需要的库
# ${CERES_LIBRARIES}只有一项ceres，后面很多库都没有。。。所以需要自己定义需要链接那些库。
# set(LIBS ${CERES_LIBRARIES} umfpack cxsparse glog gflags gomp
#       ccolamd btf klu cholmod lapack blas camd amd pthread)

target_link_libraries(${PROJECT_NAME} ${CERES_LIBRARIES})