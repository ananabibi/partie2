/*
 *  Epidemic simulation
 *  2023
 * @authors: 
 *
 */
#pragma once

#include <iostream>
#include <Random/Random.hpp>
#include <array>


using namespace std;

enum Sex {
    MALE, FEMALE
}; // juste important de mettre en dehors de la classe
enum ColorAllele {
    GRAY, BLACK
};

class Genome {
private :
    Sex sexe;
    array<ColorAllele, 2> couleur; //tableau de 2 ColorAllele
    array<double, 10> profilImmun; //tableau de 10 double

public :
    Genome(const Genome *genomeMere = nullptr, const Genome *genomePere = nullptr); //pas sure du const

    Sex getSex() const;

    ColorAllele getFirstColorAllele() const;

    ColorAllele getSecondColorAllele() const;

    ColorAllele getColorPhenotype() const;

    double getImmuneGenes(size_t idx) const;

};

std::ostream &operator<<(ostream &out, const Genome &g);
