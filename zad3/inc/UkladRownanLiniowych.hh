#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "Macierz.hh"
#include "Wektor.hh"
#include "uklconst.h"
#include "blad.h"

/**
 * Plik zawiera definicje klasy UkladRownanLinowych, metod tej klasy,
 * oraz przeciazenia operatorow, rowniez dotyczacych ukladu rownan liniowych. 
 */
class UkladRownanLiniowych {
  Wektor wyrazWolny;    /*! Pole reprezentujace wektor wyrazu wolnego.*/ 
  Wektor rozwiazanie;   /*! Pole reprezentujace wektor rozwiazania.*/ 
  Wektor wekBlad;
  Macierz macierz;      /*! Pole reprezentujace macierz.*/

  public:
  
  /**
    * Konstruktor Wektor, tworzy macierz , oraz dwa wektory rozwiazania i wyrazu wolnego.
    */
  UkladRownanLiniowych(){macierz = Macierz(); wyrazWolny = Wektor(); rozwiazanie = Wektor();}
  
  /**
   * Przeciążenie operatora pozwalające na czytanie wartosci wektorow wyrazu wolnego i rozwiazania.
   * 
   * @return Wektor
   */
  const Wektor& operator[] (int unsigned wek) const {return wek == WYRAZWOLNY?wyrazWolny: wek == ROZWIAZANIE ? rozwiazanie : wekBlad;}

  /**
   * Przeciążenie operatora pozwalające na edycje wartosci wektorow wyrazu wolnego i rozwiazania.
   * 
   * @return Wektor
   */
        Wektor& operator[] (int unsigned wek)       {return wek == WYRAZWOLNY?wyrazWolny: wek == ROZWIAZANIE ? rozwiazanie : wekBlad;}
  
  /**
   * Przeciążenie operatora pozwalające na czytanie wartosci macierzy.
   * 
   * @return Macierz
   */
  const Macierz operator() (int unsigned mac) const {return macierz;}

  /**
   * Przeciążenie operatora pozwalające na edycje wartosci macierzy.
   * 
   * @return Macierz
   */
       Macierz& operator() (int unsigned mac)       {return macierz;}

  /**
   * Metoda oblicza rozwiazanie zgodnie z metoda wyznacznikow Cramer'a.
   * Dziala na kopiach nie ingerujac w macierz. Jezeli wyznacznik macierzy
   * podstawowej jest rowny 0 assert zwaca blad. Wynik zapisuje do wektora
   * roziazanie.
   * 
   * @return Wektor - jest to wektor rozwiazania.
   */
  Wektor& obliczCramer();

  /**
   * Metoda oblicza wektor bledu podczas uzywania metody.
   * 
   * @return Wektor - jest to wektor bledu.
   */
  Wektor& obliczWektorBledu();

  /**
   * Metoda oblicza dlugosc wektora bledu.
   * 
   * @return TYP - dlugosc wektora bledu.
   */
  TYP dlWektoraBl() const; 

};

/**
 * Pozwala operatorowi przesuniecia bitowego w lewo wczytywac Uklad rownan.
 * Akcjeptuje jedynie format zgodny z wczytywaniem formatu Macierz a nastepnie Wektor.
 * W przypadku niepoprawności zwraca bład. 
 * Calosc wczytywana w postaci transponowanej.
 * 
 * @param[in] strm - strumien wczytywania
 * @param[in] mac - macierz wczytywana
 * @return Strumien do wczytania
 */
std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &uklRown);

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac uklad rownan.
 * 
 * @param[in] strm - strumien wypisania
 * @param[in] uklRown - uklad rownan do wypisania
 * @return Strumien do wypisania
 */
std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych &uklRown);


#endif
