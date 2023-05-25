#include "Obstacle.hpp"
#include <Application.hpp>

// CONSTRUCTEURS :

Obstacle::Obstacle(Vec2d position, double rayon, bool traversable)
        : mRayon(rayon), mTraversable(traversable) {
    setPosition(position);
}

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

void Obstacle::setPosition(Vec2d position) {
    auto size = getAppConfig().world_size;
    auto x = position.x();
    if(x < 0) {
        x += size;
    } else if(x >= size) {
        x -= size;
    }
    auto y = position.y();
    if(y < 0) {
        y += size;
    } else if(y >= size) {
        y -= size;
    }
    mPosition = Vec2d(x, y);
}

// SURCHARGE OPERATEURS :

bool Obstacle::operator|(const Obstacle &other) {
    return this->isColliding(other);
}

bool operator>(Obstacle o, Vec2d const &p) {
    return o.isPointInside(p);
}

