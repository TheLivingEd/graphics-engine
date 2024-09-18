#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace BackEnd {
void Init();
void w_Create();
void w_Close();
void w_ErrorCall();
void w_BeginFrame();
void w_EndFrame();
void grid();
} // namespace BackEnd
