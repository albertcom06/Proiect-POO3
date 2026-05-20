#include "tenis.h"

// Implementare Constructor
Tenis::Tenis(std::string nume_, double cota_, std::string pronostic_, std::string suprafata_,bool dublu_)
        :Sport(std::move(nume_),cota_,std::move(pronostic_)),suprafataTeren(std::move(suprafata_)),esteMeciDublu(dublu_) {

    //validare specifica,nu putem avea egal
    if (getPronostic() == "X" || getPronostic()== "x") {
        throw EroarePariuri("Nu putem paria egal pe tenis");
    }
}
// Implementare clone
std::shared_ptr<Sport> Tenis::clone() const {
    return std::make_shared<Tenis>(*this);
}
// Implementare calcul castig cu bonus de suprafata
double Tenis::calculeazaCastig(double miza) const {
    double bonusSuprafata = 1.0;
    if (suprafataTeren == "Iarba") {
        bonusSuprafata = 1.02;
    }
    return miza * getCotaBaza() * bonusSuprafata;
}
// Implementare afisare specifica
void Tenis::afisareSpecifica(std::ostream &os) const {
    os << " [Tenis] Pronostic: " << getPronostic()
       << "  Suprafata: " << suprafataTeren
       << "  Tip: " << (esteMeciDublu ? "Dublu" : "Simplu");
}