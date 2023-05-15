#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "LivingEntity.hpp"


class Bush : public LivingEntity {

public:
    Bush(Vec2d position, double size);

    Bush(Vec2d position);

    void drawOn(sf::RenderTarget &target) ;


private:
    double taille;

};

