/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Texture management. There are the functions       =
=  which allow the load, the binding, the filters..  =
=													 =
======================================================
*/

#pragma once

#include <glimac/Program.hpp>

#include "include/resources.hpp"

/**
 * @brief Loads a texture.
 * 
 * @param ptrText A pointer on an Image (defined in the glimac library).
 ********************************************************************************/
GLuint loadTexture(std::unique_ptr<Image> ptrText);
