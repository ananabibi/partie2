#pragma once

#include <Env/Environment.hpp>
#include "Animal.hpp"
#include"Animal.hpp"


class Buffalo : public Animal {

 // Buffalo(Vec2d p, double energie = getAppConfig().buffalo_energy_initial, const Genome *genomeMere = nullptr,
 //          const Genome *genomePere = nullptr);

    //genome est nul quand on crée l'environnement...
public :
    Buffalo(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    Buffalo (Vec2d position)
    : Animal(position,getAppConfig().buffalo_size/2,false, getAppConfig().buffalo_energy_initial)
    {}




};
