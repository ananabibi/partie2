/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */
#include <Tests/GraphicalTests/AnimalTest.hpp>
#include <Env/Buffalo.hpp>
#include <Env/Bush.hpp>
//#include <Env/Water.hpp>
#include <Utility/Utility.hpp>

IMPLEMENT_MAIN(AnimalTest)


void AnimalTest::onRun() {
    // Setup stats
    Application::onRun();
    setStats(false);
    resetStats();
}

void AnimalTest::onSimulationStart() {
    //add more here if needed
    Application::onSimulationStart();
}

void AnimalTest::onEvent(sf::Event event, sf::RenderWindow &) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::B:
                // UNCOMMENT WHEN READY TO TEST
              //  getAppEnv().addEntity(new Buffalo(getCursorPositionInView()));
                break;
            case sf::Keyboard::G: {
                 getAppEnv().addEntity(new Bush(getCursorPositionInView()));
           //     Bush bush = Bush(getCursorPositionInView());
            //    auto bushptr = &bush;
          //      getAppEnv().addEntity(bushptr);
            }
                break;
            case sf::Keyboard::W:
                // UNCOMMENT WHEN READY TO TEST
                getAppEnv().addWaterSource(new Water(getCursorPositionInView()));
                break;
            default:
                break;
        }

    }

}


void AnimalTest::onDraw(sf::RenderTarget & /*target*/) {
    // ADD INSTRUCTIONS IF NEEDED
}

void AnimalTest::resetStats() {
    Application::resetStats();
}

std::string AnimalTest::getHelpTextFile() const {
    return RES_LOCATION + "help_animalTest.txt";
}

std::string AnimalTest::getWindowTitle() const {
    return getAppConfig().window_title + " (AnimalTest)";
}
