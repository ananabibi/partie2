/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

#ifndef INFOSV_RANDOMGENERATOR_HPP
#define INFOSV_RANDOMGENERATOR_HPP

#include <random>

/**
 *  @brief  Get a unique random number generator
 *
 *  @return always the same generator
 */
std::mt19937& getRandomGenerator();

#endif // INFOSV_RANDOMGENERATOR_HPP
