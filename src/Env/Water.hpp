#pragma once

#include "../../../partie2/src/Env/Obstacle.hpp"
#include <Utility/Vec2d.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class Water : public Obstacle {

public:
    Water(Vec2d position);
    void drawOn(sf::RenderTarget &target) const override;
    void update(sf::Time dt);


private:
    double taille;

};
