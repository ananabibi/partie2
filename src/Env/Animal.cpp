#include"Animal.hpp"
#include<Application.hpp>

void Animal::update(sf::Time dt) {
    move(dt);
}

void Animal::move(sf::Time dt) {

    double y = getNewRotation();
    mAngle +=y;

    Vec2d v = getPosition().normalised() * getStandardMaxSpeed();
    v = getPosition() + v * dt.asSeconds();
    Obstacle :: move(v);
    //    setPosition(getPosition() + v * dt.asSeconds());



}

double Animal :: getNewRotation() {
    std :: vector <double> intervals = { -180, -100, -55, -25, -10, 0, 10, 25, 55, 100, 180};
    std :: vector <double> probs = {0.0000,0.0000,0.0005,0.0010,0.0050,0.9870,0.0050,0.0010,0.0005,0.0000,0.0000};

    return piecewise_linear(intervals, probs) * DEG_TO_RAD;

}


// GETTERS


double Animal::getViewRange() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_view_range;
}

double Animal::getViewDistance() const { // TODO mettre dans buffalo?
    return getAppConfig().buffalo_view_distance;
}

//CONSTRUCTEURS

Animal::Animal(
        Vec2d position, double rayon, bool traversable,
        double energie,
        const Genome *genomePere, const Genome *genomeMere)
        : LivingEntity(position, rayon, traversable, energie),
          mGenome(genomePere, genomeMere),
          mDirection(Vec2d(1, 0).normalised()) {
    mMasse = 0;
    mVmax = 0;
}
