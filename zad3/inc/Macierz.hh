#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "typ.h"
#include "Wektor.hh"
#include <iostream>
#include <cassert>


/**
 * Plik zawiera definicje klasy Macierz, metod tej klasy,
 * oraz przeciazenia operatorow, rowniez dotyczacych macierzy. 
 */
class Macierz {
  Wektor _kolumna[ROZMIAR];     /*! Pole reprezentujace kolumny macierzy.*/
  TYP wyznacznik = 1;           /*! Pole reprezentujace wyznacznik macierzy, wartosc domyslna to 1.*/
  
  public:
    /**
    * Konstruktor Macierzy, tworzy macierz na podstawie konstruktora Wektora 
    */
    Macierz(){for(Wektor& elem : _kolumna) elem = Wektor();}

    /**
    * Konstruktor kopiujący Macierzy, tworzy macierz na podstawie innego już istniejącego wektora 
    */
    Macierz(const Macierz &m){for(int i = 0; i < ROZMIAR; i++) _kolumna[i] = m._kolumna[i];}

    /**
     * Przeciążenie operatora pozwalające na czytanie wartosci
     * kolumn.
     * 
     * @return Wektor
     */
    const Wektor& operator[] (int unsigned kol) const {return _kolumna[kol];}

    /**
     * Przeciążenie operatora pozwalające na zmienianie wartosci
     * kolumn.
     * 
     * @return Wektor
     */
          Wektor& operator[] (int unsigned kol)       {return _kolumna[kol];}

    /**
     * Przeciążenie operatora pozwalające na czytanie wartosci
     * wspolczynnikow kolumn macierzy.
     * 
     * @return TYP ,wspolczynnik kolumny
     */
    const TYP operator() (int unsigned wi, int unsigned ko) const {return _kolumna[ko](wi);}

    /**
     * Przeciążenie operatora pozwalające na zmiane wartosci
     * wspolczynnikow kolumn macierzy.
     * 
     * @return TYP ,wspolczynnik kolumny
     */
         TYP& operator() (int unsigned wi, int unsigned ko)       {return _kolumna[ko](wi);}

    /**
     * Metoda pozwalająca wyliczenie wyznacznika macierzy
     * metoda Gaussa. Program korzysta z kopii macierzy nie wplywajac na jej wyglad,
     * jednak zapisuje wynik w polu wyznacznik.
     * 
     * @return TYP ,wyznacznik.
     */
    TYP WyznacznikMGaussa();

    /**
     * Metoda zamienia kolumne w macierzy na dany wektor.
     * Podana wartosc kolumny, nie moze byc wieksza niz ROZMIAR macierzy.
     * 
     * @param[in] kol - bez znakowa przedstawiajaca kolumne.
     * @param[in] wektor - wektor na ktory ma zostac zamieniona kolumna.
     */
    void ZamianaKolumnyNaWektor(unsigned int kol, Wektor&  wektor);
};

/**
 * Pozwala operatorowi przesuniecia bitowego w lewo wczytywac Macierz.
 * Akcjeptuje jedynie format zgodny z wczytywaniem formatu Wektor.
 * W przypadku niepoprawności zwraca bład. wczytuje macierz 
 * w postaci transponowanej.
 * 
 * @param[in] strm - strumien wczytywania
 * @param[in] mac - macierz wczytywana
 * @return Strumien do wczytania
 */
std::istream& operator >> (std::istream &strm, Macierz &mac);

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac wektor.
 * 
 * @param[in] strm - strumien wypisania
 * @param[in] mac - macierz wczytywana
 * @return Strumien do wypisania
 */
std::ostream& operator << (std::ostream &strm, const Macierz &mac);


#endif
