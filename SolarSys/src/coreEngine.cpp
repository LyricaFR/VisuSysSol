#include "include/coreEngine.hpp"


int render3DScene(){

    GLFWwindow * window;

    if(!initWindowLib()){
        return ERR_INT_CODE;
    }

    if (!(window = createWindow(500, 500, "App"))){
        return ERR_INT_CODE;
    }

    setEvents(window);

    while (!glfwWindowShouldClose(window)){

        // Make the background being black
        glClearColor(0.f, 0.f, 0.f, 0.f);

        // Clean the previous display
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        // Check the possible events that occured
        glfwPollEvents();
    }

    freeCurrentWindow();
    
    return 0;
}