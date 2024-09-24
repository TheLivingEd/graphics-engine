#include "Object.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Object
{
	bool is3Dmodel;
	float *vertices;
	unsigned int *indices;
	int vertices_size;
	int indices_size;
	int vertex_attribute;
	std::string shader_vert;
	std::string shader_frag;
};

void create_Object(Object name)
{
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
	glBufferData(GL_ARRAY_BUFFER, name.vertices_size, name.vertices, GL_STATIC_DRAW);       // VBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, name.indices_size, name.indices, GL_STATIC_DRAW); // EBO
	// Set our vertex attributes pointers
	glVertexAttribPointer(0, name.vertex_attribute, GL_FLOAT, GL_FALSE, name.vertex_attribute * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
}