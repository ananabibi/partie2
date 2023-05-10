/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <string>

// Numerical constants
double const DEG_TO_RAD = 0.0174532925; ///< Degree to Radian conversion constant
double const TAU = 6.283185307;         ///< TAU constant (= 2 * PI)
double const PI = 3.141592654;          ///< PI constant
double const EPSILON = 1e-8;            ///< a small epsilon value

// Define resources location
std::string const RES_LOCATION = "../res/";

// Define the location of the config file
std::string const DEFAULT_CFG = "app2.json";

// Define the location of the font file (could be in the config instead of here)
std::string const APP_FONT_LOCATION = RES_LOCATION + "sansation.ttf";


/// Loader parameters
std::string const MAP_NAME = "MAP_NAME";

// Stats titles
namespace s
{

std::string const GENERAL = "general";
std::string const LIONS = "lions";
std::string const BUFFALOS  = "buffalos";
std::string const BUSHES  = "bushes";
std::string const INFECTED  = "infected";
std::string const ANIMAL_INDIVIDUAL = "Tracked Animal";
std::string const BUSH_INDIVIDUAL   = "Tracked bushes";
	
std::string const INDIVIDUAL = "Tracked Animal";
std::string const HEALTH = "health";
std::string const ENERGY = "energy";
std::string const VIRUS = "virus";
std::string const SCORE = "score";
std::string const ADASCORE = "adapt-score";
std::string const IMUNAC= "immune-act";


} // s


