#include "sport.h"

int Sport::nrEvenimenteActive = 0;

Sport::Sport(std::string nume_, double cota_,std::string pronostic_) : numeEchipe(std::move(nume_)), cotaBaza(cota_),pronostic(std::move(pronostic_)) {
    nrEvenimenteActive++;}

Sport::~Sport() {
    nrEvenimenteActive--;}

void Sport::afisareEvenimente() const {
    std::cout << "Eveniment sportiv \n";
    std::cout << "Meci: " << numeEchipe << "\n";
    std::cout << "Cota: " << cotaBaza << "\n";
    afisareSpecifica(std::cout);
}

double Sport::getCotaBaza() const { return cotaBaza; }

int Sport::getNrEvenimente() { return nrEvenimenteActive; }

std::ostream& operator<<(std::ostream& os, const Sport& s) {
    os << "Eveniment sportiv\n";
    os << "Meci: " << s.numeEchipe << "\n";
    os << "Cota: " << s.cotaBaza << "\n";
    s.afisareSpecifica(os); // Aici se produce polimorfismul
    return os;
}