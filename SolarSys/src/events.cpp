/*
======================================================
=  													 =
=     Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Place where we can find the system of events.     =
=													 =
=  There are the all the interactions the user can   =
=  have with the window such as the keys of its		 =
=  keyboard, its mouse (keys, motion), the window	 =
=  events (resize..)								 =
=													 =
======================================================
*/


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


void onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "Key Event : " << window << " for key " << key << " of scancode " << scancode 
                                << ". Made the action : " << action << " and mods are " << mods << std::endl;
}


/**
 * @brief Sets all the events the user is allowed to interact with.
 *
 * Sets all the kind of interactions the user is allowed to have with its window
 * for instance the ones with the keys, its mouse... Moreover the behaviour of
 * the app binded to each interaction are also configured there
 * 
 * @param window A window to bind the events with.
 ********************************************************************************/
void setEvents(GLFWwindow *window){
    glfwSetWindowSizeCallback(window, onWindowResized);
	glfwSetCursorPosCallback(window, onMouseMotion); /* Mouse moved */
	glfwSetMouseButtonCallback(window, onMouseButton);	   /* Mouse click */
    glfwSetKeyCallback(window, onKey);   /* Key events */
}