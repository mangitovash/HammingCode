cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HammingCodeProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(HammingProgram main.cpp HammingCode.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})
