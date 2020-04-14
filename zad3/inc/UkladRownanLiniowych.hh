#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <iomanip>
#include <cassert>
#include "Macierz.hh"
#include "Wektor.hh"

#define WYRAZWOLNY 11
#define ROZWIAZANIE 22
#define MACIERZ 33
#define BLAD -1



class UkladRownanLiniowych {
  Wektor wyrazWolny, rozwiazanie;
  Macierz macierz;

  public:
  UkladRownanLiniowych(){macierz = Macierz(); wyrazWolny = Wektor(); rozwiazanie = Wektor();}
  const Wektor& operator[] (int unsigned wek) const {return wek == WYRAZWOLNY?wyrazWolny:rozwiazanie;}
        Wektor& operator[] (int unsigned wek)       {return wek == WYRAZWOLNY?wyrazWolny:rozwiazanie;}
  
  const Macierz operator() (int unsigned mac) const {return macierz;}
       Macierz& operator() (int unsigned mac)       {return macierz;}

  Wektor& obliczCramer();

};

std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &uklRown);
std::ostream& operator << ( std::ostream                  &strm, 
                            const UkladRownanLiniowych    &uklRown
                          );


#endif
