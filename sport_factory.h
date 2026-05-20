
#ifndef PROIECT_POO2_SPORT_FACTORY_H
#define PROIECT_POO2_SPORT_FACTORY_H

#include <memory>
#include <string>
#include "sport.h"
#include "fotbal.h"
#include "baschet.h"
#include "tenis.h"
#include "erori.h"

class SportFactory {
    public:
    static std::shared_ptr<Sport> creeazaSport(const std::string& tip, const std::string& nume,double cota,const std::string& pronostic,double extraParam, const std::string& extraString ="") {
        if (tip == "Fotbal") {
            //extraParam determina daca sunt prelungiri
            bool prelungiri = (extraParam != 0);
            return std::make_shared<Fotbal>(nume,cota,pronostic,prelungiri);
        }
        else
            if(tip=="Tenis") {
                //extraParam va det daca e meci dublu,extraString este suprafata
                bool dublu = (extraParam != 0);
                return std::make_shared<Tenis>(nume,cota,pronostic,extraString,dublu);
            }
        else
            if (tip == "Baschet") {
                //extraParam este limita de puncte
                return std::make_shared<Baschet>(nume,cota,pronostic,static_cast<int>(extraParam));
            }
        throw EroarePariuri("Tip sport necunoscut: "+tip);
    }
};

#endif //PROIECT_POO2_SPORT_FACTORY_H