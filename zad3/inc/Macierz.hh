#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "typ.h"
#include "Wektor.hh"
#include <iostream>
#include <cassert>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  Wektor _kolumna[ROZMIAR];
  TYP wyznacznik = 1;
  
  public:
    Macierz(){for(Wektor& elem : _kolumna) elem = Wektor();}
    Macierz(const Macierz &m){for(int i = 0; i < ROZMIAR; i++) _kolumna[i] = m._kolumna[i];}
    const Wektor& operator[] (int unsigned kol) const {return _kolumna[kol];}
          Wektor& operator[] (int unsigned kol)       {return _kolumna[kol];}

    const TYP operator() (int unsigned wi, int unsigned ko) const {return _kolumna[ko](wi);}
         TYP& operator() (int unsigned wi, int unsigned ko)       {return _kolumna[ko](wi);}

    TYP WyznacznikMGaussa();
    void ZamianaKolumnyNaWektor(unsigned int kol, Wektor&  wektor);
};

std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
