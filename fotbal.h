#ifndef PROIECT_POO2_FOTBAL_H
#define PROIECT_POO2_FOTBAL_H

#include "sport.h"
class Fotbal: public Sport {
private:
    bool arePrelungiri;
    public:

    Fotbal(std::string nume_, double cota_,std::string pronostic_,bool prelungiri_);

    //Implementare clone
    std::shared_ptr<Sport> clone() const override;

    // Calcul specific:taxă de solidaritate de 1%
    double calculeazaCastig(double miza) const override;

    bool getArePrelungiri() const;

private:
    void afisareSpecifica(std::ostream& os) const override;
};
#endif //PROIECT_POO2_FOTBAL_H