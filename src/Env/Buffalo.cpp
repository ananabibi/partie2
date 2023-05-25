#include<Application.hpp>
#include "Buffalo.hpp"
#include "Utility/Arc.hpp"

Buffalo::Buffalo(
        Vec2d position, double rayon, bool traversable,
        double energie,
        const Genome *genomeMere, const Genome *genomePere)
        : Animal(position, rayon, traversable, getAppConfig().buffalo_energy_initial) {
    mDirection = Vec2d(1, 0).normalised();
}

double Buffalo::getMass() const {
    return getAppConfig().buffalo_mass;
}

double Buffalo::getStandardMaxSpeed() const {
    return getAppConfig().buffalo_max_speed;
}

void Buffalo::drawOn(sf::RenderTarget &target) const {
    auto config = getAppConfig();
    std::string texture;

    if (mGenome.getSex()== MALE) {
        if (mGenome.getColorPhenotype()== GRAY){
            texture = config.buffalo_texture_gray_male;
        }   else {
            texture = config.buffalo_texture_black_male;
        }
    } else {
        if (mGenome.getColorPhenotype()== GRAY){
            texture = config.buffalo_texture_gray_female;
        }   else {
            texture = config.buffalo_texture_black_female;
        }
    }


    auto radians = mDirection.angle();// todo Change to degrees
    auto degres = radians / DEG_TO_RAD;

    auto buffaloSprite(
            buildSprite(getPosition(),
                        config.buffalo_size,
                        getAppTexture(texture),
                        degres));

    target.draw(buffaloSprite);

    if (getAppConfig().getDebug()) { // todo modulariser
        sf::Color color = sf::Color::Black;
        if (eauPercue != nullptr) color = sf::Color::Blue; // todo enlever (debug)
        color.a = 16; // light, transparent grey

        double viewRange = getViewRange() / DEG_TO_RAD;
        double viewDistance = getViewDistance();
        double angle = mDirection.angle() / DEG_TO_RAD;
        Vec2d position = getPosition();

        Arc arc(-viewRange/2, viewRange/2, viewDistance, color, viewDistance);
        arc.setOrigin(viewDistance, viewDistance);
        arc.setPosition(position);
        arc.rotate(angle);

        target.draw(arc);
    }

}

