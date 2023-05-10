#include<Application.hpp>
#include "Buffalo.hpp"

Buffalo::Buffalo(
        Vec2d position, double rayon, bool traversable,
        double energie,
        const Genome *genomeMere, const Genome *genomePere)
        : Animal(position, rayon, traversable, getAppConfig().buffalo_energy_initial) {
    mDirection = Vec2d(1, 0).normalised();
}


