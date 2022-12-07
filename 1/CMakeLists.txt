cmake_minimum_required(VERSION 3.24)
project(1)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        src
)

add_executable(1 src/main.cpp include/DataLoader.h src/DataLoader.cpp src/Elf.cpp src/Elves.cpp include/Elf.h include/Elves.h)

file(COPY data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")