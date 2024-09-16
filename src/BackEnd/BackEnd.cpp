#include "BackEnd.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>

#include "../Common.h"
#include "../GL_Shader/GL_Shader.h"

namespace BackEnd {

void Init()
{
	w_Create();
	// Build and compile our shader program
	std::string VertShader = "res/shaders/OpenGL/standard.vert";
	std::string FragShader = "res/shaders/OpenGL/standard.frag";
	Load::GL_Shader(VertShader, FragShader);
	grid();
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(_window)) {
		// Render here
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(Load::shaderProgram);
		glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT, 0);
		w_EndFrame();
		w_BeginFrame();
	}
	w_Close();
	return;
}

void w_Create()
{
	// Initialize GLFW library
	glfwInit();
	w_ErrorCall();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// GLFW window creation
	_window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (!_window) {
		w_Close();
		w_ErrorCall();
	}
	// Set window's context to current pointer
	glfwMakeContextCurrent(_window);
	// Initialize GLAD library
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		w_Close();
		return;
	}
}

void w_Close() { glfwTerminate(); }

void w_ErrorCall()
{
	glfwSetErrorCallback([](int error, const char *description) {
		std::cout << "GLFW Error (" << std::to_string(error) << "): " << description << "\n";
	});
}

void w_BeginFrame() { glfwPollEvents(); }

void w_EndFrame() { glfwSwapBuffers(_window); }

void grid()
{
	float vertices[] = {// Position
	                    -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.0f, -0.5f, 0.5f, 0.0f};

	unsigned int indices[] = {
	    0, 1, // Bottom line
	    1, 2, // Right line
	    2, 3, // Top line
	    3, 0  // Left line
	};

	// Define VAO, VBO, and EBO
	unsigned int VAO, VBO, EBO;
	// Place in OpenGL buffer
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind to buffer
	glBindVertexArray(VAO);                     // Bind VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);         // Bind VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // Bind EBO
	// Retrieve data that we bound to buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);       // VBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); // EBO
	// Set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
}

} // namespace BackEnd