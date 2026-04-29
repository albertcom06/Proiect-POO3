#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "sport.h"
#include "tenis.h"
#include "fotbal.h"
#include "baschet.h"
#include "bilet.h"
#include "erori.h"

 //Citim fisierul si cream o lista de meciuri
 std::vector<std::shared_ptr<Sport>> incarcaOferta(const std::string& Meciuri_bilet){
    std::vector<std::shared_ptr<Sport>> oferta;
    std::ifstream fin(Meciuri_bilet);
    if (!fin.is_open()) {
        throw EroarePariuri("Eroare:Nu s-a putut deschide fisierul "+Meciuri_bilet+"|Cod eroare: "+std::to_string(errno));
    }

    std::string tip;
    while (fin >> tip) {
        std::string nume, pronostic;
        double c1, cX, c2;
        double cota=0;

        if (tip =="Fotbal") {
            bool prelungiri;
            fin>>nume>>c1>>cX>>c2>>pronostic>>prelungiri;

            if (pronostic == "1") cota = c1;
            else if (pronostic == "X" || pronostic == "x") cota = cX;
            else if (pronostic == "2") cota = c2;
            else throw EroarePariuri("Pronostic invalid pentru fotbal: " + pronostic);

            if (cota <= 1.0) throw CotaInvalida(cota);

            oferta.push_back(std::make_shared<Fotbal>(nume, cota, pronostic, prelungiri));
        }else if (tip=="Tenis") {
            std::string suprafata;
            bool dublu;
            fin >> nume >> c1 >> c2 >> pronostic >> suprafata >> dublu;

            if (pronostic == "1") cota= c1;
            else if (pronostic == "2") cota = c2;
            else throw EroarePariuri("Nu exista optiunea de egal: " + pronostic);

            if (cota <= 1.0) throw CotaInvalida(cota);

           oferta.push_back(std::make_shared<Tenis>(nume, cota, pronostic, suprafata, dublu));
        }else if (tip=="Baschet") {
            int limita;
            fin >> nume >> c1 >> cX >> c2 >> pronostic >> limita;
            if (pronostic == "1") cota = c1;
            else if (pronostic == "X") cota = cX;
            else if (pronostic == "2") cota = c2;
            else throw EroarePariuri("Pronostic invalid baschet: " + pronostic);

            if (cota <= 1.0) throw CotaInvalida(cota);

            oferta.push_back(std::make_shared<Baschet>(nume, cota, pronostic, limita));
        }
    }
    return oferta;
}

void verificaDetaliiFotbal(const std::vector<std::shared_ptr<Sport>>& lista) {
     std::cout << "\nVerificare detaliata meciuri Fotbal (Dynamic Cast)\n";
     int count = 0;

     for (const auto& s : lista) {
         // incercam sa convertim pointerul de baza la pointer de Fotbal
         // folosim std::dynamic_pointer_cast pentru shared_ptr
         auto meciFotbal = std::dynamic_pointer_cast<Fotbal>(s);

         if (meciFotbal) { // daca conversia a reușit (obiectul chiar este Fotbal)
             count++;
             std::cout << "Meciul " << count << " este Fotbal. ";
             // acum putem accesa metode sau atribute specifice Fotbalului
         }
     }

     if (count == 0) {
         std::cout << "Nu am gasit niciun meci de fotbal in aceasta lista.\n";
     }
 }

std::vector<std::shared_ptr<Sport>> filtreazaDupaSport(const std::vector<std::shared_ptr<Sport>>& oferta, const std::string& tipCautat) {
     std::vector<std::shared_ptr<Sport>> rezultat;

     for (const auto& s : oferta) {
         if (tipCautat == "Fotbal") {
             // Folosim dynamic_pointer_cast pentru a verifica dacă obiectul este de tip Fotbal
             if (std::dynamic_pointer_cast<Fotbal>(s)) {
                 rezultat.push_back(s->clone()); // Folosim clone() conform cerintei de cc
             }
         }
         else if (tipCautat == "Tenis") {
             if (std::dynamic_pointer_cast<Tenis>(s)) {
                 rezultat.push_back(s->clone());
             }
         }
         else if (tipCautat == "Baschet") {
             if (std::dynamic_pointer_cast<Baschet>(s)) {
                 rezultat.push_back(s->clone());
             }
         }
     }
     return rezultat;
 }


int main() {

    try {
        // 1. Incarca toate optiunile din fisier
        auto ofertaMeciuri = incarcaOferta("Meciuri_bilet");
        size_t nrMeciuri = ofertaMeciuri.size();

        verificaDetaliiFotbal(ofertaMeciuri);


        // 2. Cream Biletul 1 (Meciul 1 si 2)
        Bilet bilet1(50.0);
        if (nrMeciuri >= 2) {
            bilet1.adaugaMeci(ofertaMeciuri[0]->clone());
            bilet1.adaugaMeci(ofertaMeciuri[1]->clone());
        }

        // 3. Cream Biletul 2 (Meciul 2 si 3)
        Bilet bilet2(100.0);
        if (nrMeciuri >= 3) {
            bilet2.adaugaMeci(ofertaMeciuri[1]->clone()); // Clonat pentru a fi independent
            bilet2.adaugaMeci(ofertaMeciuri[2]->clone());
        }

        // Afișare rezultate
        std::cout << "\n Bilet 1 \n";
        bilet1.afiseazaContinut();
        std::cout << "Castig: " << bilet1.calculeazaPotentialCastig() << " RON\n\n";

        std::cout << " Bilet 2 \n";
        bilet2.afiseazaContinut();
        std::cout << "Castig: " << bilet2.calculeazaPotentialCastig() << " RON\n";


        std::cout << "\n Meciuri de tenis disponibile: \n";
        auto doarTenis = filtreazaDupaSport(ofertaMeciuri, "Tenis");

        for (const auto& meci : doarTenis) {
            std::cout << *meci << "\n"; // Foloseste operatorul << polimorfic
        }

        // Creare bilet doar cu meciuri de tenis
        if (!doarTenis.empty()) {
            Bilet biletSpecial(20.0);
            biletSpecial.adaugaMeci(doarTenis[0]);

        }

        std::cout<<"\n";

        Bilet biletGigant(10.0);
        for(const auto& m : ofertaMeciuri) {
            biletGigant.adaugaMeci(m);
        }
        biletGigant.afiseazaContinut();

    } catch (const EroarePariuri& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
    }
    return 0;
}