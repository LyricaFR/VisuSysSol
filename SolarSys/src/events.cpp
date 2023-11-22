#include "include/events.hpp"



void onWindowResized(GLFWwindow *window, int width, int height){
    std::cout << "RESIZE : " << window << " for dimension " <<  width << " x " << height << std::endl;
}


void onMouseMotion(GLFWwindow *window, double x, double y){
    std::cout << "Mouse Motion : " << window << " for mouse position " <<  x << " , " << y << std::endl;
}


void onMouseButton(GLFWwindow *window, int code, int action, int other){
    std::cout << "Mouse Button : " << window << " of code " <<  code << " fo action " 
            << action << " and other : " << other << std::endl;
}

void setEvents(GLFWwindow *window){
    glfwSetWindowSizeCallback(window, onWindowResized);
	glfwSetCursorPosCallback(window, onMouseMotion); /* Mouse moved */
	glfwSetMouseButtonCallback(window, onMouseButton);	   /* Mouse click events */
}