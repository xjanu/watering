cmake_minimum_required(VERSION 3.0.0)

project(water CXX)

add_executable(water main.cpp deps/7seg/7seg.cpp)

# Arduino.h is included in hello_world.cpp, so link with Arduino core
target_link_arduino_libraries(water PRIVATE core)
target_include_directories(water PRIVATE deps/7seg)

# This is needed for the generation of HEX binary and uploading it
target_enable_arduino_upload(water)
