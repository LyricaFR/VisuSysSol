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

class SolarSystem{
public:
    SolarSystem()
    {}

    void addPlanet(const PlanetObject& planet){
        _planets.emplace_back(planet);
    }

    const std::vector<PlanetObject> getAllPlanets() const {
        return _planets;
    }


private:
    std::vector<PlanetObject> _planets;
};