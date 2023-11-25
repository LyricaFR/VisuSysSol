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

#pragma once

#include <glimac/Image.hpp>

using namespace glimac;

std::unique_ptr<Image> loadImgFromPath(const char *path);