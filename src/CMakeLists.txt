cmake_minimum_required(VERSION 3.30.3) 
set(CMAKE_CXX_STANDARD 20)


set(engine_src                                                                    
	${CMAKE_CURRENT_LIST_DIR}/BackEnd/BackEnd.cpp
	${CMAKE_CURRENT_LIST_DIR}/Camera/Camera.cpp
	${CMAKE_CURRENT_LIST_DIR}/Engine/Engine.cpp
	${CMAKE_CURRENT_LIST_DIR}/GL_Shader/GL_Shader.cpp
	${CMAKE_CURRENT_LIST_DIR}/Utility/Utility.cpp
	)

set(engine_hdr
	${CMAKE_CURRENT_LIST_DIR}/BackEnd/BackEnd.h
	${CMAKE_CURRENT_LIST_DIR}/Camera/Camera.h
	${CMAKE_CURRENT_LIST_DIR}/Engine/Engine.h
	${CMAKE_CURRENT_LIST_DIR}/GL_Shader/GL_Shader.h
	${CMAKE_CURRENT_LIST_DIR}/Utility/Utility.h
	${CMAKE_CURRENT_LIST_DIR}/Common.h
	)

add_library(engine_lib STATIC ${engine_src})

target_link_libraries(engine_lib PRIVATE
    glad
	glfw
	glm
	assimp
)
 
add_custom_target(format COMMAND
    clang-format -style=file -i ${engine_src} ${engine_hdr}
	COMMENT "Running clang-format on source and header files"
	VERBATIM
)