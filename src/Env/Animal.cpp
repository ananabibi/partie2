#include"Animal.hpp"
#include<Application.hpp>

void Animal::update(sf::Time dt){

}

void Animal::move(sf::Time dt){
    auto size = getAppConfig().world_size;

    Vec2d x = *new Vec2d(size, 0);
    Vec2d y = *new Vec2d(0, size);

    while (mPosition.x() < 0) mPosition+=x;
    while (mPosition.x() > size) mPosition-=x;

    while (mPosition.y() < 0) mPosition+=y;
    while (mPosition.y() > size) mPosition-=y;

    Vec2d v = mPosition.normalised() * getStandardMaxSpeed();

    mPosition += v*dt.asSeconds();
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
