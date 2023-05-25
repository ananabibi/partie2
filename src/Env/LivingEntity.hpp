#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "../../../partie2/src/Env/Obstacle.hpp"

class LivingEntity : public Obstacle {

public:

    LivingEntity(Vec2d position, double rayon, bool traversable, double energie);
    virtual void drawOn(sf::RenderTarget &target) const { std::cout << "Here????" << std::endl; };
    Vec2d getPosition() const;


protected:

private :
    double mEnergie;
    sf::Time mAge;

};

