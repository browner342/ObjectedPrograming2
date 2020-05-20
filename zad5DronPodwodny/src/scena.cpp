#include "scena.hh"
bool Scena::generujSceneDoPliku(const char *nazwaPliku){    
    std::ofstream Strm(nazwaPliku);
    if (Strm.fail()) return false;
    
    _napis += (*this).woda->napis();
    _napis += "#\n\n";
    _napis += (*this).dno->napis();
    _napis += "#\n\n";

    Strm<<_napis;
    return true;
}