cmake_minimum_required(VERSION 3.24)
project(2)

set(CMAKE_C_COMPILER "g++-6.3.0")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++")

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(2 src/main.cpp include/DataLoader.h src/DataLoader.cpp)

file(COPY data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")