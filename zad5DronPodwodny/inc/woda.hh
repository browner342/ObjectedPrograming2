#ifndef WODA_HH
#define WODA_HH
#include <vector>
#include <consts.h>
#include <wektor3D.hh>

class Woda{
    std::vector <Wektor3D> wartosci; 
public:
    Woda(){}
    Woda(Wektor3D poczatek, Wektor3D koniec);

    int ilosc(){return wartosci.size();}
    Wektor3D  operator [] (unsigned int i) const { return wartosci[i]; }
};

#endif