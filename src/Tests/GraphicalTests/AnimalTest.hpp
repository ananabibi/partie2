/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <Application.hpp>

/*!
 *  Test prey-predator simulation
 *
 * Generate one target on click
 */

class AnimalTest : public Application
{
public:
  AnimalTest(int argc, char const** argv)
    : Application(argc, argv)
  {
  }
  virtual void onRun() override final;
  virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
  virtual void onSimulationStart() override final;

  virtual void onDraw(sf::RenderTarget& target) override final;
  virtual void resetStats() override final;
  virtual std::string getHelpTextFile() const override final;
  std::string virtual getWindowTitle() const override final;
};

