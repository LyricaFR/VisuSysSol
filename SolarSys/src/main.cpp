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

int main(int argc, char *argv[])
{
    argc++; // Avoid the compilation flag of warning becoming errors
    if (render3DScene(argv[0]))
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
