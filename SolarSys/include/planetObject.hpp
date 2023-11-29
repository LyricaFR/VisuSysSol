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

#include <vector>
#include <memory>

#include "include/planetData.hpp"
#include "include/shaderManager.hpp"
#include "include/matrices.hpp"

class PlanetObject
{
public:
    PlanetObject(GLuint textureID, const PlanetData& data, std::shared_ptr<ShaderManager> shader) : _data{data}, _shader{shader}
    {
        _textIDs.emplace_back(textureID);
    }

    PlanetObject(unsigned int nbOfTextures, GLuint * textureIDs, const PlanetData& data, std::shared_ptr<ShaderManager> shader) : _data{data}, _shader{shader}
    {
        for(unsigned int i = 0; i < nbOfTextures; i++){
            _textIDs.emplace_back(textureIDs[i]);
        }
    }

    ~PlanetObject() {}

    void configureMatrices(float w, float h){
        _matrices.init(w, h);
    }

    void updateMatrices(float rotation){

        auto previousMVMatrix = _matrices.getMVMatrix();
        auto projMatrix = _matrices.getProjMatrix();

        auto MVMatrix = glm::rotate(previousMVMatrix, rotation, glm::vec3(0, 1, 0));
        auto normalMatrix = glm::transpose(glm::inverse(MVMatrix));
        auto MVPMatrix = projMatrix * MVMatrix;

        _matrices.setMVMatrix(MVMatrix);
        _matrices.setNormalMatrix(normalMatrix);
        _matrices.setMVPMatrix(MVPMatrix);
    }

    const std::vector<GLuint> getTextIDs() const{
        return _textIDs;
    }

    std::shared_ptr<ShaderManager> getShaderManager() {
        return _shader;
    }

    const Matrices& getMatrices() const{
        return _matrices;
    }

private:
    PlanetData _data;
    std::vector<GLuint> _textIDs;
    std::shared_ptr<ShaderManager> _shader;
    Matrices _matrices;
    // add the satellites (later)
};