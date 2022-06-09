cmake_minimum_required(VERSION 3.23.2)

project(FEX VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(fex ${SOURCES})

target_include_directories(fex PUBLIC headers)
target_link_libraries(fex -lsfml-system -lsfml-window -lsfml-graphics)