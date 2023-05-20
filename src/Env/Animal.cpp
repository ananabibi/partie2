#include"Animal.hpp"
#include<Application.hpp>

void Animal::update(sf::Time dt) {
    move(dt);
}

void Animal::move(sf::Time dt) {

    Vec2d v = getPosition().normalised() * getStandardMaxSpeed();

    setPosition(getPosition() + v * dt.asSeconds());
}

// GETTERS

double Animal::getMass() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_mass;
}

double Animal::getStandardMaxSpeed() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_max_speed;
}

double Animal::getViewRange() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_view_range;
}

double Animal::getViewDistance() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_view_distance;
}

//CONSTRUCTEURS

Animal::Animal(
        Vec2d position, double rayon, bool traversable,
        double energie,
        const Genome *genomePere, const Genome *genomeMere)
        : LivingEntity(position, rayon, traversable, energie),
          mGenome(genomePere, genomeMere),
          mDirection(Vec2d(1, 0).normalised()) {
    mMasse = 0;
    mVmax = 0;
}
