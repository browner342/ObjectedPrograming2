#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include "typ.h"
#include <iostream>
#include <cmath>


/**
 * Plik zawiera definicje klasy Wektor, metod tej klasy,
 * oraz przeciazenia operatorow, rowniez dotyczacych wektora. 
 */
//dopisac oblicznie dlugosci wektora
class Wektor {
  TYP _wsp[ROZMIAR];    /*! Pole reprezentuje tablice wspolczynnikow wektora*/

  public:
  /**
   * Konstruktor Wektora, tworzy wektor o wszystkich wspolcznynnikach 0 
   */
  Wektor(){for(TYP& elem : _wsp) elem = 0;}
  
  Wektor(const Wektor &wek){for(int i = 0; i < ROZMIAR; i++) _wsp[i] = wek._wsp[i];}
  /**
   * Przeciążenie operatora pozwalające na odczytywanie wartosci
   * wspolczynnikow wektora.
   * 
   * @return TYP ,wspolczynnik wektora
   */
  TYP operator () (unsigned int i) const {return _wsp[i];}

  /**
   * Przeciążenie operatora pozwalające na zmienianie wartosci
   * wspolczynnikow wektora.
   * 
   * @return TYP ,wspolczynnik wektora
   */
  TYP& operator () (unsigned int i)      {return _wsp[i];}

  /**
   * Przeciążenie operatora dodawania pozwalające na dodawanie
   * do siebie dwóch wektorów.
   * 
   * @param[in] Wektor wek - wektor który ma zostać dodany.
   * @return Wektor, suma wektora z danej klasy oraz wektora wczytanego.
   */
  Wektor operator + (Wektor const &wek) const;

  /**
   * Przeciążenie operatora odejmowania pozwalające na odejmowanie
   * od siebie dwóch wektorów.
   * 
   * @param[in] Wektor wek - wektor który ma zostać odjety.
   * @return Wektor, róznica wektora z danej klasy oraz wektora wczytanego.
   */
  Wektor operator - (Wektor const &wek) const;

  /**
   * Przeciążenie operatora mnożenia pozwalające na mnozenie
   * wektora przez wektor. Jest to mnozenie sklarne.
   * 
   * @param[in] Wektor wek - wektor który ma zostać pomnozony.
   * @return TYP, wynikiem iloczynu skalarnego jest liczba.
   */
  TYP operator * (Wektor const &wek) const;

  /**
   * Przeciazenie operatora mnozenia pozwalajace na mnozenie
   * wektora przez liczbe.
   * 
   * @param[in] TYP mnoznik, przez ktory ma zostac pomnozony wektor.
   * @return Wektor, wynik mnozenia liczby przez wektor.
   */
  Wektor operator * (TYP const &mnoznik) const;

  /**
   * Przeciazenie operatora dzielenia pozwalajace na dzielenie
   * wektora przez liczbe.
   * 
   * @param[in] TYP dzielnik, przez ktory ma zostac podzielony wektor.
   * @return Wektor, wynik dzielenia liczby przez wektor.
   */
  Wektor operator / (TYP const &dzielnik) const;

   /**
   * Metoda oblicza dlugosc wektora bledu.
   * 
   * @return TYP - dlugosc wektora bledu.
   */
  TYP dlugoscWektora();
};


/**
 * Pozwala operatorowi przesuniecia bitowego w lewo wczytywac Wektor.
 * Akcjeptuje jedynie format zgodny z TYP, jak również cyfry wczytywane należy
 * odzielać spacją. W przypadku niepoprawności zwraca bład/
 * 
 * @param[in] strm - strumien wczytywania
 * @param[in] wek - wektor
 * @return Strumien do wczytania
 */
std::istream& operator >> (std::istream &strm, Wektor &wek);

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac wektor.
 * 
 * @param[in] strm - strumien wypisania
 * @param[in] wek - wektor
 * @return Strumien do wypisania
 */
std::ostream& operator << (std::ostream &strm, const Wektor &wek);

/**
 * Przeciazenie operatora mnozenia pozwalajace na mnozenie
 * wektora przez liczbe.
 * 
 * @param[in] TYP mnoznik, przez ktory ma zostac pomnozony wektor.
 * @param[in] Wektor wek - wektor, który ma zostac pomnozony przez liczbe.
 * @return Wektor, wynik mnozenia liczby przez wektor.
 */
Wektor operator * (TYP const &mnoznik, Wektor const &wek);
#endif
