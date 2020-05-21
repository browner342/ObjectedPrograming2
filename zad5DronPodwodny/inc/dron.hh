#ifndef DRON_HH
#define DRON_HH

#include "prostopadloscian.hh"
#include "macierz3D.hh"
#include <cmath>

class Dron:public Prostopadloscian{
    double katZmianyUkladu = 0;
    Wektor3D wektorPrzesunieciaUkladu;
    std::vector <Wektor3D> _ukladGlobalny;
public:
    Dron();
    void powrotDoUkladuLok();
    void obrotWokolOZ(const double& kat);
    void ruchNaWprost(const double& katGoraDol, const double& odleglosc);
    bool wykrywanieKolizjiZDnem();
    bool wykrywanieKolizjiZWoda();
    void dronPozaMapa(Wektor3D& po, Wektor3D& ko);
    std::string generujDronaDoPliku();
    std::string napis() const {return _napis;}
};
#endif