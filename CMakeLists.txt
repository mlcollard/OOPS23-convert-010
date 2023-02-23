# @file CMakeLists.txt
# 
# CMake files for the convert example

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.19)

# project info
project(convert)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Use Debug build type if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# convert application
add_executable(convert convert.cpp)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Demo run command
add_custom_target(demo
        COMMENT "Run demo"
        COMMAND echo convert --lower "ABCD"
        COMMAND $<TARGET_FILE:convert> --lower "ABCD"
        COMMAND echo convert --upper "ABCD"
        COMMAND $<TARGET_FILE:convert> --upper "abcd"
        COMMAND echo convert --invalid "ABCD"
        COMMAND $<TARGET_FILE:convert> --invalid "ABCD" || true
        DEPENDS convert
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
