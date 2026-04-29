#ifndef PROIECT_POO2_TENIS_H
#define PROIECT_POO2_TENIS_H

#include "sport.h"
#include "erori.h"

class Tenis : public Sport {

private:
    std::string suprafataTeren;
    bool esteMeciDublu;

public:

    //Constructorul derivatei
    Tenis(std::string nume_, double cota_, std::string pronostic_, std::string suprafata_,bool dublu_);

   //constructor virtual
    std::shared_ptr<Sport> clone() const override;

    //suprascrierea calcului de castig
    double calculeazaCastig(double miza) const override;

private:
    void afisareSpecifica(std::ostream &os) const override;
};
#endif //PROIECT_POO2_TENIS_H