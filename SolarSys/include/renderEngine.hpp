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


#pragma once

#include <glad/glad.h>    // GLCleanColor/GLClear


/**
 * @brief Clears the display on a window.
 *
 * The current context of the rendered scene is cleared with a colored background
 ********************************************************************************/
void clearDisplay();