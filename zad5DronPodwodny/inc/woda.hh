#ifndef WODA_HH
#define WODA_HH
#include <vector>
#include <consts.h>
#include <wektor3D.hh>

class Woda{
    /**
    * Trzyma wartosci punktow siatki wody
    */
    std::string _napis = "";
public:
    /**
    * Tworzy powierzchnie wody na zakresie od poczatek do koniec
    * 
    * @param[in] poczatek - wektorowy poczatek zakresu
    * @param[in] koniec - wektorowy koniec zakresu 
    */
    Woda(Wektor3D& poczatek, Wektor3D& koniec);

    /**
    * Destruktor wody
    */
    ~Woda(){}

    std::string napis() const {return _napis;}
};

#endif