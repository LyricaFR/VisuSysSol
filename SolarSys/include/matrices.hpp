/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This module gathers all the functions about       =
=  matrices used in 3D rendering.                    =
=													 =
======================================================
*/

#pragma once

#include <glimac/glm.hpp>

class Matrices
{
public:
    Matrices(){}

    void init(float w, float h){
        _projMatrix = glm::perspective(glm::radians(70.f), w / h, 0.1f, 100.f);
        _MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0.f, 0.f, -5.f));
        _normalMatrix = glm::transpose(glm::inverse(_MVMatrix));
        _MVPMatrix = _projMatrix * _MVMatrix;
    }

    const glm::mat4 getMVPMatrix() const{
        return _MVPMatrix;
    }

    const glm::mat4 getMVMatrix() const{
        return _MVMatrix;
    }

    const glm::mat4 getNormalMatrix() const{
        return _normalMatrix;
    }

    const glm::mat4 getProjMatrix() const{
        return _projMatrix;
    }


    void setMVPMatrix(glm::mat4 newMatrix) {
        _MVPMatrix = newMatrix;
    }

    void setMVMatrix(glm::mat4 newMatrix) {
        _MVMatrix = newMatrix;
    }

    void setNormalMatrix(glm::mat4 newMatrix) {
        _normalMatrix = newMatrix;
    }



private:
    glm::mat4 _projMatrix;
    glm::mat4 _MVMatrix;
    glm::mat4 _normalMatrix;
    glm::mat4 _MVPMatrix;
};