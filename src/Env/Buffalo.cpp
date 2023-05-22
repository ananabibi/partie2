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

    if (getAppConfig().getDebug()) {
        sf::Color color = sf::Color::Black;
        color.a = 16; // light, transparent grey
        Arc arc(-mAngle / 2, mAngle / 2, mRayon, color, mRayon);
        arc.setOrigin(mRayon, mRayon);
        arc.setPosition(mDirection);
        target.draw(arc);
    }

}

