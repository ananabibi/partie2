#pragma once

#include "Animal.hpp"

class Lion : public Animal {

public :
    Lion(Vec2d position);
    Lion (Vec2d position, double rayon, bool traversable, double energie, const Genome *genomeMere, const Genome *genomePere);


};
