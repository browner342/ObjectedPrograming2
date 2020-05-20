#ifndef DRON_HH
#define DRON_HH

#include "prostopadloscian.hh"
#include "macierz3D.hh"

class Dron:public Prostopadloscian{
    double katZmianyUkladu = 0;
    Wektor3D wektorPrzesunieciaUkladu;
    std::vector <Wektor3D> _ukladGlobalny;
public:
    Dron();
    void ukladWokolOZ(const double& kat);
};
#endif