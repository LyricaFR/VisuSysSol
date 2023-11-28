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

#include <glad/glad.h>
#include <glimac/Sphere.hpp>

#include "include/textures.hpp"
#include "include/tools.hpp"
#include "include/planetObject.hpp"

class RenderEngine
{
public:
    RenderEngine() {}

    void create3DSphere();

    void start(const PlanetObject &planet);

    void draw(PlanetObject &planet);

    void end(const PlanetObject& planet);

private:
    GLuint _vbo;
    GLuint _vao;
    unsigned int _nbVertices = 0;
};

/**
 * @brief Clears the display on a window.
 *
 * The current context of the rendered scene is cleared with a colored background
 ********************************************************************************/
void clearDisplay();

GLuint createTexture(const char *path);

void init3DConfiguration();