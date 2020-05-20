#include <woda.hh>

Woda::Woda(Wektor3D& poczatek, Wektor3D& koniec){
    Wektor3D tmp;
    for (int x = poczatek(0);  x <= koniec(0); x += KROK_SIATKI) {
        for (int y = poczatek(1);  y <= koniec(1); y += KROK_SIATKI) {
            if(x % 2 == 0){
                tmp = Wektor3D(x,y,WODA_MAX);
                _napis += tmp.napis();
            }
            else{
                tmp = Wektor3D(x,y,WODA_MIN);
                _napis += tmp.napis();
            }
        }
        _napis += "\n";
    }
}