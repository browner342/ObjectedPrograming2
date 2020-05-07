#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include <math.h>



template <typename STyp, int SWymiar>
class Wektor {
    STyp  _wsp[SWymiar];
  public:
    Wektor() { for (STyp &wsp: _wsp) wsp = 0; }
  
    STyp  operator () (unsigned int i) const { return _wsp[i]; }
    STyp &operator () (unsigned int i)       { return _wsp[i]; }

      /**
     * Przeciążenie operatora dodawania pozwalające na dodawanie
     * do siebie dwóch wektorów.
     * 
     * @param[in] Wektor wek - wektor który ma zostać dodany.
     * @return Wektor, suma wektora z danej klasy oraz wektora wczytanego.
     */
    Wektor<STyp,SWymiar> operator + (const Wektor<STyp,SWymiar> &wek) const;
    Wektor<STyp,SWymiar> operator - (const Wektor<STyp,SWymiar> &odjemnik) const;
    Wektor<STyp,SWymiar> operator * (STyp mnoznik) const;

      /**
     * Przeciążenie operatora mnożenia pozwalające na mnozenie
     * wektora przez wektor. Jest to mnozenie sklarne.
     * 
     * @param[in] Wektor wek - wektor który ma zostać pomnozony.
     * @return TYP, wynikiem iloczynu skalarnego jest liczba.
     */
    STyp operator * (const Wektor<STyp,SWymiar> &wek) const;

     /**
     * Przeciazenie operatora dzielenia pozwalajace na dzielenie
     * wektora przez liczbe.
     * 
     * @param[in] TYP dzielnik, przez ktory ma zostac podzielony wektor.
     * @return Wektor, wynik dzielenia liczby przez wektor.
     */
    Wektor<STyp,SWymiar> operator / (STyp const &dzielnik) const;

    /**
     * Metoda oblicza dlugosc wektora bledu.
     * 
     * @return TYP - dlugosc wektora bledu.
     */
    STyp dlugoscWektora();
};

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator + (const Wektor<STyp,SWymiar> &wek) const{
    
    Wektor<STyp,SWymiar> wynik;
    
    for(int i = 0; i < SWymiar; i++){
        wynik(i) = _wsp[i] + wek(i);
    }
    return wynik;
}

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator - (const Wektor<STyp,SWymiar> &Odjemnik) const
{
  Wektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik(Ind) = (*this)(Ind) - Odjemnik(Ind);
  return Wynik;
}


template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator * (STyp Mnoznik) const
{
  Wektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik(Ind) = (*this)(Ind)*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
STyp Wektor<STyp,SWymiar>::operator * (const Wektor<STyp,SWymiar> &wek) const{
    STyp wynik;
    for(int i = 0; i < SWymiar; i++){
        wynik += _wsp[i] * wek(i);
    }
    return wynik;
}

template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator / (STyp const &dzielnik) const{

    Wektor<STyp,SWymiar> wynik;
  
    for(int i = 0; i < SWymiar; i++){
        wynik(i) = _wsp[i] / dzielnik;
    }
    return wynik;
}

template <typename STyp, int SWymiar>
STyp Wektor<STyp,SWymiar>:: dlugoscWektora(){
    STyp wynik;
    wynik = 0;

    for(STyp& elem : _wsp){
        wynik =wynik + elem * elem;
    }
    wynik = sqrt(wynik);

    return wynik;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, Wektor<STyp,SWymiar>& wek){
    STyp tmp[SWymiar];
    for(int i = 0; i < SWymiar; i++){
        strm>>tmp[i];

        if(strm.fail()){return strm;}
    }
    for(int i = 0; i < SWymiar; i++){wek(i) = tmp[i];}
    return strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strm, const Wektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; Ind++) {
    strm << " " << W(Ind);
  }  
  return strm;
}

#endif
