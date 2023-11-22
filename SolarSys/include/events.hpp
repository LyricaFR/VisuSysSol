#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

// Includes to get files for the shaders
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>

// Allows to use the Math library
#include <glimac/glm.hpp>


using namespace glimac;


int ex2_triangle_couleurs(char** argv);