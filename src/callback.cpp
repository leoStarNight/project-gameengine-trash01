#include <stdio.h>
#include "callback.hpp"

void error_callback(GLint error, const GLchar* desc)
{
    printf("GLFW Error:\n Code: %s \n Desc: %s \n", error, desc);
}

void key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods)
{
    if (key == GLFW_KEY_ESCAPE &&
        action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
