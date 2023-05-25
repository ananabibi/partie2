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

    virtual Vec2d getCenter() const;

    virtual double getRadius() const;

    bool isTraversable() const;

    bool isColliding(Obstacle other) const;

    bool isPointInside(Vec2d p) const;

    bool operator|(Obstacle const &b2);

    virtual void update(sf::Time dt) {}

    void setPosition(Vec2d position);

    void move(Vec2d vector);

    Vec2d getPosition() const { return mPosition; };

protected:
    double mRayon;
    bool mTraversable;

private:
    Vec2d mPosition;
};

bool operator>(Obstacle body, Vec2d const &point);

