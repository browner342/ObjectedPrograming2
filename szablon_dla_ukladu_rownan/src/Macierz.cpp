#include "Macierz.hh"

Wektor Macierz::operator * (const Wektor& wek) const{
    Wektor tmp;
    Macierz mac(*this);

    for(int i = 0; i < ROZMIAR; i++){
        for(int j = 0; j < ROZMIAR; j++){
            tmp(i) += mac[j](i) * wek(j);
        }
    }
    return tmp;
}

TYP Macierz::WyznacznikMGaussa(){
    TYP dzielnik;
    TYP wyznacznik = 1;
    Macierz tmp(*this);

    for(int i = 0; i < ROZMIAR - 1; i++){
        for(int j = i + 1; j < ROZMIAR; j++){
            if(tmp[i](i) != 0){
                dzielnik = tmp[j](i) / tmp[i](i);
                tmp[j] = tmp[j] - tmp[i] * dzielnik;
            }
        }
    }
    for(int i = 0; i < ROZMIAR; i++) wyznacznik *= tmp[i](i);

    return wyznacznik;
}

void Macierz::ZamianaKolumnyNaWektor(unsigned int kol, Wektor& wektor){
    assert(kol < ROZMIAR);
    
    _kolumna[kol] = wektor;
}

std::istream& operator >> (std::istream &strm, Macierz &mac){
    for(int i = 0; i < ROZMIAR; i++){
        strm >> mac[i];

        if(strm.fail()){return strm;}
    }
    return strm;
}

std::ostream& operator << (std::ostream &strm, const Macierz &mac){
    for(int i = 0; i < ROZMIAR; i++){
        strm << mac[i];
        strm << std::endl;
    }
    
    return strm;
}