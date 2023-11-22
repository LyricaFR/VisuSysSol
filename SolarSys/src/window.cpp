#include "include/window.hpp"

#include <iostream>

void onError(int code, const char* desc){
    std::cout << "Code : "<< code << std::endl
              << desc  << std::endl;
}


int initWindowLib(){
    if(!glfwInit()){
        return ERR_INT_CODE;
    }
    return SUCCESS_INT_CODE;
}


void freeCurrentWindow(){
    glfwTerminate();
}



GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title){

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

    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // Couldn't be created properly
    if (!window) {
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Intialize glad (loads the OpenGL functions) */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return nullptr;
    }
    return window;
}


