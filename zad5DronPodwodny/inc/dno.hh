#ifndef DNO_HH
#define DNO_HH
#include <vector>
#include <consts.h>
#include <wektor3D.hh>

class Dno{
    /**
    * Trzyma wartosci punktow siatki dna
    */
    std::string _napis = "";
public:
    /**
    * Tworzy powierzchnie dna na zakresie od poczatek do koniec
    * 
    * @param[in] poczatek - wektorowy poczatek zakresu
    * @param[in] koniec - wektorowy koniec zakresu 
    */
    Dno(Wektor3D poczatek, Wektor3D koniec);

    /**
    * Destruktor dna
    */
    ~Dno(){}

    std::string napis() const {return _napis;}
};

#endif