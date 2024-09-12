cmake_minimum_required(VERSION 3.30.1)  # CMake version check
project(Utility)                        # Create project "Utility"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard



add_library(Utility)
target_sources(Utility PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Utility.cpp)
target_include_directories(Utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Utility.h)