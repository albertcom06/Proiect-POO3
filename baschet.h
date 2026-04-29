#ifndef PROIECT_POO2_BASCHET_H
#define PROIECT_POO2_BASCHET_H

#include "sport.h"

class Baschet:public Sport {
    private:
    int limitaPuncte;

    public:
    Baschet(std::string nume_, double cota_, std::string pronostic_, int limita_);
    std::shared_ptr<Sport> clone() const override;
    double calculeazaCastig(double miza) const override;

    private:
    void afisareSpecifica(std::ostream &os) const override;
};

#endif //PROIECT_POO2_BASCHET_H