/*
 * prjsv 2023
 * @authors : 
 */

#include <Env/Environment.hpp>
#include<SFML/Graphics.hpp>
#include <Application.hpp>
#include "Buffalo.hpp"

//bool Environment::isPlaceable(Obstacle* other) {
//    for(auto eau: plans) {
//        if (eau->isColliding(*other)) return false;
//    }
//    for(auto entity: etres) {
//        if(entity->isColliding(*other)) return false;
//    }
//    return true;
//}


bool Environment::isEntityPlaceable(LivingEntity e) {
    for (auto etre: etres) {
        if (e.isColliding(*etre)) {
            return false;
        }
    }
    for (auto plan: plans) {
        if (e.isColliding(*plan)) {
            return false;
        }
    }

    return true;
}

bool Environment::isWaterPlaceable(Water w) {
    for (auto eau: plans) {
        if (w.isColliding(*eau)) {
            return false;
        }
    }

    return true;
}

// SETTERS :



void Environment::addEntity(LivingEntity *e) {
    if (isEntityPlaceable(*e)) {//compléter
        etres.push_back(e);
    }
}

void Environment::addWaterSource(Water *w) {
    plans.push_back(w);
}


// METHODES :

void Environment::update(sf::Time dt) {
    //faire évoluer tout ce qui peut évoluer ici:
    for (Water* plan : plans) {
        plan->update( dt);
    }

}


void Environment::drawOn(sf::RenderTarget &targetWindow) const {
    for (Water* plan : plans) {
        plan->drawOn(targetWindow);
    }
    for (LivingEntity* etre : etres) {
        etre->drawOn(targetWindow);
    }
}


void Environment::reset() {
    etres.clear();
    plans.clear();
}


void Environment::increaseTemperature() {
    if (temperature <= getAppConfig().environment_max_temperature - 0.5) {
        temperature += 0.5;
    }
}

void Environment::decreaseTemperature() {
    if (temperature >= getAppConfig().environment_min_temperature + 0.5) {
        temperature -= 0.5;
    }
}


void Environment::resetControls() {
    temperature = getAppConfig().environment_default_temperature;
}


// CONSTRUCTEURS :
Environment::Environment()
        : temperature(getAppConfig().environment_default_temperature) {}
// question : constructeur par defaut initialise les listes au tableau vide ou pas ?

// GETTERS :
double Environment::getTemperature() const {
    return temperature;
}


