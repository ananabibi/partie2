#include<Application.hpp>
#include "Lion.hpp"
#include "Utility/Arc.hpp"


Lion::Lion(
        Vec2d position, double rayon, bool traversable,
        double energie,
        const Genome *genomeMere, const Genome *genomePere)
        : Animal(position, rayon, traversable, getAppConfig().buffalo_energy_initial) {
    mDirection = Vec2d(1, 0).normalised();
}

Lion::Lion(Vec2d position)
        : Animal(
        position,
        getAppConfig().lion_size / 2,
        false,
        getAppConfig().lion_energy_initial) {}


double Lion::getMass() const {
    return getAppConfig().lion_mass;
}

double Lion::getStandardMaxSpeed() const {
    return getAppConfig().lion_max_speed;
}


