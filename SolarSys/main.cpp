#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

// Includes to get files for the shaders
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>

// Allows to use the Math library
#include <glimac/glm.hpp>

// Vectors
#include <vector>

using namespace glimac;


int ex2_triangle_couleurs(char** argv)
{
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a window and its OpenGL context */
#ifdef __APPLE__
    /* We need to explicitly ask for a 3.3 context on Mac */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Intialize glad (loads the OpenGL functions) */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    /* MY CODE - START */
    /********************* SHADERS IMPORT ********************/

    // Load shaders, compile them, indicate to OpenGL to use them

    std::cout << argv[0] << std::endl;
    FilePath applicationPath(argv[0]);
    Program  program = loadProgram(applicationPath.dirPath() + "SolarSys/shaders/triangle.vs.glsl",
                                   applicationPath.dirPath() + "SolarSys/shaders/triangle.fs.glsl");
    program.use();

    /********************* INITIALIZATION ********************/

    GLuint vbo;

    // Generates buffer of the VBO and binds it
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Push the Data on the GPU
    GLfloat vertices[] = {
        -0.5f, -0.5f, 1.f, 0.f, 0.f, // premier sommet
        0.5f, -0.5f, 0.f, 1.f, 0.f,  // deuxième sommet
        0.0f, 0.5f, 0.f, 0.f, 1.f    // troisième sommet
    };
    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Unbind due to we need a static draw (we won't modify the data in the buffer in the future)
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind thanks to the Buffer ID 0

    // VAO generation
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Vertex Attributes
    const GLuint VERTEX_ATTR_POSITION = 3;
    const GLuint F_ATTR_COLOR         = 8;           // Saw this in the shader file
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION); // Index 0 : Position attribute
    glEnableVertexAttribArray(F_ATTR_COLOR);         // Color attribute

    // Set the information for GPU of how to read the vertex array
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);                            // Position
    glVertexAttribPointer(F_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (const GLvoid*)(2 * sizeof(GLfloat))); // Color
    glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                      // Unbind thanks to the Buffer ID 0

    // Unbind the VAO to not modify again
    glBindVertexArray(0);
    /* MY CODE - END */

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        
        glClearColor(0.f, 0.f, 0.f, 0.f);

        // Clean the previous display
        glClear(GL_COLOR_BUFFER_BIT);

        // Bind the VAO to draw its data
        glBindVertexArray(vao);

        // Draw the VAO data
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Unbind the VAO
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    // Free the resources
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    glfwTerminate();

    return EXIT_SUCCESS;
}


int main(int argc, char* argv[])
{
    argc++;
    
    ex2_triangle_couleurs(argv);

    return 1;
}
