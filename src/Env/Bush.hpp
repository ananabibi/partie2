#pragma once

#include "LivingEntity.hpp"


class Bush : public LivingEntity {
private:
    //Vec2d position;
    double taille;

public:
    Bush(Vec2d pos, double size);

};

