cmake_minimum_required(VERSION 3.0.0)

project(water CXX)

list(APPEND WATER_SOURCES
    "src/main.cpp"
    "src/sense.cpp"
    "src/moist.cpp"
    "src/water.cpp"
    "deps/7seg/7seg.cpp"
)

add_executable(water ${WATER_SOURCES})

# Link with Arduino core (Arduino.h)
target_link_arduino_libraries(water PRIVATE core)
target_include_directories(water PRIVATE deps/7seg include)

# This is needed for the generation of HEX binary and uploading it
target_enable_arduino_upload(water)
