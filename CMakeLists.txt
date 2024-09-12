cmake_minimum_required(VERSION 3.30.1)                     # CMake version check
project(engine)                                            # Create project "engine"
set(CMAKE_CXX_STANDARD 20)                                 # Enable c++20 standard
set(SOURCE_FILES src/main.cpp)                             # Set main file "main.cpp"
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})      # Set executable target name

set(CMAKE_BUILD_TYPE Debug)


# Set path to dependencies subdirectory
set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

# Set path to src subdirectory
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Set path to res subdirectory
set(RES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)

#   +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+
#   |P|u|b|l|i|c| |L|i|b|r|a|r|i|e|s|
#   +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+

# Check for glfw
if (NOT EXISTS ${DEPENDENCIES_DIR}/glfw)
    message(FATAL_ERROR "The library ${DEPENDENCIES_DIR}/glfw does not exist")
else()
    add_subdirectory(${DEPENDENCIES_DIR}/glfw)                                  # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)                   # Link glfw
endif()


# Check for glad
if (NOT EXISTS ${DEPENDENCIES_DIR}/glad)
    message(FATAL_ERROR "The library ${DEPENDENCIES_DIR}/glad does not exist")
else()
    add_subdirectory(${DEPENDENCIES_DIR}/glad)                                 # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glad)                  # Link glad
endif()

# Check for glm
if (NOT EXISTS ${DEPENDENCIES_DIR}/glm)
    message(FATAL_ERROR "The library ${DEPENDENCIES_DIR}/glm does not exist")
else()
    add_subdirectory(${DEPENDENCIES_DIR}/glm)                                  # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glm)                   # Link glm
endif()

# Check for assimp
if (NOT EXISTS ${DEPENDENCIES_DIR}/assimp)
    message(FATAL_ERROR "The library ${DEPENDENCIES_DIR}/assimp does not exist")
else()
    add_subdirectory(${DEPENDENCIES_DIR}/assimp)                               # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE assimp)                # Link assimp
endif()

#   +-+-+ +-+-+-+-+-+-+-+
#   |M|y| |h|e|a|d|e|r|s|
#   +-+-+ +-+-+-+-+-+-+-+

if (NOT EXISTS ${SRC_DIR}/BackEnd)
    message(FATAL_ERROR "The library ${SRC_DIR}/BackEnd does not exist")
else()
    add_subdirectory(${SRC_DIR}/BackEnd)                                       # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE BackEnd)               # Link BackEnd
endif()

if (NOT EXISTS ${SRC_DIR}/Engine)
    message(FATAL_ERROR "The library ${SRC_DIR}/Engine does not exist")
else()
    add_subdirectory(${SRC_DIR}/Engine)                                        # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Engine)                # Link Engine
endif()

if (NOT EXISTS ${SRC_DIR}/GL_Shader)
    message(FATAL_ERROR "The library ${SRC_DIR}/GL_Shader does not exist")
else()
    add_subdirectory(${SRC_DIR}/GL_Shader)                                     # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE GL_Shader)             # Link GL_Shader
endif()

if (NOT EXISTS ${SRC_DIR}/Utility)
    message(FATAL_ERROR "The library ${SRC_DIR}/Utility does not exist")
else()
    add_subdirectory(${SRC_DIR}/Utility)                                       # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Utility)               # Link Utility
endif()

if (NOT EXISTS ${SRC_DIR}/Camera)
    message(FATAL_ERROR "The library ${SRC_DIR}/Camera does not exist")
else()
    add_subdirectory(${SRC_DIR}/Camera)                                        # Add subdirectory
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Camera)                # Link Camera
endif()

# +-+-+-+-+-+-+-+-+-+
# |R|e|s|o|u|r|c|e|s|
# +-+-+-+-+-+-+-+-+-+
if (NOT EXISTS ${RES_DIR})
    message(FATAL_ERROR "The resource folder ${RES_DIR} does not exist")
else()
    file (COPY ${RES_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()