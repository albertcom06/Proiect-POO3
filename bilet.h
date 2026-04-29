#ifndef PROIECT_POO2_BILET_H
#define PROIECT_POO2_BILET_H

#include <vector>
#include <algorithm>
#include <memory>
#include "sport.h"
#include "erori.h"

class Bilet {
private:
    std::vector<std::shared_ptr<Sport>> pariuri;
    double miza;

    double calculeazaProcentRecursiv(int nrMeciuri) const;

public:

    //Constructor de initializare
    Bilet(double miza_=0);

    //Constructor de copiere: cream un bilet nou identic cu unul existent
    Bilet(const Bilet& other);

    friend void swap(Bilet& b1, Bilet& b2) noexcept;


    Bilet& operator=(Bilet other);

    void adaugaMeci(std::shared_ptr<Sport> s);

    double calculeazaPotentialCastig() const;

    void aplicaBonusMultipla(double& cotaFinala) const;

    void afiseazaContinut() const;
};

#endif //PROIECT_POO2_BILET_H