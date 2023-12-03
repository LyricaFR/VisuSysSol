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
void SolarSystem::addPlanet(std::unique_ptr<PlanetObject> planet)
{
    _planets.emplace_back(std::move(planet));
}

/**
 * @brief Get a collection of all the planets stored.
 *
 * @return A vector of all the PlanetObject (defined in the planetObject module)
 *         stored.
 ********************************************************************************/
const std::vector<std::unique_ptr<PlanetObject>> &SolarSystem::getAllPlanets() const
{
    return _planets;
}

/**
 * @brief Retrieves the amount of planets stored.
 *
 * @return The number of planets.
 ********************************************************************************/
unsigned int SolarSystem::nbPlanets()
{
    return _planets.size();
}

/**
 * @brief Retrieves the planet ath the given.
 *
 * Returns the index th planet stored.
 *
 * @param index An integer describing the index which must belong to the
 * [0, size - 1] interval.
 *
 * @return The number of planets.
 ********************************************************************************/
PlanetObject &SolarSystem::operator[](unsigned int index)
{
    // Vérifier la validité de l'index
    if (index >= _planets.size())
    {
        throw std::out_of_range("Index out of bounds");
    }

    return *_planets[index];
}

/**
 * @brief Destructor of the class.
 ********************************************************************************/
SolarSystem::~SolarSystem()
{
    _planets.clear(); // When the solar system is deleted, we want all the planets to be
}

/**
 * @brief Returns the first planet.
 *
 * @return A pointer on the first planet.
 ********************************************************************************/
SolarSystem::Iterator SolarSystem::begin()
{
    return Iterator(_planets, 0);
}

/**
 * @brief Returns the end value of the iterator.
 *
 * @return A pointer on the first location that'll generate an error.
 ********************************************************************************/
SolarSystem::Iterator SolarSystem::end()
{
    return Iterator(_planets, _planets.size());
}

/* ============================================== ITERATOR =============================================== */

/**
 * @brief Constructor of the class.
 ********************************************************************************/
SolarSystem::Iterator::Iterator(std::vector<std::unique_ptr<PlanetObject>> &vec, size_t index)
    : planetsVec(&vec), currentIndex(index)
{
}

/**
 * @brief Moves the pointer of the iterator on the next element
 * (after expression).
 ********************************************************************************/
SolarSystem::Iterator &SolarSystem::Iterator::operator++()
{
    ++currentIndex;
    return *this;
}

/**
 * @brief Moves the pointer of the iterator on the next element
 * (befor expression).
 ********************************************************************************/
SolarSystem::Iterator SolarSystem::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief Comparison operator.
 *
 * Two iterators are equals if they points at the same index.
 *
 * @param other An iterator.
 *
 * @return True if the iterators are equals and False otherwise.
 ********************************************************************************/
bool SolarSystem::Iterator::operator==(const Iterator &other) const
{
    return currentIndex == other.currentIndex;
}

/**
 * @brief Comparison operator (unequality).
 *
 * @param other An iterator.
 *
 * @return True if the iterators aren't equals and False otherwise.
 ********************************************************************************/
bool SolarSystem::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

/**
 * @brief Dereferencing operator.
 *
 * @return The object stored in the pointer.
 ********************************************************************************/
SolarSystem::Iterator::reference SolarSystem::Iterator::operator*() const
{
    return *planetsVec->at(currentIndex);
}

/**
 * @brief Arrow operator.
 *
 * @return The pointer that stores the object.
 ********************************************************************************/
SolarSystem::Iterator::pointer SolarSystem::Iterator::operator->() const
{
    return planetsVec->at(currentIndex).get();
}
