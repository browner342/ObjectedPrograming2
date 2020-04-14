#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include "typ.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  TYP _wsp[ROZMIAR];

  public:
  Wektor(){for(TYP& elem : _wsp) elem = 0;}
  TYP operator () (unsigned int i) const {return _wsp[i];}
  TYP& operator () (unsigned int i)      {return _wsp[i];}

  Wektor operator + (Wektor const &wek);
  Wektor operator - (Wektor const &wek);
  TYP operator * (Wektor const &wek);
  Wektor operator * (TYP const &mnoznik);
  Wektor operator / (TYP const &dzielnik);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, Wektor &wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const Wektor &wek);

Wektor operator * (TYP const &mnoznik, Wektor const &wek);
#endif
