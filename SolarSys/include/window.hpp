/*
======================================================
=  													 =
=     Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Window management module.                         =
=  													 =
======================================================
*/

#pragma once

#define GLFW_INCLUDE_NONE

#include <string>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "include/tools.hpp"



/**
 * @brief Initializes the library for the window management.
 *
 * @return A code error telling if the initialization is successfull or not.
 ********************************************************************************/
int initWindowLib();


/**
 * @brief Frees properly the current window.
 ********************************************************************************/
void freeCurrentWindow();


void manageWindow(GLFWwindow *window);

/**
 * @brief Checks if a window is still active/opened.
 *
 * @return A boolean, true if window is still open and false otherwise.
 ********************************************************************************/
int isWindowOpen(GLFWwindow *window);

GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);


