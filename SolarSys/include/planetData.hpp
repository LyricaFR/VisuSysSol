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

#pragma once


/**
 * @brief Structure that represents data about a planet.
 * 
 * It stores information such as the rotation period of the planet, its size..
 ********************************************************************************/
class PlanetData
{
public:

    /**
     * @brief Destructor of the class.
     ********************************************************************************/
    virtual ~PlanetData() {}
    
protected:

    /**
     * @brief Constructor of the class.
     * 
     * @param rotation A float value that describes the rotation period of the 
     *                 planet.
     * @param diameter A size for the planet.
     ********************************************************************************/
    PlanetData(float rotation, float diameter);


    float _rotationPeriod; // Rotation period of the planet
    float _diameter;       // Size of the planet
};


/**
 * @brief Gather data about the Sun.
 * 
 * A SunData object is a kind of PlanetData.
 ********************************************************************************/
class SunData : public PlanetData
{
public:
    /**
     * @brief Constructor of the class.
     ********************************************************************************/
    SunData();
};


/**
 * @brief Gather data about the Earth.
 * 
 * A EarthData object is a kind of PlanetData.
 ********************************************************************************/
class EarthData : public PlanetData
{
public:

    /**
     * @brief Constructor of the class.
     ********************************************************************************/
    EarthData();
};