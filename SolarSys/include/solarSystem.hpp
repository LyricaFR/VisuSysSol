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

#pragma once

#include <vector>

#include "include/planetObject.hpp"


/**
 * @brief Gathers all the planets.
 * 
 * It is a PlanetObject (defined in the planetObject module) container.
 ********************************************************************************/
class SolarSystem{
public:

    /**
     * @brief Constructor of the class.
     ********************************************************************************/
    SolarSystem() {}

    /**
     * @brief Adds a new planet.
     * 
     * @param planet A PlanetObject (defined in the planetObject module) to add
     ********************************************************************************/
    void addPlanet(const PlanetObject& planet);

    /**
     * @brief Get a collection of all the planets stored.
     * 
     * @return A vector of all the PlanetObject (defined in the planetObject module)
     *         stored.
     ********************************************************************************/
    const std::vector<PlanetObject> getAllPlanets() const;

private:
    std::vector<PlanetObject> _planets;  // Planets storage
};