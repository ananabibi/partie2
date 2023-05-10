#pragma once

#include "../../../partie1/src/Env/Obstacle.hpp"

class LivingEntity : public Obstacle {

private :
    double mEnergie;
    sf::Time mAge;

public:

    LivingEntity(Vec2d position, double rayon, bool traversable, double energie);

};

