/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This is the core engine module, it is the         =
=  gathering of the whole system that manages the    =
=  behaviour of the app.                             =
=													 =
=  We can find the main loop that manages the        =
=  simulation.										 =
=													 =
======================================================
*/

#include "include/coreEngine.hpp"



/**
 * @brief Renders the whole 3D simulation
 *
 * Launches the main loop that allows the program to run the 3D simulation.
 * It manages the computations of trasnformations, the window management, 
 * and the rendering of a 3D environment.
 *
 * @return The code error of the core engine part.
 * 
 ********************************************************************************/
int render3DScene(){

    if(!Window::initWindowLib()){
        return ERR_INT_CODE;
    }
    
    auto window = Window(1000, 1000, "App");

    if(!window.isCreated()){
        return ERR_INT_CODE;
    }

    window.configureEvents();

    while (window.isWindowOpen()){

        clearDisplay();

        // Rendering There

        window.manageWindow();  // Make the window active (events) and swap the buffers
    }

    Window::freeCurrentWindow();
    
    return SUCCESS_INT_CODE;
}