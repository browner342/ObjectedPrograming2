#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include <iostream>
#include <math.h>
#include "macierz.hh"
#include "wektor3D.hh"

class Macierz3D : public Macierz<double, 3>{
public:
    Macierz3D(Wektor3D& jeden, Wektor3D& dwa, Wektor3D& trzy){(*this)[0] = jeden; 
                                                            (*this)[1] = dwa;
                                                            (*this)[2] = trzy;}
};
#endif