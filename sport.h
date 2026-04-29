#ifndef PROIECT_POO2_SPORTURI_H
#define PROIECT_POO2_SPORTURI_H

#include <iostream>
#include <string>
#include <memory>

class Sport {
private:
    std::string numeEchipe;
    double cotaBaza;
    static int nrEvenimenteActive;

protected:
    std::string pronostic;

public:
    Sport(std::string nume_,double cota_, std::string pronostic_);

    virtual ~Sport();

    //Constructor virtual;
    virtual std::shared_ptr<Sport> clone() const=0;

    //Interfata non-virtuala
    void afisareEvenimente() const;

    virtual double calculeazaCastig(double miza) const =0;

    static int getNrEvenimente();

    friend std::ostream& operator<<(std::ostream& os, const Sport& s);

protected:
    //permitem derivatelor sa acceseze cota pentru calcule
    double getCotaBaza() const ;

    std::string getPronostic() const { return pronostic; }

private:
    virtual void afisareSpecifica(std::ostream &os) const =0;
};

#endif //PROIECT_POO2_SPORTURI_H