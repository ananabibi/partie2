/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

#ifndef INFOSV_CHECKUTILITY_HPP
#define INFOSV_CHECKUTILITY_HPP

#include "../catch/catch.hpp"

#include <cmath>

#define CHECK_EPSILON 0.0001

#define CHECK_APPROX_EQUAL(a, b) CHECK(std::abs((a) - (b)) <= CHECK_EPSILON)

#endif // INFOSV_CHECKUTILITY_HPP
