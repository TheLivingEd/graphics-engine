cmake_minimum_required(VERSION 3.30.1)  # CMake version check
project(Engine)                         # Create project "Engine"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

add_library(Engine)
target_sources(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Engine.cpp)
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Engine.h)

# Include the glad library
target_include_directories(Engine PUBLIC ../../dependencies/glad/include)

# Include the glfw library
target_include_directories(Engine PUBLIC ../../dependencies/glfw/include)