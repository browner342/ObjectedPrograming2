#ifndef SCENA_HH
#define SCENA_HH
#include <wektor3D.hh>
#include <woda.hh>
#include <dno.hh>
#include <consts.h>
#include <string>
#include <fstream>
#include <cstdlib>

class Scena{
    Wektor3D zakresP;
    Wektor3D zakresK;
public:
    Wektor3D zakresy() {std::cout<<zakresP<<std::endl<<zakresK; return zakresK;}
    
    Scena(){zakresP = Wektor3D(); zakresK = Wektor3D();}
    Scena(Wektor3D poczatek, Wektor3D koniec) : Scena(){zakresP = poczatek; zakresK = koniec;}
    
    bool generujSceneDoPliku(const char *nazwaPliku);

};

#endif