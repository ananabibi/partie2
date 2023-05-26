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


    auto radians = mDirection.angle();
    auto degres = radians / DEG_TO_RAD;

    auto buffaloSprite(
            buildSprite(getPosition(),
                        config.buffalo_size,
                        getAppTexture(texture),
                        degres));

    target.draw(buffaloSprite);

    if (getAppConfig().getDebug()) {
        drawArc(target);
        drawTexts(target);
    }
}

void Buffalo::drawArc(sf::RenderTarget &target) const {
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

void Buffalo::drawTexts(sf::RenderTarget &target) const {
    const string state = mAssoiffe ? "Thirsty" : "Not thirsty";
    const string energy = to_nice_string(getEnergy());

    const size_t textSize = getAppConfig().default_debug_text_size;
    const sf::Color textColor = getAppConfig().debug_text_color;
    double textRotation = mAngle / DEG_TO_RAD + 90;
    Vec2d position = LivingEntity::getPosition();
    Vec2d thirstPosition = {position.x() + (mDirection.x() + 1)*getRadius(), position.y() + (mDirection.y() - 1)*getRadius()}; //todo mieux placer
    Vec2d energyPosition = {position.x() + (mDirection.x() + 1)*getRadius(), position.y() + mDirection.y()*getRadius()};

    auto const thirstState = buildText(state, thirstPosition, getAppFont(), textSize, textColor, textRotation);
    auto const energyState = buildText(energy, energyPosition, getAppFont(), textSize, textColor, textRotation);

    target.draw(thirstState);
    target.draw(energyState);

}

