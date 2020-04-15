#include "Wektor.hh"

Wektor Wektor::operator + (Wektor const &wek){
    Wektor wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik(i) = this->_wsp[i] + wek(i);
    }
    return wynik;
}

Wektor Wektor::operator - (Wektor const &wek){
    Wektor wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik(i) = this->_wsp[i] - wek(i);
    }
    return wynik;
}

TYP Wektor::operator * (Wektor const &wek){
    TYP wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik += this->_wsp[i] * wek(i);
    }
    return wynik;
}

Wektor Wektor::operator * (TYP const &mnoznik){
    Wektor wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik(i) = mnoznik * this->_wsp[i];
    }
    return wynik;
}

Wektor Wektor::operator / (TYP const &dzielnik){
    Wektor wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik(i) = this->_wsp[i] / dzielnik;
    }
    return wynik;
}

/*********************************************************/

std::istream& operator >> (std::istream &strm, Wektor &wek){
    TYP tmp[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        strm>>tmp[i];

        if(strm.fail()){return strm;}
    }
    for(int i = 0; i < ROZMIAR; i++){wek(i) = tmp[i];}
    return strm;
}

std::ostream& operator << (std::ostream &strm, const Wektor &wek){
    for(int i = 0; i < ROZMIAR; i++){
        strm << wek(i)<<' ';
    }
    return strm;
}

Wektor operator * (TYP const &mnoznik, Wektor const &wek){
    Wektor wynik;
    for(int i = 0; i < ROZMIAR; i++){
        wynik(i) = mnoznik * wek(i);
    }
    return wynik;
}
