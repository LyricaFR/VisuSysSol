/*
======================================================
=  													 =
=     Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Window management module.                         =
=  													 =
======================================================
*/

#include "include/window.hpp"

#include <iostream>

/**
 * @brief Displays the error that occured on the window.
 *
 * @param code Code error.
 * @param desc A description of the error.
 ********************************************************************************/
void onError(int code, const char *desc)
{
    std::cerr << "Code : " << code << std::endl
              << desc << std::endl;
}

/**
 * @brief Initializes the library for the window management.
 *
 * @return A code error telling if the initialization is successfull or not.
 ********************************************************************************/
int initWindowLib()
{
    if (!glfwInit())
    {
        return ERR_INT_CODE;
    }
    return SUCCESS_INT_CODE;
}

/**
 * @brief Frees properly the current window.
 ********************************************************************************/
void freeCurrentWindow()
{
    glfwTerminate();
}

/**
 * @brief Checks if a window is still active/opened.
 *
 * @return A boolean, true if window is still open and false otherwise.
 ********************************************************************************/
int isWindowOpen(GLFWwindow *window)
{
    if (glfwWindowShouldClose(window))
    { // Close flag is true
        return false;
    }
    return true;
}

/**
 * @brief Make a window being active.
 *
 * This means that, its allows the window to react with the possible events by the
 * user on the window for example.
 *
 * @param window A window.
 ********************************************************************************/
void manageWindow(GLFWwindow *window)
{
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    // Check the possible events that occured
    glfwPollEvents();
}

/**
 * @brief Creates a window.
 *
 * @param width Width dimension of the window.
 * @param height Height dimension of the window.
 * @param title A char array that represents the title of the window.
 *
 * @return A window created otherwise its a null pointer if an error occured.
 ********************************************************************************/
GLFWwindow *createWindow(unsigned int width, unsigned int height, const char *title)
{

    /* Create a window and its OpenGL context */
#ifdef __APPLE__
    /* We need to explicitly ask for a 3.3 context on Mac */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    // Useful to get errors in the window management
    glfwSetErrorCallback(onError);

    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // Couldn't be created properly
    if (!window)
    {
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Intialize glad (loads the OpenGL functions) */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return nullptr;
    }
    return window;
}
