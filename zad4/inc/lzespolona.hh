#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!

 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  

  LZespolona(){re = 0; im = 0;}
  LZespolona(double r, double i){re = r; im = i;}

  bool operator != (double Liczba);

  LZespolona &operator = (double  Liczba);

  /**
 * Dodaje do siebie dwie liczby zespolone
 * 
 * @param[in] Z2 - drugi skladnik dodawania
 * @return Liczba zespolona 
 */
  LZespolona  operator + (LZespolona  Z2) const;

  /**
 * Odejmune od siebie dwie liczby zespolone
 * 
 * @param[in] Z2 - liczba zespolona odejmujaca
 * @return Liczba zespolona
 */
  LZespolona operator - (LZespolona  Z2) const;

  /**
 * Mnozy przez siebie dwie liczby zespolone
 * 
 * @param[in] Z2 - drugi skladnik mnozenia
 * @return Liczba zespolona
 */
  LZespolona operator * (LZespolona  Z2) const;

  /**
 * Dzieli przez dwie liczby zespolone
 * 
 * @param[in] Z2 - drugi skladnik dzielenia
 * @return Liczba zespolona, iloraz skladnikow Skl1 oraz Skl2  
 */
LZespolona operator / (LZespolona Z2) const;

  /**
 * Sprzezenie liczby zespolonej
 */
  void Sprzezenie();

  /**
 * Oblicza modul liczby zespolonej
 * @return double modul liczby zespolonej  
 */
  double Modul ();

  
};
/**
 * Mnozu liczbe zespolona przez liczbe zmiennoprzecinkowa
 * 
 * @param[in] liczba - mnoznik
 * @param[in] Z - liczba lezspolona mnozona
 * @return bool, true jesli sa rowne, jesli nie false  
 */
LZespolona  operator * (float liczba, LZespolona  &Z);

/**
 * Mnozu liczbe zespolona przez liczbe zmiennoprzecinkowa
 * 
 * @param[in] Z - liczba lezspolona mnozona
 * @param[in] liczba - mnoznik
 * @return bool, true jesli sa rowne, jesli nie false  
 */
LZespolona  operator * (LZespolona  &Z, float liczba);

/**
 * Porownuje do siebie dwie liczby zespolone
 * 
 * @param[in] Arg1 - pierwszy skladnik porownania
 * @param[in] Arg2 - drugi skladnik porownania
 * @return bool, true jesli sa rowne, jesli nie false  
 */
bool operator == (LZespolona Arg1, LZespolona Arg2);

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac licze zespolona
 * 
 * @param[in] StrmWy - strumien wypisania
 * @param[in] Lz - liczba zespolona
 * @return Strumien do wypisania
 */
std::ostream& operator<<(std::ostream & StrmWy, const LZespolona& Lz);

/**
 * Pozwala operatorowi przesuniecia bitowego w lewo wczytywac liczbe zespolone
 * Liczba zespolona musi miec nastepujacy zapis (Re (+|-|*|/) Im'i')
 * 3 proby wpisania, nastepnie zwraca blad
 * Podczas kazdej nieprawidlowej proby zwraca blad na cerr
 * 
 * @param[in] StrmWe - strumien wczytywania
 * @param[in] Lz - liczba zespolona
 * @return Strumien do wczytania
 */
std::istream& operator>>(std::istream& StrmWe, LZespolona& Lz);

#endif