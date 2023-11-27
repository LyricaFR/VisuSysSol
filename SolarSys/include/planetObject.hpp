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
#include "include/shaderManager.hpp"

class PlanetObject
{
public:
    PlanetObject(const PlanetData& data, const ShaderManager& shader) : _data{data}, _shader{shader}
    {}

private:
    PlanetData _data;
    GLuint _textId;
    ShaderManager _shader;
    // add the satellites (later)
    // add the matrices
};