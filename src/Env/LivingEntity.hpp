#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "../../../partie2/src/Env/Obstacle.hpp"

class LivingEntity : public Obstacle {

private :
    double mEnergie;
    sf::Time mAge;

public:

    LivingEntity(Vec2d position, double rayon, bool traversable, double energie);

    virtual void drawOn(sf::RenderTarget &target) {
        std::cout << "Should never be called" << std::endl;
    };
};

