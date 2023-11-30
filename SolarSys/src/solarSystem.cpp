/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This module contains all the planets we can find  =
=  in the solar system.                              =
=  behaviour of the app.                             =
=													 =
======================================================
*/

#include "include/solarSystem.hpp"


/**
 * @brief Adds a new planet.
 * 
 * @param planet A PlanetObject (defined in the planetObject module) to add
 ********************************************************************************/
void SolarSystem::addPlanet(const PlanetObject& planet){
    _planets.emplace_back(planet);
}


/**
 * @brief Get a collection of all the planets stored.
 * 
 * @return A vector of all the PlanetObject (defined in the planetObject module)
 *         stored.
 ********************************************************************************/
const std::vector<PlanetObject> SolarSystem::getAllPlanets() const {
    return _planets;
}