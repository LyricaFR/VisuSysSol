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
void clearDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLuint createTexture(const char *path)
{
    auto ptrText = loadImgFromPath(path);

    if (ptrText == NULL)
    {
        return ERR_INT_CODE;
    }

    auto textID = loadTexture(std::move(ptrText));

    return textID < 0 ? ERR_INT_CODE : textID; // Check that the texture has been loaded successfully
}

void init3DConfiguration()
{
    glEnable(GL_DEPTH_TEST); // Enable the GPU to take the depth for 3D
}