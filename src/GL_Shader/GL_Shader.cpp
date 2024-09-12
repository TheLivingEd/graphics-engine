#include "GL_Shader.h"
#include "../Utility/Utility.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


namespace Load {
    unsigned int shaderProgram = 0;
    void GL_Shader(std::string VertexPath, std::string FragmentPath) {
        std::string vertexShaderSource = Utility::FileText(VertexPath);             // Build VertexShader
        const char* vShaderCode = vertexShaderSource.c_str();

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vShaderCode, NULL);
        glCompileShader(vertexShader);

        int success;                                                                // Check for compile errors
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        std::string fragmentShaderSource = Utility::FileText(FragmentPath);         // Build FragmentShader
        const char* fShaderCode = fragmentShaderSource.c_str();

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
        glCompileShader(fragmentShader);

       glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);                  // Check for compile errors
       if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
                                                          
        unsigned int program = glCreateProgram();                                   // Create the program
        glAttachShader(program, vertexShader);                                      // VertexShader Link
        glAttachShader(program, fragmentShader);                                    // FragmentShader Link
        glLinkProgram(program);                                                     // Link the program
        glGetProgramiv(program, GL_LINK_STATUS, &success);                          // check for linking errors
        if (!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        shaderProgram = program;
        glDeleteShader(vertexShader);                                               // Delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(fragmentShader);                                             // Delete the shaders as they're linked into our program now and no longer necessery
    }
}