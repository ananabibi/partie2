/*
 * prjsv 2023
 * @authors: 
 */


#pragma once

#include <list>
#include<SFML/Graphics.hpp>
#include <Utility/Vec2d.hpp>
#include "Water.hpp"
#include "LivingEntity.hpp"
//#include <Application.hpp>


class LivingEntity;

class Animal;

class Water;


class Environment {
private:
    double temperature;
    std::list<LivingEntity *> etres;
    std::list<Water *> plans;
public:
    bool isEntityColliding(LivingEntity e);

    bool isWaterPlaceable(Water w);

//    bool isPlaceable(Obstacle* other);
    Environment(Environment const &autre) = delete;

    void addEntity(LivingEntity *e);

    void addWaterSource(Water *w);

    void update(sf::Time dt);

    void drawOn(sf::RenderTarget &targetWindow) const;

    void reset();

    Environment();

    double getTemperature() const;

    void increaseTemperature();

    void decreaseTemperature();

    void resetControls();

    Water* findNearestWaterSource(Animal& a) const;
};


