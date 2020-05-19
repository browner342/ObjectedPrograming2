#ifndef DNO_HH
#define DNO_HH
#include <vector>
#include <consts.h>
#include <wektor3D.hh>

class Dno{
    std::vector <Wektor3D> wartosci; 
public:
    Dno(){}
    Dno(Wektor3D poczatek, Wektor3D koniec);

    int ilosc(){return wartosci.size();}
    Wektor3D  operator [] (unsigned int i) const { return wartosci[i]; }
};

#endif