#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace BackEnd
{
void Init();
void create_Window();
void close_Window();
void error_Window();
void beginframe_Window();
void endframe_Window(GLFWwindow *window);
} // namespace BackEnd
