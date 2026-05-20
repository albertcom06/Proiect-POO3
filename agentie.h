
#ifndef PROIECT_POO2_AGENTIE_H
#define PROIECT_POO2_AGENTIE_H

#include <iostream>
#include <string>

class AgentiePariuri {
private:
    std::string numeAgentie;

    //Constructor privat
    AgentiePariuri(): numeAgentie("Superbet"){}

public:
    AgentiePariuri(const AgentiePariuri&)=delete;
    AgentiePariuri& operator=(const AgentiePariuri&) =delete;

    static AgentiePariuri& get_instance() {
        static AgentiePariuri instance;
        return instance;
    }
void afisareMsjBunVenit() const {
        std::cout <<"\n";
        std::cout << numeAgentie<<"\n";
        std::cout <<"\n";
    }
};
#endif //PROIECT_POO2_AGENTIE_H