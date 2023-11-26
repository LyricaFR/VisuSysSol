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

GLuint loadTexture(std::unique_ptr<Image> ptrText);
