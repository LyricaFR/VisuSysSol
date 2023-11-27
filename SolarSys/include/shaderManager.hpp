/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This module introduces the structure used to      =
=  manage the shaders and the uniform values         =
=  easily.                                           =
=													 =
======================================================
*/

#pragma once

#include <glimac/Program.hpp>


using namespace glimac;


class ShaderManager{
protected:
    ShaderManager(){}
public:
    virtual ~ShaderManager(){}
};


// Shader structure for single texture
struct Shader1Texture : public ShaderManager
{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uSunTexture;

    Shader1Texture(const FilePath &applicationPath) : m_Program(loadProgram(applicationPath.dirPath() + "SolarSys/shaders/3D.vs.glsl",
                                                                     applicationPath.dirPath() + "SolarSys/shaders/3D.fs.glsl"))
    {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");

        uSunTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};

