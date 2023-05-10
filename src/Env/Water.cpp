#include "Water.hpp"
#include <Application.hpp>

//CONSTRUCTEURS :
Water::Water(Vec2d p)
        :Obstacle(position,getAppConfig().water_size / 2 ,traversable), taille(getAppConfig().water_size) {}


// METHODES :
void Water::drawOn(sf::RenderTarget &target) const {
    // à faire
}

void Water::update(sf::Time dt) {
    if (getAppEnv().getTemperature() > getAppConfig().water_evaporation_threshold) {
        taille -= dt.asSeconds() * getAppConfig().water_evaporation_rate;
    }
    if (taille < 0) {
        taille = 0;
    }
}

//GETTERS
//sf::Texture Water::Application::getAppTexture(NULL){   // todo What is needed here
/*sf::Texture Application::getAppTexture(NULL){
        return
}*/

