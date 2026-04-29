//
// Created by userpc on 4/25/2026.
//
#ifndef PROIECT_POO2_ERORI_H
#define PROIECT_POO2_ERORI_H

#include <stdexcept>
#include <string>

class EroarePariuri : public std::runtime_error {
public:
    explicit EroarePariuri(const std::string& mesaj) : std::runtime_error(mesaj) {}
};

class MizaInvalida : public EroarePariuri {
public:
    explicit MizaInvalida(double miza)
        : EroarePariuri("Miza invalida: " + std::to_string(miza) + ". Trebuie sa fie > 0!") {}
};

class CotaInvalida : public EroarePariuri {
    public:
    explicit CotaInvalida(double cota)
        : EroarePariuri("Cota Invalida: "+ std::to_string(cota)+" .Cota trebuie sa fie >1.0!"){}
};

#endif //PROIECT_POO2_ERORI_H