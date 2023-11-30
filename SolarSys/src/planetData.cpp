/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This module introduces all the data concercing    =
=  the app, we can find the information about the    =
=  solar system behaviour such as the rotation       =
=  period of the planets and more.					 =
=													 =
======================================================
*/

#include "include/planetData.hpp"



/*========================== PLANET DATA ==========================*/


/**
 * @brief Constructor of the class.
 * 
 * @param rotation A float value that describes the rotation period of the 
 *                 planet.
 * @param diameter A size for the planet.
 ********************************************************************************/
PlanetData::PlanetData(float rotation, float diameter)
        : _rotationPeriod{rotation}, _diameter{diameter} 
{
}


/*========================== SUN DATA ==========================*/

/**
 * @brief Constructor of the class.
 ********************************************************************************/
SunData::SunData() : PlanetData(25, 10)
{
}


/*========================== EARTH DATA ==========================*/

/**
 * @brief Constructor of the class.
 ********************************************************************************/
EarthData::EarthData() : PlanetData(25, 10)
{
}
