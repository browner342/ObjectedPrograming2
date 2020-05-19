#include <woda.hh>

Woda::Woda(Wektor3D poczatek, Wektor3D koniec){
    for (int x = poczatek(0);  x < koniec(0); x += KROK_SIATKI) {
        for (int y = poczatek(1);  y < koniec(1); y += KROK_SIATKI) {
            if(x % 2 == 0){wartosci.push_back(Wektor3D(x,y,WODA_MAX));}
            else          {wartosci.push_back(Wektor3D(x,y,WODA_MIN));}
        }
    }
}