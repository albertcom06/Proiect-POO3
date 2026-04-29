#include "fotbal.h"

Fotbal::Fotbal(std::string nume_, double cota_,std::string pronostic_, bool prelungiri_)
    :Sport(std::move(nume_), cota_,std::move(pronostic_)), arePrelungiri(prelungiri_){}

std::shared_ptr<Sport> Fotbal::clone() const {
    return std::make_shared<Fotbal>(*this);
}

double Fotbal::calculeazaCastig(double miza) const {
    return miza * getCotaBaza() * 0.99;
}
bool Fotbal::getArePrelungiri() const {return arePrelungiri;}

void Fotbal::afisareSpecifica(std::ostream &os) const {
    os << "[Fotbal] Pronostic: " <<getPronostic()
    <<" | Cota: "<<getCotaBaza()
    << " | Prelungiri: " << (arePrelungiri ? "Da" : "Nu");
}
