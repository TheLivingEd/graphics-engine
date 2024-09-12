cmake_minimum_required(VERSION 3.30.1)  # CMake version check
project(BackEnd)                        # Create project "BackEnd"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

add_library(BackEnd)
target_sources(BackEnd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/BackEnd.cpp)
target_include_directories(BackEnd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/BackEnd.h)

# Include the glad library
target_include_directories(BackEnd PUBLIC ../../dependencies/glad/include)

# Include the glfw library
target_include_directories(BackEnd PUBLIC ../../dependencies/glfw/include)

# Include the glm library
target_include_directories(BackEnd PUBLIC ../../dependencies/glm)