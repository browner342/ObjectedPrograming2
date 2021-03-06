#ifndef UKLROWNAN_HH
#define UKLROWNAN_HH

#include <iostream>
#include <iomanip>
#include <cassert>
#include "macierz.hh"
#include "wektor.hh"
#include "uklconst.h"
#include "blad.h"

/**
 * Plik zawiera definicje klasy UkladRownanLinowych, metod tej klasy,
 * oraz przeciazenia operatorow, rowniez dotyczacych ukladu rownan liniowych. 
 */
template <typename STyp, int SWymiar>
class UkladRownanLiniowych {
  Wektor<STyp,SWymiar> wyrazWolny;    /*! Pole reprezentujace wektor wyrazu wolnego.*/ 
  Macierz<STyp,SWymiar> macierz;      /*! Pole reprezentujace macierz.*/

  public:
  
  /**
    * Konstruktor Wektor, tworzy macierz , oraz dwa wektory rozwiazania i wyrazu wolnego.
    */
  UkladRownanLiniowych(){macierz = Macierz<STyp,SWymiar>(); wyrazWolny = Wektor<STyp,SWymiar>();}
  
  /**
   * Przeciążenie operatora pozwalające na czytanie wartosci wektorow wyrazu wolnego i rozwiazania.
   * 
   * @return Wektor
   */
  const Wektor<STyp,SWymiar>& operator[] (int unsigned wek) const {return wyrazWolny;}

  /**
   * Przeciążenie operatora pozwalające na edycje wartosci wektorow wyrazu wolnego i rozwiazania.
   * 
   * @return Wektor
   */
        Wektor<STyp,SWymiar>& operator[] (int unsigned wek)       {return wyrazWolny;}
  
  /**
   * Przeciążenie operatora pozwalające na czytanie wartosci macierzy.
   * 
   * @return Macierz
   */
  const Macierz<STyp,SWymiar> operator() (int unsigned mac) const {return macierz;}

  /**
   * Przeciążenie operatora pozwalające na edycje wartosci macierzy.
   * 
   * @return Macierz
   */
       Macierz<STyp,SWymiar>& operator() (int unsigned mac)       {return macierz;}

  /**
   * Metoda oblicza rozwiazanie zgodnie z metoda wyznacznikow Cramer'a.
   * Dziala na kopiach nie ingerujac w macierz. Jezeli wyznacznik macierzy
   * podstawowej jest rowny 0 assert zwaca blad. Wynik zapisuje do wektora
   * roziazanie.
   * 
   * @return Wektor - jest to wektor rozwiazania.
   */
  Wektor<STyp,SWymiar> obliczCramer()const{  
    Macierz<STyp,SWymiar> tmp[SWymiar];
    Macierz<STyp,SWymiar> mac(macierz);
    Wektor<STyp, SWymiar> wynik;
    Wektor<STyp, SWymiar> wolny(wyrazWolny);
    STyp wyznacznik = mac.WyznacznikMGaussa();

    assert(wyznacznik != 0);

    for(int i = 0; i < SWymiar; i++){//tworzy kopie macierzy po czym oblicza na nich wyznaczniki zgodnie z metoda Cramera
        tmp[i] = mac;
        tmp[i].ZamianaKolumnyNaWektor(i, wolny);
        wynik(i) = tmp[i].WyznacznikMGaussa() / wyznacznik;

    }

    return wynik;
}

  /**
   * Metoda oblicza wektor bledu podczas uzywania metody.
   * 
   * @return Wektor - jest to wektor bledu.
   */
  Wektor<STyp,SWymiar> obliczWektorBledu(Wektor<STyp,SWymiar> roz)const{
    Wektor<STyp,SWymiar> wekBlad;
    Macierz<STyp,SWymiar> mac(macierz);
    //Wektor<STyp,SWymiar> roz(rozwiazanie);
    wekBlad = mac * roz - wyrazWolny;

    return wekBlad;
  }
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
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, UkladRownanLiniowych<STyp,SWymiar> &uklRown){
  strm >> uklRown(MACIERZ);
  if(strm.fail()){return strm;}
  strm >> uklRown[WYRAZWOLNY];
  return strm;
}


/*
template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych<STyp,SWymiar> &uklRown){
    for(int wi = 0; wi < SWymiar; wi++){
        strm <<"| ";
        for(int kol = 0; kol < SWymiar; kol++){strm << std::right<< std::setw(6) << std::setprecision(2) << uklRown(MACIERZ)[kol](wi) << ' ';}
        strm << "| | ";
        strm <<std::right<< std::setw(6) << std::setprecision(2) <<uklRown[ROZWIAZANIE](wi);
        strm << " | ";
        wi == (SWymiar/2) ? strm << '=' : strm << ' ';
        strm << " | ";
        strm << std::right<< std::setw(6) << std::setprecision(2) << uklRown[WYRAZWOLNY](wi);
        strm << " |" << std::endl;
    }
 
    return strm;
}*/
/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac uklad rownan.
 * 
 * @param[in] strm - strumien wypisania
 * @param[in] uklRown - uklad rownan do wypisania
 * @return Strumien do wypisania
 */
template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych<STyp,SWymiar> &uklRown){
  Wektor<STyp, SWymiar> wek; 
  Wektor<STyp, SWymiar> rozwiazanie;

  rozwiazanie = uklRown.obliczCramer();
  wek = uklRown.obliczWektorBledu(rozwiazanie);

  strm << "Macierz A^T:" << std::endl;
  strm << uklRown(MACIERZ) << std::endl;
  strm<< "Wektor wyrazow wolnych b:"<<std::endl;
  strm << uklRown[WYRAZWOLNY] << std::endl << std::endl;
  strm << "Rozwiazanie:";
  for(int i = 0; i < SWymiar; i++){strm<<" x"<<i+1;}
  strm << std::endl;
  strm << std::setprecision(3) << rozwiazanie << std::endl<<std::endl;

  
  strm << "Wektor bledu: Ax-b = ("<< wek <<")" << std::endl;
  strm << "Dlugosc wektora bledu: "<<wek.dlugoscWektora() << std::endl;
  return strm;
}


#endif