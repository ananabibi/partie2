#include"Animal.hpp"
#include<Application.hpp>

// GETTERS

double Animal::getMass() const {
    return getAppConfig().buffalo_mass;
}

double Animal::getStandardMaxSpeed() const {
    return getAppConfig().buffalo_max_speed;
}

//CONSTRUCTEURS

Animal:: Animal(
        Vec2d position,double rayon, bool traversable,
        double energie,
        const Genome *genomePere, const Genome *genomeMere)
        : LivingEntity(position,rayon,traversable,energie),
        mGenome(genomePere, genomeMere),
        mDirection(Vec2d(1, 0).normalised())  {
    mMasse = 0;
    mVmax = 0;
}
