#include "UkladRownanLiniowych.hh"

Wektor& UkladRownanLiniowych::obliczCramer(){  
    Macierz tmp[ROZMIAR];
    TYP wyznacznik = macierz.WyznacznikMGaussa();

    assert(wyznacznik != 0);

    for(int i = 0; i < ROZMIAR; i++){//tworzy kopie macierzy po czym oblicza na nich wyznaczniki zgodnie z metoda Cramera
        tmp[i] = macierz;
        tmp[i].ZamianaKolumnyNaWektor(i, wyrazWolny);
        rozwiazanie(i) = tmp[i].WyznacznikMGaussa() / wyznacznik;
    }

    return rozwiazanie;
}

std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &uklRown){
    strm >> uklRown(MACIERZ);
    if(strm.fail()){return strm;}
    strm >> uklRown[WYRAZWOLNY];
    return strm;
}
/*
std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych &uklRown){
    strm << uklRown(MACIERZ);
    strm << uklRown[WYRAZWOLNY] << std::endl; 
    strm << uklRown[ROZWIAZANIE] << std::endl;
    return strm;
}
*/

std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych &uklRown){
    for(int wi = 0; wi < ROZMIAR; wi++){
        strm <<"| ";
        for(int kol = 0; kol < ROZMIAR; kol++){strm << std::right<< std::setw(6) << std::setprecision(2) << uklRown(MACIERZ)[kol](wi) << ' ';}
        strm << "| | ";
        strm <<std::right<< std::setw(6) << std::setprecision(2) <<uklRown[ROZWIAZANIE](wi);
        strm << " | ";
        wi == (ROZMIAR/2) ? strm << '=' : strm << ' ';
        strm << " | ";
        strm << std::right<< std::setw(6) << std::setprecision(2) << uklRown[WYRAZWOLNY](wi);
        strm << " |" << std::endl;
    }
    return strm;
}
