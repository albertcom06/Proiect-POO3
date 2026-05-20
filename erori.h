
#ifndef PROIECT_POO2_ERORI_H
#define PROIECT_POO2_ERORI_H

#include <stdexcept>//biblioteca standard exceptii
#include <string>

//clasa de baza pentru toate erorile din aplicatia noastra ,derivata din runtime_error
class EroarePariuri : public std::runtime_error {
public:
    //constructor care paseaza mesaju catre clasa parinte
    explicit EroarePariuri(const std::string& mesaj) : std::runtime_error(mesaj) {}
};

//exceptie pentru situatia in care miza introdusa este negativa
class MizaInvalida : public EroarePariuri {
public:
    explicit MizaInvalida(double miza)
        : EroarePariuri("Miza invalida: " + std::to_string(miza) + ". Trebuie sa fie > 0!") {}
};

//exceptie pentru cazurile in care cotele sunt mai < 1.0
class CotaInvalida : public EroarePariuri {
    public:
    explicit CotaInvalida(double cota)
        : EroarePariuri("Cota Invalida: "+ std::to_string(cota)+" .Cota trebuie sa fie >1.0!"){}
};

#endif //PROIECT_POO2_ERORI_H