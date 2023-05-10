#include "Obstacle.hpp"

// CONSTRUCTEURS :

Obstacle::Obstacle(Vec2d position, double rayon, bool traversable)
        : mPosition(position), mRayon(rayon), mTraversable(traversable) {}

// GETTERS :

Vec2d Obstacle::getCenter() const {
    return mPosition;
}

double Obstacle::getRadius() const { // todo getRayon?
    return mRayon;
}

bool Obstacle::isTraversable() const {
    return mTraversable;
}

// METHODES :


bool Obstacle::isColliding(Obstacle other) const {
    Vec2d diff(mPosition - other.getCenter());
    if (diff.length() <= (mRayon + other.getRadius())) {
        return true;
    } else {
        return false;
    }
}

bool Obstacle::isPointInside(Vec2d p) const {
    Vec2d diff(mPosition - p);
    if (diff.length() <= mRayon) {
        return true;
    } else {
        return false;
    }
}

// SURCHARGE OPERATEURS :


bool Obstacle::operator|(const Obstacle &other) {
    return this->isColliding(other);
}

bool operator>(Obstacle o, Vec2d const &p) {
    return o.isPointInside(p);
}

