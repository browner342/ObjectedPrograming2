#ifndef DNO_HH
#define DNO_HH
#include <vector>
#include <consts.h>
#include "wektor3D.hh"
#include "powierzchnia.hh"

class Dno:public Powierzchnia{
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
};

#endif