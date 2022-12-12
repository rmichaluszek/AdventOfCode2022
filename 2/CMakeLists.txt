cmake_minimum_required(VERSION 3.24)

set(CMAKE_GENERATOR "Mingw Makefiles")
message("Generator is set to ${CMAKE_GENERATOR}")

project(3)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(2 src/main.cpp include/DataLoader.h src/DataLoader.cpp include/RockPaperScissors.h src/RockPaperScissors.cpp)

file(COPY data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")