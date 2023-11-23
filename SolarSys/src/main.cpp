/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This is the input of the app, it calls the core   =
=  engine which launches the 3D simulation           =
=                                                    =
=													 =
======================================================
*/


#include "include/coreEngine.hpp"


int main(void)
{   
    if(render3DScene()){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
