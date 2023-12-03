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
#include <iterator>

#include "include/planetObject.hpp"

/**
 * @brief Gathers all the planets.
 *
 * It is a PlanetObject (defined in the planetObject module) container.
 ********************************************************************************/
class SolarSystem
{
private:
    /**
     * @brief Iterator class used to iterate over the planets stored in
     * the solar system.
     ********************************************************************************/
    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag; // Want it to be forward to allow read and write operations
        using difference_type = std::ptrdiff_t;
        using value_type = PlanetObject;
        using pointer = PlanetObject *;
        using reference = PlanetObject &;

        /**
         * @brief Constructor of the class.
         ********************************************************************************/
        Iterator(std::vector<std::unique_ptr<PlanetObject>> &vec, size_t index);

        /**
         * @brief Moves the pointer of the iterator on the next element (after expression).
         ********************************************************************************/
        Iterator &operator++();

        /**
         * @brief Moves the pointer of the iterator on the next element (befor expression).
         ********************************************************************************/
        Iterator operator++(int);

        /**
         * @brief Comparison operator (equality).
         *
         * Two iterators are equals if they points at the same index.
         *
         * @param other An iterator.
         *
         * @return True if the iterators are equals and False otherwise.
         ********************************************************************************/
        bool operator==(const Iterator &other) const;

        /**
         * @brief Comparison operator (unequality).
         *
         * @param other An iterator.
         *
         * @return True if the iterators aren't equals and False otherwise.
         ********************************************************************************/
        bool operator!=(const Iterator &other) const;

        /**
         * @brief Dereferencing operator.
         *
         * @return The object stored in the pointer.
         ********************************************************************************/
        reference operator*() const;

        /**
         * @brief Arrow operator.
         *
         * @return The pointer that stores the object.
         ********************************************************************************/
        pointer operator->() const;

    private:
        std::vector<std::unique_ptr<PlanetObject>> *planetsVec; // Storage of the Planets in the iterator context
        size_t currentIndex;                                    // Value of the current index pointed by the iterator
    };

    std::vector<std::unique_ptr<PlanetObject>> _planets; // Planets storage (in SolarSystem)

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
    void addPlanet(std::unique_ptr<PlanetObject> planet);

    /**
     * @brief Get a collection of all the planets stored.
     *
     * @return A vector of all the PlanetObject (defined in the planetObject module)
     *         stored.
     ********************************************************************************/
    const std::vector<std::unique_ptr<PlanetObject>> &getAllPlanets() const;

    /**
     * @brief Destructor of the class.
     ********************************************************************************/
    ~SolarSystem();

    /**
     * @brief Returns the first planet.
     *
     * @return A pointer on the first planet.
     ********************************************************************************/
    Iterator begin();

    /**
     * @brief Returns the end value of the iterator.
     *
     * @return A pointer on the first location that'll generate an error.
     ********************************************************************************/
    Iterator end();

    /**
     * @brief Retrieves the amount of planets stored.
     *
     * @return The number of planets.
     ********************************************************************************/
    unsigned int nbPlanets();

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
    PlanetObject &operator[](unsigned int index);
};