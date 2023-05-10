#include "Genome.hpp"
#include <Random/Random.hpp>
#include <Application.hpp>



//CONSTRUCTEURS

Genome::Genome(const Genome *genomeMere, const Genome *genomePere) {
    //on peut le mettre en dehors des du if car dans les deux cas on doit l'utiliser
    sexe = bernoulli(0.5) ? FEMALE : MALE;

    // For 'new' buffaloes
    if (genomeMere == nullptr or genomePere == nullptr) {
        couleur[0] = (bernoulli(getAppConfig().genome_gray_allele_prevalence)) ? GRAY : BLACK;
        couleur[1] = (bernoulli(getAppConfig().genome_gray_allele_prevalence)) ? GRAY : BLACK;

        for (size_t i = 0; i < 10; ++i) {
            profilImmun[i] = uniform(-5.0, 5.0);
        }

    } else {
        // We made a baby
        couleur[0] = bernoulli(0.5) ? genomeMere->getFirstColorAllele() : genomeMere->getSecondColorAllele();
        couleur[1] = bernoulli(0.5) ? genomePere->getFirstColorAllele() : genomePere->getSecondColorAllele();


        for (size_t i = 0; i < 10; ++i) {
            double v = getAppConfig().genome_mutability_innate_immune_system;
            double base = bernoulli(0.5) ? genomeMere->getImmuneGenes(i) : genomePere->getImmuneGenes(i);
            double variance = uniform(-v, v);

            profilImmun[i] = base + variance;
        }
    }
}

//GETTERS

Sex Genome::getSex() const {
    return sexe;
}

ColorAllele Genome::getFirstColorAllele() const {
    return couleur[0];
}

ColorAllele Genome::getSecondColorAllele() const {
    return couleur[1];
}

ColorAllele Genome::getColorPhenotype() const {
    if (couleur[0] == GRAY and couleur[1] == GRAY) {
        return GRAY;
    } else {
        return BLACK;
    }

}

double Genome::getImmuneGenes(size_t idx) const {
    return profilImmun[idx];

}

std::ostream &operator<<(ostream &out, const Genome &g) {
    out << "Genome (" << g.getSex() << ") :" << endl;
    out << " Color phenotype = " << g.getColorPhenotype() << endl;
    out << " First color allele = " << g.getFirstColorAllele() << endl;
    out << " Second color allele = " << g.getSecondColorAllele() << endl;
    out << " Immune profile =";
    for (size_t i = 0; i < 10; ++i) {
        out << " " << g.getImmuneGenes(i);
    }
    out << endl;

    return out;
}


