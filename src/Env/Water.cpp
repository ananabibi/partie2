#include "Water.hpp"
#include <Application.hpp>

//CONSTRUCTEURS :
Water::Water(Vec2d position)
        :Obstacle(position,getAppConfig().water_size / 2 ,mTraversable), taille(getAppConfig().water_size) {}


// METHODES :
void Water::drawOn(sf::RenderTarget &target) const {
    auto waterSprite(buildSprite(mPosition, taille, getAppTexture(getAppConfig().water_texture)));
    target.draw(waterSprite);
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
//sf::Texture Water::getAppTexture(NULL) {
//}
//}
/*sf::Texture Application::getAppTexture(NULL){
        return
}*/

