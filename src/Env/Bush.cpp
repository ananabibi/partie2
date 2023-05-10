#include "Bush.hpp"
#include <Application.hpp>

Bush::Bush(Vec2d pos, double size)
        :LivingEntity(position,rayon,traversable,getAppConfig().bush_initial_energy), taille(size) {
//    if (not(isColliding(other))) {
        taille = getAppConfig().bush_initial_energy;    // todo This saves the same info twice???
        //position = pos;
        rayon = taille / 2;    // todo This saves the same info twice???
        traversable = true;    // todo This saves the same info twice???
//    }
}
