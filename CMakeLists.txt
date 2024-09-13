cmake_minimum_required(VERSION 3.30.1)                     # CMake version check
project(engine)                                            # Create project "engine"
set(CMAKE_CXX_STANDARD 20)                                 # Enable c++20 standard
set(SOURCE_FILES src/main.cpp)                             # Set main file "main.cpp"
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})      # Set executable target name
set(CMAKE_BUILD_TYPE Debug)                                # Set CMake build type Debug/Release

set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)                         # Set env variable for dependencies subdirectory

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)                                           # Set env variable for src subdirectory

set(RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)                                           # Set env variable for res subdirectory

#   +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+
#   |P|u|b|l|i|c| |L|i|b|r|a|r|i|e|s|
#   +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+

set(DEPENDENCIES "glfw;glad;glm;assimp")                                               # List of dependencies

foreach(ITEM IN LISTS DEPENDENCIES)
    if (NOT EXISTS ${DEPENDENCIES_DIR}/${ITEM})
        message(FATAL_ERROR "The library ${DEPENDENCIES_DIR}/${ITEM} does not exist")
    else()
        add_subdirectory(${DEPENDENCIES_DIR}/${ITEM})                                  # Add subdirectory
        target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${ITEM})                   # Link library
    endif()
endforeach()

#   +-+-+ +-+-+-+-+-+-+-+
#   |M|y| |h|e|a|d|e|r|s|
#   +-+-+ +-+-+-+-+-+-+-+

set(HEADERS "BackEnd;Engine;GL_Shader;Utility;Camera")                                 # List of headers

foreach(ITEM IN LISTS HEADERS)
    if (NOT EXISTS ${SRC_DIR}/${ITEM})
        message(FATAL_ERROR "The header ${SRC_DIR}/${ITEM} does not exist")
    else()
        add_subdirectory(${SRC_DIR}/${ITEM})                                           # Add subdirectory
        target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${ITEM})                   # Link library
    endif()
endforeach()

# +-+-+-+-+-+-+-+-+-+
# |R|e|s|o|u|r|c|e|s|
# +-+-+-+-+-+-+-+-+-+

if (NOT EXISTS ${RES_DIR})
    message(FATAL_ERROR "The resource folder ${RES_DIR} does not exist")
else()
    file (COPY ${RES_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()