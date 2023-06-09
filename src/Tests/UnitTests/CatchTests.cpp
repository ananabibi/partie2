/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

// Define the entry point for tests with Catch frameworks.

#include <Application.hpp>

#define CATCH_CONFIG_RUNNER
#include "../catch/catch.hpp"


int main(int argc, char const** argv)
{
    INIT_DEFAULT_APP(argc, argv);
    return Catch::Session().run();
}
