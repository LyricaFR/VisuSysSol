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

#include "include/matrices.hpp"


/**
 * @brief Initialize the matrices.
 * 
 * @param w Width used to build the projection matrix (with perspective 
 * function).
 * @param h Height used to build the projection matrix (with perspective 
 * function).
 ********************************************************************************/
void Matrices::init(float w, float h){
    _projMatrix = glm::perspective(glm::radians(70.f), w / h, 0.1f, 100.f);

    if(w == 1000){  // TODO : Remove it when the planet will be able to be located only thanks to its data
        _MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0.f, 0.f, -6.f));
    }else{
        _MVMatrix = glm::translate(glm::mat4(1), glm::vec3(-2.f, 1.f, -5.f));
    }
    
    _normalMatrix = glm::transpose(glm::inverse(_MVMatrix));
    _MVPMatrix = _projMatrix * _MVMatrix;
}


/**
 * @brief Retrieves the Projection ModelView matrix.
 * 
 * @return A view of the 4x4 matrix that represents the Projection ModelView 
 * matrix.
 ********************************************************************************/
const glm::mat4 Matrices::getMVPMatrix() const{
    return _MVPMatrix;
}

/**
 * @brief Retrieves the ModelView matrix.
 * 
 * @return A view of the 4x4 matrix that represents the ModelView matrix.
 ********************************************************************************/
const glm::mat4 Matrices::getMVMatrix() const{
    return _MVMatrix;
}

/**
 * @brief Retrieves the Normal matrix.
 * 
 * @return A view of the 4x4 matrix that represents the Normal matrix.
 ********************************************************************************/
const glm::mat4 Matrices::getNormalMatrix() const{
    return _normalMatrix;
}

/**
 * @brief Retrieves the Projection matrix.
 * 
 * @return A view of the 4x4 matrix that represents the Projection matrix.
 ********************************************************************************/
const glm::mat4 Matrices::getProjMatrix() const{
    return _projMatrix;
}


/**
 * @brief Set a new value to the Projection ModelView matrix.
 * 
 * @param newMatrix A 4x4 (glm::mat4 provided by the glm library) matrix.
 ********************************************************************************/
void Matrices::setMVPMatrix(glm::mat4 newMatrix) {
    _MVPMatrix = newMatrix;
}

/**
 * @brief Set a new value to the ModelView matrix.
 * 
 * @param newMatrix A 4x4 (glm::mat4 provided by the glm library) matrix.
 ********************************************************************************/
void Matrices::setMVMatrix(glm::mat4 newMatrix) {
    _MVMatrix = newMatrix;
}

/**
 * @brief Set a new value to the Normaal matrix.
 * 
 * @param newMatrix A 4x4 (glm::mat4 provided by the glm library) matrix.
 ********************************************************************************/
void Matrices::setNormalMatrix(glm::mat4 newMatrix) {
    _normalMatrix = newMatrix;
}