#include <scena.hh>
bool Scena::generujSceneDoPliku(const char *nazwaPliku){
    //generowanie wartosci wektorow wody oraz dna
    Woda w = Woda(zakresP, zakresK);
    Dno d = Dno(zakresP, zakresK);

    std::ofstream Strm(nazwaPliku);
    if (Strm.fail()) return false;

    _napis += w.napis();
    _napis += "#\n\n";
    _napis += d.napis();

    Strm<<_napis;

    return true;
}