#ifndef PROIECT_POO2_BILET_H
#define PROIECT_POO2_BILET_H

#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include "sport.h"
#include "erori.h"

//Functie libera template
template <typename T>
void afiseazaMesajSistem(const T& mesaj) {
    std::cout<<" Sistem bilete "<< mesaj<< "\n";
}


template <typename T>
class Bilet {
private:
    std::vector<std::shared_ptr<Sport>> pariuri;
    double miza;

    //atribut de tip t
    T detaliuBilet;

    double calculeazaProcentRecursiv(int nrMeciuri) const{
        if (nrMeciuri <= 3) {
            return 0.0; // Cazul de baza: nu mai exista bonus sub 4 meciuri
        }
        // Pasul recursiv: 5% pentru meciul curent + bonusul meciurilor anterioare
        return 0.05 + calculeazaProcentRecursiv(nrMeciuri - 1);
    }

public:

    //Constructor de initializare
    Bilet(double miza_=0, T detaliu_ = T()) : miza(miza_), detaliuBilet(detaliu_) {
        if (miza_ < 0 ) throw MizaInvalida(miza_);
    }

    //Constructor de copiere: cream un bilet nou identic cu unul existent
    Bilet(const Bilet& other): miza(other.miza) , detaliuBilet(other.detaliuBilet) {
        //parcurgem lista de meciuri din biletul pe care il copiem
        for (const auto& p: other.pariuri) {
            this->pariuri.push_back(p->clone());
        }
    }

    friend void swap(Bilet& b1, Bilet& b2) noexcept {
        using std::swap;
        swap(b1.pariuri, b2.pariuri);
        swap(b1.miza, b2.miza);
        swap(b1.detaliuBilet, b2.detaliuBilet);
    };



    Bilet& operator=(Bilet other) {
        swap(*this, other); //schimbam tot ce are biletul curent cu datele din copia other
        return *this;//returnam obiectul actualizat
    }

    T getDetaliu() const {
        return detaliuBilet;
    }

    void adaugaMeci(std::shared_ptr<Sport> s){
       pariuri.push_back(s->clone());
    }

    double calculeazaPotentialCastig() const {

        if (pariuri.empty()) return 0;

        double cotaFinala = 1;
        for (const auto& p : pariuri) {
            cotaFinala *= p->calculeazaCastig(1.0);
        }

        aplicaBonusMultipla(cotaFinala);
        return miza*cotaFinala;
    }

    void aplicaBonusMultipla(double& cotaFinala) const{
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

    void afiseazaContinut() const {
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
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Bilet<U>& b);
};

//operator friend template
template <typename T>
std::ostream& operator<<(std::ostream& os, const Bilet<T>& b) {
    os<<"Miza: "<<b.miza<<" | Info: "<<b.detaliuBilet;
    return os;
}

#endif //PROIECT_POO2_BILET_H