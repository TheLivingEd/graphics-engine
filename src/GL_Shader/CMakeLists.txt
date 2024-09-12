cmake_minimum_required(VERSION 3.30.1)  # CMake version check
project(GL_Shader)                      # Create project "GL_Shader"
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

add_library(GL_Shader)
target_sources(GL_Shader PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/GL_Shader.cpp)
target_include_directories(GL_Shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/GL_Shader.h)




# Include the glad library
target_include_directories(GL_Shader PUBLIC ../../dependencies/glad/include)

# Include the glfw library
target_include_directories(GL_Shader PUBLIC ../../dependencies/glfw/include)

