#include "baschet.h"

Baschet::Baschet(std::string nume_,double cota_, std::string pronostic_, int limita_)
    :Sport(std::move(nume_),cota_,std::move(pronostic_)),limitaPuncte(limita_) {}

std::shared_ptr<Sport> Baschet::clone() const {
    return std::make_shared<Baschet>(*this);
}

double Baschet::calculeazaCastig(double miza) const {
    // bonus de 5% daca limita de puncte este mare
    double bonus = (limitaPuncte > 200) ? 1.05 : 1.0;
    return miza * getCotaBaza() * bonus;
}

void Baschet::afisareSpecifica(std::ostream& os) const {
    os << " [Baschet] Pronostic: " << getPronostic()
       <<"  Cota: "<<getCotaBaza()
       << "  Limita puncte: " << limitaPuncte;
}