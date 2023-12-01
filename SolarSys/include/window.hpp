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
#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "include/tools.hpp"
#include "include/events.hpp"

/**
 * @brief Representation of a window where we can render the 3D scene.
 *
 * This one is using GLFW library.
 ********************************************************************************/
class Window
{

public:
    /**
     * @brief Creates a window.
     *
     * @param width Width dimension of the window.
     * @param height Height dimension of the window.
     * @param title A char array that represents the title of the window.
     *
     * @return A window created otherwise its a null pointer if an error occured.
     ********************************************************************************/
    Window(unsigned int width, unsigned int height, const char *title);

    /**
     * @brief Initializes the library for the window management.
     *
     * @warning This must be called before the creation of the window
     *
     * @return A code error telling if the initialization is successfull or not.
     ********************************************************************************/
    static int initWindowLib();

    /**
     * @brief Frees properly the current window.
     ********************************************************************************/
    /*static*/ void freeCurrentWindow();

    /**
     * @brief Make a window being active.
     *
     * This means that, its allows the window to react with the possible events by the
     * user on the window for example.
     *
     * @param window A window.
     ********************************************************************************/
    void manageWindow();

    /**
     * @brief Checks if a window is still active/opened.
     *
     * @return A boolean, true if window is still open and false otherwise.
     ********************************************************************************/
    bool isWindowOpen();

    /**
     * @brief Sets the events for the window.
     ********************************************************************************/
    void configureEvents();

    /**
     * @brief Gives the creation state of the window.
     ********************************************************************************/
    int isCreated();

    ~Window(){
        if(_window != NULL){
            free(_window);
            _window = NULL;
        }
    }

private:
    /**
     * @brief Displays the error that occured on the window.
     *
     * @param code Code error.
     * @param desc A description of the error.
     ********************************************************************************/
    static void onError(int code, const char *desc);

    GLFWwindow *_window = NULL; // Pointer on a GLFW window
    bool _state = false;        // True if the window is open and false otherwise
};