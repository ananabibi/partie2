#include "LivingEntity.hpp"


Vec2d LivingEntity::getPosition() const {
    return getCenter();
}

double LivingEntity::getEnergy() const {
    return mEnergie;
}

//CONSTURCTEURS

LivingEntity:: LivingEntity(Vec2d position, double rayon, bool traversable, double energie)
    : Obstacle(position,rayon,traversable), mEnergie(energie), mAge(sf::Time::Zero) {

}


