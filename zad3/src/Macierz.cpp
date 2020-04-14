#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
TYP Macierz::WyznacznikMGaussa(){
    TYP dzielnik;
    wyznacznik = 1;
    Macierz tmp(*this);
    for(int i = 0; i < ROZMIAR - 1; i++){
        for(int j = i + 1; j < ROZMIAR; j++){
            dzielnik = tmp[j](i) / tmp[i](i);
            tmp[j] = tmp[j] - tmp[i] * dzielnik;
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