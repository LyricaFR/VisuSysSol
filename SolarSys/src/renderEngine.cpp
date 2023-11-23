/*
======================================================
=  													 =
=     Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Gathers the tasks linked to the rendering.        =
=													 =
=  This module role is to be the render engine of 	 =
=  global app.										 =
=  													 =
======================================================
*/

#include "include/renderEngine.hpp"


/**
 * @brief Clears the display on a window.
 *
 * The current context of the rendered scene is cleared with a colored background
 ********************************************************************************/
void clearDisplay(){
    glClearColor(0.f, 0.f, 0.f, 0.f); // Make the background being black
    glClear(GL_COLOR_BUFFER_BIT); // Clean the previous display
}