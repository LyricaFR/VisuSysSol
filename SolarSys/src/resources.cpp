/*
======================================================
=  													 =
=     Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  Module that manages the resources (files load     =
=  etc)                                      	     =
=  													 =
======================================================
*/

#include "include/resources.hpp"

std::unique_ptr<Image> loadImgFromPath(const char *path)
{
    return loadImage(path);
}
