/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This module owns the management of a planet		 =
=  object, this means that we can find all the		 =
=  information we need to draw it            		 =
=													 =
======================================================
*/

#pragma once

#include "include/planetData.hpp"
#include "glimac/Program.hpp"

class PlanetObject
{
public:
    PlanetObject();

private:
    PlanetData _data;
    GLuint textId;
    // add the shaders (structure with the uniform values)
    // add the satellites (later)
    // add the matrices
};