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
};

/**
 * Dodaje do siebie dwie liczby zespolone
 * 
 * @param[in] Skl1 - pierwszy skladnik dodawania
 * @param[in] Skl2 - drugi skladnik dodawania
 * @return Liczba zespolona, suma skladnikow Skl1 oraz Skl2  
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

/**
 * Odejmune od siebie dwie liczby zespolone
 * 
 * @param[in] Skl1 - liczba zespolona odejmowana
 * @param[in] Skl2 - liczba zespolona odejmujaca
 * @return Liczba zespolona, roznica skladnikow Skl1 i Skl2  
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

/**
 * Mnozy przez siebie dwie liczby zespolone
 * 
 * @param[in] Skl1 - pierwszy skladnik mnozenia
 * @param[in] Skl2 - drugi skladnik mnozenia
 * @return Liczba zespolona, iloczyn skladników Skl1 oraz Skl2  
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

/**
 * Dzieli przez dwie liczby zespolone
 * 
 * @param[in] Skl1 - pierwszy skladnik dzielenia
 * @param[in] Skl2 - drugi skladnik dzielenia
 * @return Liczba zespolona, iloraz skladnikow Skl1 oraz Skl2  
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

/**
 * Porownuje do siebie dwie liczby zespolone
 * 
 * @param[in] Arg1 - pierwszy skladnik porownania
 * @param[in] Arg2 - drugi skladnik porownania
 * @return bool, true jesli sa rowne, jesli nie false  
 */
bool operator == (LZespolona Arg1, LZespolona Arg2);

/**
 * Sprzezenie liczby zespolonej
 * 
 * @param[in] Lz - liczba zespolona, na ktorej wykonywane bedzie sprzezenie
 * @return Liczba zespolona po sprzezeniu 
 */
LZespolona  sprzeznie (LZespolona  Lz);

/**
 * Oblicza modul liczby zespolonej
 * 
 * @param[in] Lz - liczba zespolona, z ktorej oblicznay bedzie modul
 * @return double modul liczby zespolonej  
 */
double Modul (LZespolona Lz);

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac licze zespolona
 * 
 * @param[in] StrmWy - strumien wypisania
 * @param[in] Lz - liczba zespolona
 * @return Strumien do wypisania
 */
std::ostream& operator<<(std::ostream & StrmWy, LZespolona& Lz);

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
