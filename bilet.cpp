#include "bilet.h"
Bilet::Bilet(double miza_):miza(miza_) {
        if (miza_ < 0 ) throw MizaInvalida(miza_);
    }

Bilet::Bilet(const Bilet& other) : miza(other.miza) {
    //parcurgem lista de meciuri din biletul pe care il copiem
    for (const auto& p: other.pariuri) {
        this->pariuri.push_back(p->clone());
    }
}

void swap(Bilet& b1, Bilet& b2) noexcept {
    using std::swap;
    swap(b1.pariuri, b2.pariuri);
    swap(b1.miza, b2.miza);
};

//Operator de atribuire (operator=):foloseste copy and swap
Bilet& Bilet::operator=(Bilet other) {
    swap(*this, other); //schimbam tot ce are biletul curent cu datele din copia other
    return *this;//returnam obiectul actualizat
}

void Bilet::adaugaMeci(std::shared_ptr<Sport> s) {
    pariuri.push_back(s->clone());
}

// Functia recursiva: adauga 0.05 pentru fiecare meci peste 3
double Bilet::calculeazaProcentRecursiv(int nrMeciuri) const {
    if (nrMeciuri <= 3) {
        return 0.0; // Cazul de baza: nu mai exista bonus sub 4 meciuri
    }
    // Pasul recursiv: 5% pentru meciul curent + bonusul meciurilor anterioare
    return 0.05 + calculeazaProcentRecursiv(nrMeciuri - 1);
}

void Bilet::aplicaBonusMultipla(double& cotaFinala) const {
    if (pariuri.size() >= 4) {
        bool toateCoteleSuntOk = true;
        for (const auto& p : pariuri) {
            if (p->calculeazaCastig(1.0) <= 1.25) {
                toateCoteleSuntOk = false;
                break;
            }
        }

        if (toateCoteleSuntOk) {
            double procentTotal = calculeazaProcentRecursiv(pariuri.size());

            std::cout << "Bonus multiplu activat: +"
                      << procentTotal * 100 << "%\n";

            cotaFinala *= (1.0 + procentTotal);
        }
    }
}

double Bilet::calculeazaPotentialCastig() const {

    if (pariuri.empty()) return 0;

    double cotaFinala = 1;
    for (const auto& p : pariuri) {
        cotaFinala *= p->calculeazaCastig(1.0);
    }

    aplicaBonusMultipla(cotaFinala);
    return miza*cotaFinala;
}




void Bilet::afiseazaContinut() const {
    std::cout << "\n Continut bilet \n";
    for (const auto& p : pariuri) {
        p->afisareEvenimente(); // Folosește interfața non-virtuala care apeleaza polimorfic afisareSpecifica
        std::cout << "\n";
    }

    double cotaFaraBonus = 1.0;
    for (const auto& p : pariuri) cotaFaraBonus *= p->calculeazaCastig(1.0);

    double cotaFinala = cotaFaraBonus;
    aplicaBonusMultipla(cotaFinala); // Aici se apeleaza recursivitatea si se afisează mesajul de bonus

    std::cout << "Miza: " << miza << " Ron\n";
    std::cout << "Cota totala: " << cotaFinala << "\n";
    std::cout << "Cota cumulata (fara bonus): " << cotaFaraBonus << "\n";
    std::cout << " Castig potential: " << (miza * cotaFinala) << " RON\n";


    if (cotaFinala > cotaFaraBonus) {
        double profitBonus = (cotaFinala - cotaFaraBonus) * miza;
        std::cout << "Cota finala (cu bonus): " << cotaFinala << "\n";
        std::cout << "Castig extra din bonus: " << profitBonus << " RON\n";
    }
}