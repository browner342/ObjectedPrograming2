#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

//#include "lzespolona.hh"
#include <iostream>
#include <math.h>
#include "wektor.hh"

class Wektor3D: public Wektor<double, 3>{
    static int iloscWszystkie;
    static int iloscZniszczone;

public:
    int ileWszystkie() const {return iloscWszystkie;}
    int ileTeraz()     const {return iloscWszystkie - iloscZniszczone;}

    Wektor3D() : Wektor<double, 3>() {iloscWszystkie++;}
    Wektor3D(const Wektor3D &w){(*this) = w; iloscWszystkie++;}
    Wektor3D(double x, double y, double z) : Wektor<double, 3>() {(*this)(0)= x; (*this)(1)= y; (*this)(2)= z; iloscWszystkie++;}
    Wektor3D(const Wektor<double, 3> &m) : Wektor<double, 3>(m) {iloscWszystkie++;}
    ~Wektor3D(){iloscZniszczone++;}

    std::string napis() const;
};


#endif