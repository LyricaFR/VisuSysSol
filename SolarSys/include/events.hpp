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


#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <iostream>


/**
 * @brief Sets all the events the user is allowed to interact with.
 *
 * Sets all the kind of interactions the user is allowed to have with its window
 * for instance the ones with the keys, its mouse... Moreover the behaviour of
 * the app binded to each interaction are also configured there
 * 
 * @param window A window to bind the events with.
 ********************************************************************************/
void setEvents(GLFWwindow *window);