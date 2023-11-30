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

#include "include/textures.hpp"


/**
 * @brief Loads a texture.
 * 
 * @param ptrText A pointer on an Image (defined in the glimac library).
 ********************************************************************************/
GLuint loadTexture(std::unique_ptr<Image> ptrText)
{
    // Texture Object ID
    GLuint text;

    glGenTextures(1, &text);
    glBindTexture(GL_TEXTURE_2D, text);

    // Send the image texture to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ptrText->getWidth(), ptrText->getHeight(), 0, GL_RGBA, GL_FLOAT, ptrText->getPixels());

    // FIlters OPenGL will apply when using the texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    return text;
}