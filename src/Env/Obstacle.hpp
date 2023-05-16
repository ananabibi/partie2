/*
 *  Epidemic simulation
 *  2023
 * @authors: Anna
 *
 */
#pragma once

#include <iostream>
#include <Utility/Vec2d.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Obstacle {

public:
    Obstacle(Vec2d position, double rayon, bool traversable);

    Vec2d getCenter() const;

    double getRadius() const;

    bool isTraversable() const;

    bool isColliding(Obstacle other) const;

    bool isPointInside(Vec2d p) const;

    bool operator|(Obstacle const &b2);

    void update(sf::Time dt);

    void setPosition(Vec2d position);


        protected:
    Vec2d mPosition;
    double mRayon;
    bool mTraversable;

};

bool operator>(Obstacle body, Vec2d const &point);

