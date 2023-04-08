#include <glad/glad.h>
#include <glfw3.h>
#include "prepare.hpp"

int prepareInit()
{
    if (!glfwInit()) 
        return 0;

    // Hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
    return 1;
}