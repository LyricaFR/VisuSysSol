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

class PlanetData
{
protected:
    PlanetData(float rotation, float diameter)
        : _rotationPeriod{rotation}, _diameter{diameter}
    {
    }

    virtual ~PlanetData() {}

    float _rotationPeriod;
    float _diameter;
};

class SunData : public PlanetData
{
public:
    SunData() : PlanetData(25, 10) {}
};

class EarthData : public PlanetData
{
public:
    EarthData() : PlanetData(10, 10) {}
};