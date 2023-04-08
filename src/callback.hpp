#pragma once
#include <glad/glad.h>
#include <glfw3.h>

void error_callback(GLint error, const GLchar* desc);

void key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods);