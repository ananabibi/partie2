#pragma once

#include <Env/Environment.hpp>
#include "Animal.hpp"
#include"Animal.hpp"


class Buffalo : public Animal {

public :
    Buffalo(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    Buffalo(Vec2d position)
            : Animal(
            position,
            getAppConfig().buffalo_size / 2,
            false,
            getAppConfig().buffalo_energy_initial) {}

    void drawOn(sf::RenderTarget &target) const;

    };
