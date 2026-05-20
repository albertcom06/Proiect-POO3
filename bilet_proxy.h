#ifndef PROIECT_POO2_BILET_PROXY_H
#define PROIECT_POO2_BILET_PROXY_H

#include "bilet.h"
#include <iostream>

template <typename T>
class BiletProxy {
private:
    Bilet<T> biletReal;
    bool esteContPremium; //indicator pentru statutul pariorului

    public:
    //Constructor Proxy ;primeste miza, detaliu si tipul contului
    BiletProxy(double miza, T detaliu, bool premium):biletReal(miza,detaliu),esteContPremium(premium){}

    //functie pentru adaugarea meciurilor direct in biletul real
    void adaugaMeci(std::shared_ptr<Sport> s) {
        biletReal.adaugaMeci(s);
    }

    //Functia principala din proxy care controleaza accesul la biletul real
    void proceseazaSiPlaseazaBilet() {
        double potentialCastig = biletReal.calculeazaPotentialCastig();

        std::cout<<"\nSe verifica biletul inainte de plasare\n";

        //Regula Proxy:Daca biletul poate castiga peste 5000 ron si userul nu e premium,biletul nu poate fi plasat
        if (potentialCastig>5000 && !esteContPremium) {
            std::cout<<"Eroare securitate: Castigul potential : "<<potentialCastig<<" ron , depaseste limita de 5000ron pentru conturile standard";

        }
        else {
            std::cout<<"Validare reusita! Biletul a fost plasat";
            biletReal.afiseazaContinut();
        }
    }

};


#endif //PROIECT_POO2_BILET_PROXY_H