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

/**
 * @brief Make a window being active.
 *
 * This means that, its allows the window to react with the possible events by the
 * user on the window for example.
 *
 * @param window A window.
 ********************************************************************************/
void manageWindow(GLFWwindow *window);

/**
 * @brief Checks if a window is still active/opened.
 *
 * @return A boolean, true if window is still open and false otherwise.
 ********************************************************************************/
int isWindowOpen(GLFWwindow *window);

/**
 * @brief Creates a window.
 *
 * @param width Width dimension of the window.
 * @param height Height dimension of the window.
 * @param title A char array that represents the title of the window.
 *
 * @return A window created otherwise its a null pointer if an error occured.
 ********************************************************************************/
GLFWwindow *createWindow(unsigned int width, unsigned int height, const char *title);
