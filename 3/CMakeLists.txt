cmake_minimum_required(VERSION 3.24)
project(3)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(3 src/main.cpp include/DataLoader.h src/DataLoader.cpp)
