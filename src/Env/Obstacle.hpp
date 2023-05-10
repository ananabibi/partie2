/*
 *  Epidemic simulation
 *  2023
 * @authors: 
 *
 */
#pragma once

#include <Utility/Vec2d.hpp>
#include <iostream>

class Obstacle {

protected:
    Vec2d mPosition;
    double mRayon;
    bool mTraversable;

public:
    Obstacle(Vec2d position, double rayon, bool traversable);

    Vec2d getCenter() const;

    double getRadius() const;

    bool isTraversable() const;

    bool isColliding(Obstacle other) const;

    bool isPointInside(Vec2d p) const;

    bool operator|(Obstacle const &b2);
};

bool operator>(Obstacle body, Vec2d const &point);

