#pragma once

#include<Utility/Vec2d.hpp>
#include"../../../partie2/src/Env/Genome.hpp"
#include"LivingEntity.hpp"

class Animal : public LivingEntity {

public:
    void update(sf::Time dt);
    void move(sf::Time dt);

protected :
    Animal(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);

    Vec2d mDirection;
    Genome mGenome;
    double mMasse;
    double mVmax;
    double mAngle;
    double mDistance;


private :
    double getMass() const;

    double getStandardMaxSpeed() const;

    double getViewRange() const;

    double getViewDistance() const;
};
