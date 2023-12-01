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
class SolarSystem{
private:


    // Définir un itérateur interne pour SolarSystem
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = PlanetObject;
        using pointer           = PlanetObject*;
        using reference         = PlanetObject&;

        // Constructeur prenant un pointeur sur le vecteur et l'indice actuel
        Iterator(std::vector<std::unique_ptr<PlanetObject>>& vec, size_t index) : planetsVec(&vec), currentIndex(index) {}

        // Opérations d'itération
        Iterator& operator++() {
            ++currentIndex;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Opérations de comparaison
        bool operator==(const Iterator& other) const {
            return currentIndex == other.currentIndex;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        // Opérations de déréférencement
        reference operator*() const {
            return *planetsVec->at(currentIndex);
        }

        pointer operator->() const {
            return planetsVec->at(currentIndex).get();
        }

    private:
        std::vector<std::unique_ptr<PlanetObject>>* planetsVec;
        size_t currentIndex;
    };



    std::vector<std::unique_ptr<PlanetObject>> _planets;  // Planets storage

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
    const std::vector<std::unique_ptr<PlanetObject>>& getAllPlanets() const;



    ~SolarSystem(){
        _planets.clear();
    }

    // // Définir l'itérateur de début const
    // std::vector<std::unique_ptr<PlanetObject>>::const_iterator begin() const{
    //     return _planets.begin();
    // }

    // // Définir l'itérateur de fin const
    // std::vector<std::unique_ptr<PlanetObject>>::const_iterator end() const{
    //     return _planets.end();
    // }


    //Fonctions pour obtenir les itérateurs de début et de fin
    Iterator begin() {
        return Iterator(_planets, 0);
    }

    Iterator end() {
        return Iterator(_planets, _planets.size());
    }

    unsigned int nbPlanets(){
        return _planets.size();
    }



    // Surcharge de l'opérateur []
    PlanetObject& operator[](unsigned int index) {
        // Vérifier la validité de l'index
        if (index >= _planets.size()) {
            throw std::out_of_range("Index hors limites");
        }

        // Retourner la référence à l'élément à l'index spécifié
        return *_planets[index];
    }


    PlanetObject& firstElem(){
        return *_planets[0];
    }
};