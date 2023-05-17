#include "Bush.hpp"
#include <Application.hpp>

Bush::Bush(Vec2d pos, double size)
        :LivingEntity(pos,mRayon,mTraversable,getAppConfig().bush_initial_energy), taille(size) {
//    if (not(isColliding(other))) {
    taille = getAppConfig().bush_initial_energy;    // todo This saves the same info twice???
    //position = pos;
    mRayon = taille / 2;    // todo This saves the same info twice???
    mTraversable = true;    // todo This saves the same info twice???
    // }
}

Bush::Bush(Vec2d position)
        :
            LivingEntity(
                    position,
                    getAppConfig().bush_initial_energy/2,
                    true,
                    getAppConfig().bush_initial_energy),
            taille(getAppConfig().bush_initial_energy) {}

void Bush::drawOn(sf::RenderTarget &target) const {
    auto bushSprite(buildSprite(getPosition(), taille, getAppTexture(getAppConfig().bush_texture)));
    target.draw(bushSprite);
};



