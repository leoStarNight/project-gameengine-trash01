#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <glfw3.h>
#include <linmath.h>

#include "callback.hpp"
#include "prepare.hpp"
#include "geometry.hpp"

GLFWwindow *window;

GLuint vertex_buffer, vertex_shader, fragment_shader, program;
GLint mvp_location, vpos_location, vcol_location;

void initBuffers()
{
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
 
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
}

void initLocations()
{
    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");
 
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));
}

void process(float ratio, mat4x4 p, mat4x4 m, mat4x4 mvp)
{    
    mat4x4_identity(m);
    mat4x4_rotate_Z(m, m, (float) glfwGetTime());
    mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    mat4x4_mul(mvp, p, m);
 
    glUseProgram(program);
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void processRender()
{
    float ratio;
    int width, height;
    mat4x4 m, p, mvp;
 
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
 
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    process(ratio, p, m, mvp);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if(!prepareInit())
        return 1;    

    // Somehow to create a window
    window = glfwCreateWindow(640,480,"Duppy", nullptr, nullptr);
    if(!window) 
    {
        glfwTerminate();
        return 1;
    }
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1); 

    initBuffers();
    initLocations();

    // Handle the window
    while(!glfwWindowShouldClose(window))
    {
        processRender();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}