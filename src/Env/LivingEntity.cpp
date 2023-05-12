#include "LivingEntity.hpp"


//CONSTURCTEURS

LivingEntity:: LivingEntity(Vec2d position, double rayon, bool traversable, double energie)
    : Obstacle(position,rayon,traversable), mEnergie(energie), mAge(sf::Time::Zero) {

}

