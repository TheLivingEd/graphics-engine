#include "BackEnd.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>

#include "../Common.h"
#include "../Object/Object.h"
#include "../Shader/Shader.h"

namespace BackEnd
{

void Init()
{
	create_Window();
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(_window))
	{
		// Render here
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		endframe_Window(_window);
		beginframe_Window();
	}
	close_Window();
	return;
}

void create_Window()
{
	// Initialize GLFW library
	glfwInit();
	error_Window();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// GLFW window creation
	_window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (!_window)
	{
		close_Window();
		error_Window();
	}
	// Set window's context to current pointer
	glfwMakeContextCurrent(_window);
	// Initialize GLAD library
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		close_Window();
		return;
	}
}

void close_Window()
{
	glfwTerminate();
}

void error_Window()
{
	glfwSetErrorCallback([](int error, const char *description) {
		std::cout << "GLFW Error (" << std::to_string(error) << "): " << description << "\n";
	});
}

void beginframe_Window()
{
	glfwPollEvents();
}

void endframe_Window(GLFWwindow *window)
{
	glfwSwapBuffers(window);
}

} // namespace BackEnd