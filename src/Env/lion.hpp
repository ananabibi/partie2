#pragma once

#include "Animal.hpp"

class Lion : public Animal {

public :
    Lion (Vec2d position, double rayon, bool traversable,
          double energie,
          const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    explicit Lion(Vec2d position)
    : Animal(
            position,
            getAppConfig().lion_size/ 2,
    false,
    getAppConfig().lion_energy_initial) {
        mDirection = Vec2d(1,0);
    }
    void drawOn(sf::RenderTarget &target) const;


private :
    double getMass() const;

    double getStandardMaxSpeed() const;




    };
