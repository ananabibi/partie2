#pragma once

#include <Utility/Vec2d.hpp>
#include "../../../partie2/src/Env/Genome.hpp"
#include "LivingEntity.hpp"
#include "../../../partie2/src/Env/Water.hpp"
#include <Utility/Utility.hpp>

class Animal : public LivingEntity {

public:
    void update(sf::Time dt);

    void move(sf::Time dt);
    void move(const Vec2d& force, sf::Time dt);

    double getNewRotation();

    void setRotation(double angle);


protected :
    Animal(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    Vec2d mDirection;
    Vec2d mVitesse; // todo double mVmax etait utile ?
    Genome mGenome;
    double mMasse;
    double mAngle;
    double mDistance;
    sf::Time mCompteurChangementDirection = sf::Time::Zero;
    sf::Time mCompteurDelaiSoif= sf::Time::Zero;
    Water* eauPercue;

private :

    virtual double getMass() const = 0;

    virtual double getStandardMaxSpeed() const = 0;

    void rotate();

    Water* findWater();

    Vec2d computeForce(Vec2d cible) const;

public:

    bool isPerceptible(Vec2d const& position, double offset= 0) const;

    virtual double getViewRange() const;

    virtual double getViewDistance() const;


};
