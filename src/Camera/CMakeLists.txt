cmake_minimum_required(VERSION 3.30.1)  # CMake version check
project(Camera)                        # Create project "Camera"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

add_library(Camera)
target_sources(Camera PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp)
target_include_directories(Camera PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Camera.h)




# Include the glad library
target_include_directories(Camera PUBLIC ../../dependencies/glad/include)


# Include the glfw library
target_include_directories(Camera PUBLIC ../../dependencies/glfw/include)

# Include the glm library
target_include_directories(Camera PUBLIC ../../dependencies/glm)







