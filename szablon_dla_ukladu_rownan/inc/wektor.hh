#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _wsp[SWymiar];
  public:
    SWektor() { for (STyp &wsp: _wsp) wsp = 0; }
  
    STyp  operator () (unsigned int i) const { return _wsp[i]; }
    STyp &operator () (unsigned int i)       { return _wsp[i]; }

      /**
     * Przeciążenie operatora dodawania pozwalające na dodawanie
     * do siebie dwóch wektorów.
     * 
     * @param[in] Wektor wek - wektor który ma zostać dodany.
     * @return Wektor, suma wektora z danej klasy oraz wektora wczytanego.
     */
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &wek) const;
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double mnoznik) const;

      /**
     * Przeciążenie operatora mnożenia pozwalające na mnozenie
     * wektora przez wektor. Jest to mnozenie sklarne.
     * 
     * @param[in] Wektor wek - wektor który ma zostać pomnozony.
     * @return TYP, wynikiem iloczynu skalarnego jest liczba.
     */
    STyp operator * (const SWektor<STyp,SWymiar> &wek) const;

     /**
     * Przeciazenie operatora dzielenia pozwalajace na dzielenie
     * wektora przez liczbe.
     * 
     * @param[in] TYP dzielnik, przez ktory ma zostac podzielony wektor.
     * @return Wektor, wynik dzielenia liczby przez wektor.
     */
    SWektor<STyp,SWymiar> operator / (STyp const &dzielnik) const;

    /**
     * Metoda oblicza dlugosc wektora bledu.
     * 
     * @return TYP - dlugosc wektora bledu.
     */
    STyp dlugoscWektora();
};

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &wek) const{
    
    SWektor<STyp,SWymiar> wynik;
    
    for(int i = 0; i < SWymiar; i++){
        wynik(i) = _wsp[i] + wek(i);
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik(Ind) = (*this)(Ind) - Odjemnik(Ind);
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik(Ind) = (*this)(Ind)*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &wek) const{
    STyp wynik;
    for(int i = 0; i < SWymiar; i++){
        wynik += _wsp[i] * wek(i);
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp const &dzielnik) const{

    SWektor<STyp,SWymiar> wynik;
  
    for(int i = 0; i < SWymiar; i++){
        wynik(i) = _wsp[i] / dzielnik;
    }
    return wynik;
}

template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::dlugoscWektora(){
    STyp wynik = 0;

    for(STyp& elem : _wsp){
        wynik += elem * elem;
    }
    wynik = sqrt(wynik);

    return wynik;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strm, SWektor<STyp,SWymiar>& wek){
    STyp tmp[SWymiar];
    for(int i = 0; i < SWymiar; i++){
        strm>>tmp[i];

        if(strm.fail()){return strm;}
    }
    for(int i = 0; i < SWymiar; i++){wek(i) = tmp[i];}
    return strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strm, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    strm << " " << W(Ind);
  }  
  return strm;
}

#endif
