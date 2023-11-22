#pragma once

#define GLFW_INCLUDE_NONE

#include <string>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "include/tools.hpp"


int initWindowLib();

void freeCurrentWindow();

GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);


