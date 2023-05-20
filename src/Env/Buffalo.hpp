#pragma once
#include <Env/Environment.hpp>
#include "Animal.hpp"



class Buffalo : public Animal {

public :
    Buffalo(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    explicit Buffalo(Vec2d position)
            : Animal(
            position,
            getAppConfig().buffalo_size / 2,
            false,
            getAppConfig().buffalo_energy_initial) {
        mDirection = Vec2d(1,1);
    }

    void drawOn(sf::RenderTarget &target) const;

    };
