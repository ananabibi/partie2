#pragma once

#include "../../../partie1/src/Env/Obstacle.hpp"
#include <Utility/Vec2d.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class Water : public Obstacle {

private:
    double taille;

public:
    Water(Vec2d p);

    void drawOn(sf::RenderTarget &target) const;

    void update(sf::Time dt);
};
