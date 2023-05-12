#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "LivingEntity.hpp"


class Bush : public LivingEntity {
private:
    //Vec2d position;
    double taille;

public:
    Bush(Vec2d position, double size);

    Bush(Vec2d position);

    void drawOn(sf::RenderTarget &target) override;

};

