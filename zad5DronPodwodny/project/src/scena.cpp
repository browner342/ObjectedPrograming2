#include "scena.hh"
std::string Scena::generujSceneDoPliku(){    
    std::ofstream Strm(DNOIWODA);
    if (Strm.fail()) std::cerr<<"Zapis Sceny do pliku się nie powiodl!"<<std::endl;
    
    _napis += (*this).woda->napis();
    _napis += "#\n\n";
    _napis += (*this).dno->napis();
    _napis += "#\n\n";

    Strm<<_napis;
    return _napis;
}