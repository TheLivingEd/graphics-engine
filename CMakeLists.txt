set(CMAKE_BUILD_TYPE Debug)                                # Set CMake build type Debug/Release
cmake_minimum_required(VERSION 3.30.3)                     # CMake version check
project(engine)                                            # Create project "engine"
set(CMAKE_CXX_STANDARD 20)                                 # Enable c++20 standard
set(SOURCE_FILES src/main.cpp)                             # Set main file "main.cpp"
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})      # Set executable target name

set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)                         # Set env variable for dependencies subdirectory

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)                                           # Set env variable for src subdirectory

set(RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)                                           # Set env variable for res subdirectory

# +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+
# |P|u|b|l|i|c| |L|i|b|r|a|r|i|e|s|
# +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+

set(DEPENDENCIES "glfw;glad;glm;assimp")                                               # List of dependencies

foreach(ITEM IN LISTS DEPENDENCIES)
    if (NOT EXISTS ${DEPENDENCIES_DIR}/${ITEM})
        message(FATAL_ERROR "Cannot find: ${ITEM}")
    else()
        add_subdirectory(${DEPENDENCIES_DIR}/${ITEM})                                  # Add subdirectory
    endif()
endforeach()

add_subdirectory(${SRC_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE engine_lib)

# +-+-+-+-+-+-+-+-+-+
# |R|e|s|o|u|r|c|e|s|
# +-+-+-+-+-+-+-+-+-+

if (NOT EXISTS ${RES_DIR})
    message(FATAL_ERROR "The resource folder ${RES_DIR} does not exist")
else()
    file (COPY ${RES_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()