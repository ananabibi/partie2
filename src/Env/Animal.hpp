#pragma once

#include<Utility/Vec2d.hpp>
#include"../../../partie2/src/Env/Genome.hpp"
#include"LivingEntity.hpp"

class Animal : public LivingEntity {
public:
    Vec2d mDirection;
    Genome mGenome;
    double mMasse;
    double mVmax;

protected :
    //CONSTRUCTEURS

    Animal(
            Vec2d position, double rayon, bool traversable,
            double energie,
            const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr);



private :

    //GETTERS

    double getMass() const;

    double getStandardMaxSpeed() const;



};
