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


/**
 * @brief Represents all the render engine part of the application.
 * 
 * It uses OpenGL libary.
 ********************************************************************************/
class RenderEngine
{
public:

    /**
     * @brief Constructor of the class.
     ********************************************************************************/
    RenderEngine() {}

    /**
     * @brief Clears the display of the scene.
     *
     * The current context of the rendered scene is cleared with a colored
     * background.
     ********************************************************************************/
    static void clearDisplay();

    /**
     * @brief Initialise the 3d configuration.
     * 
     * It configures the depth of the scene in OpenGL.
     ********************************************************************************/
    static void init3DConfiguration();

    /**
     * @brief Loads a texture at the given path.
     * 
     * @param path Path representation of the texture location.
     ********************************************************************************/
    static GLuint createTexture(const char *path);

    /**
     * @brief Create a Sphere object, fill the vao and vbo with
     * its data.
     * 
     * It congigures the depth of the scene in OpenGL
     ********************************************************************************/
    void createSphere();

    /**
     * @brief Configures the environment to allow the rendering.
     * 
     * Bind the textures of the planet object and the VAO.
     * 
     * @param planet A PlanetObject (defined in the planetObject module) we want
     *               to configure the drawing environment for.
     ********************************************************************************/
    void start(const PlanetObject &planet);

    /**
     * @brief Launches the rendering of the given planet.
     * 
     * @param planet A PlanetObject (defined in the planetObject module) we want
     *               to draw.
     ********************************************************************************/
    void draw(PlanetObject &planet);

    /**
     * @brief Put an end to the current rendering environment.
     * 
     * @param planet A PlanetObject (defined in the planetObject module) we want
     *               to put an end to the drawing environment for.
     ********************************************************************************/
    void end(const PlanetObject& planet);


private:

    GLuint _vbo;                    // VertexBufferObject ID
    GLuint _vao;                    // VertexArrayObject ID
    unsigned int _nbVertices = 0;   // Amount of vertices to draw
};