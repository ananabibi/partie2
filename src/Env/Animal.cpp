#include"Animal.hpp"
#include<Application.hpp>

void Animal::update(sf::Time dt) {
    if (mDelaiSoif.asSeconds() > getAppConfig().animal_thirst_delay) {
        mAssoiffe = true;
        mDelaiSoif = sf::Time::Zero;
    }

    if (mAssoiffe) { //todo reorganiser, modulariser
        eauPercue = findWater();
        if (eauPercue != nullptr) {
            double waterRadius = eauPercue->getRadius();
            bool waterReached = (LivingEntity::getPosition() - eauPercue->getPosition()).lengthSquared() < waterRadius * waterRadius;
            if (!waterReached) {
                move(computeForce(eauPercue->getCenter()), dt);
            }
            if (waterReached) {
                mAssoiffe = false;
            }
        } else {
            move(dt);
        }

    } else {
        move(dt);
    }

    mDelaiChangementDirection += dt;
    mDelaiSoif += dt;
}

enum Deceleration {
    DECEL_NULLE, DECEL_RAPIDE, DECEL_NORMALE, DECEL_LENTE
};

Vec2d Animal::computeForce(Vec2d cible) const { // todo modulariser
    Vec2d toTarget = cible - LivingEntity::getPosition();

    double speed = toTarget.length() / DECEL_LENTE;
    if (speed > getStandardMaxSpeed()) speed = getStandardMaxSpeed();

    Vec2d vTarget = toTarget.normalised() * speed;

    return vTarget - mVitesse;
}

Water *Animal::findWater() {
    return getAppEnv().findNearestWaterSource(*this);
}

void Animal::rotate() {
    double y = getNewRotation();
    mAngle += y;
    setRotation(mAngle);
}

void Animal::move(sf::Time dt) {
    sf::Time temps_entre_deux_rotations = sf::seconds(getAppConfig().animal_rotation_delay);
    if (mDelaiChangementDirection > temps_entre_deux_rotations) {
        rotate();
        mDelaiChangementDirection = sf::Time::Zero;
    }

    Vec2d v = mDirection.normalised() * getStandardMaxSpeed();
    v = getPosition() + v * dt.asSeconds();
    Obstacle::setPosition(v);
}

void Animal::move(const Vec2d &force, sf::Time dt) { // todo modulariser
    Vec2d v = mDirection.normalised() * getStandardMaxSpeed();

    Vec2d acceleration = force / getMass();
    mVitesse = v + acceleration * dt.asSeconds();
    mDirection = mVitesse.normalised();

    if (mVitesse.length() > getStandardMaxSpeed()) mVitesse = mDirection * getStandardMaxSpeed();

    setPosition(LivingEntity::getPosition() + mVitesse * dt.asSeconds());
}

double Animal::getNewRotation() {
    std::vector<double> intervals = {-180, -100, -55, -25, -10, 0, 10, 25, 55, 100, 180};
    std::vector<double> probs = {0.0000, 0.0000, 0.0005, 0.0010, 0.0050, 0.9870, 0.0050, 0.0010, 0.0005, 0.0000,
                                 0.0000};

    return piecewise_linear(intervals, probs) * DEG_TO_RAD;
}

void Animal::setRotation(double angle) {
    mDirection = {std::cos(angle), std::sin(angle)};
}

bool Animal::isPerceptible(Vec2d const &position, double offset) const {
    Vec2d d = position - getPosition();

    double squaredViewDistance = (getViewDistance() + offset) * (getViewDistance() + offset);
    bool isCloseEnough = d.lengthSquared() <= squaredViewDistance;

    double dotProduct = mDirection.dot(d.normalised());
    bool isInViewRange = dotProduct >= std::cos(getViewRange() / 2 + 0.001);

    bool samePosition = isEqual(0.0, d.lengthSquared());

    return (isCloseEnough and isInViewRange) or samePosition;
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
    mVitesse = {0, 0};
    mAssoiffe = true;
}
