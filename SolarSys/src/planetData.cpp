/*
======================================================
=  						                             =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=						                             =
=						                             =
=  This module introduces all the data concercing    =
=  the app, we can find the information about the    =
=  solar system behaviour such as the rotation       =
=  period of the planets and more.		             =
=						                             =
======================================================
*/

#include "include/planetData.hpp"

/*================================== PLANET DATA ====================================*/

/**
 * @brief Constructor of the class.
 *
 * @param rotation A float value that describes the rotation period of the
 *                 planet.
 * @param diameter A size for the planet.
 * @param position A position value regarding the sun position.
 * @param angle A value that represents the angle regarding the ellipse.
 ********************************************************************************/
PlanetData::PlanetData(float rotation, float diameter, float position, float angle, float revPeriod)
    : _rotationPeriod{rotation}, _diameter{diameter}, _position{position}, _angle{angle}, _revolutionPeriod{revPeriod}
{
}

/*================================== SUN DATA ====================================*/

/**
 * @brief Constructor of the class.
 ********************************************************************************/
SunData::SunData() : PlanetData(3, 1, 0, 0, 0)
{
}

/*================================== EARTH DATA ====================================*/

/**
 * @brief Constructor of the class.
 ********************************************************************************/
EarthData::EarthData() : PlanetData(0.4, 0.5, 2, 0, 1)
{
}
