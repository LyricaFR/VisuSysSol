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
#include "include/matrices.hpp"

class PlanetObject
{
public:
    PlanetObject(GLuint textureID, const PlanetData& data, EarthShader* shader) : _data{data}, _textID{textureID}, _shader{shader}
    {}

    void configureMatrices(float w, float h){
        _matrices.init(w, h);
    }

    void updateMatrices(){

        auto previousMVMatrix = _matrices.getMVMatrix();
        auto projMatrix = _matrices.getProjMatrix();
        auto MVMatrix = glm::rotate(previousMVMatrix, 0.f, glm::vec3(0, 1, 0));
        auto normalMatrix = glm::transpose(glm::inverse(MVMatrix));
        auto MVPMatrix = projMatrix * MVMatrix;

        _matrices.setMVMatrix(MVMatrix);
        _matrices.setNormalMatrix(normalMatrix);
        _matrices.setMVPMatrix(MVPMatrix);
    }

    GLuint getTextID() const{
        return _textID;
    }

    const EarthShader* getShaderManager() {
        return _shader;
    }

    const Matrices& getMatrices() const{
        return _matrices;
    }

private:
    PlanetData _data;
    GLuint _textID;
    EarthShader* _shader;
    Matrices _matrices;
    // add the satellites (later)
};