#include "fotbal.h"

//Constructor
Fotbal::Fotbal(std::string nume_, double cota_,std::string pronostic_, bool prelungiri_)
    :Sport(std::move(nume_), cota_,std::move(pronostic_)), arePrelungiri(prelungiri_){}

//Implementare clone
std::shared_ptr<Sport> Fotbal::clone() const {
    return std::make_shared<Fotbal>(*this);
}

//calcul specific:la fotbal aplicam o taxa de 1%
double Fotbal::calculeazaCastig(double miza) const {
    return miza * getCotaBaza() * 0.99;
}
bool Fotbal::getArePrelungiri() const {return arePrelungiri;}

//afisare detalii extra
void Fotbal::afisareSpecifica(std::ostream &os) const {
    os << "[Fotbal] Pronostic: " <<getPronostic()
    << " | Prelungiri: " << (arePrelungiri ? "Da" : "Nu");
}
