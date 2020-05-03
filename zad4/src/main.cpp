#include "wektor.hh"
#include "lzespolona.hh"
#include "macierz.hh"
#include "rozmiar.h"
#include "uklrownan.hh"

using namespace std;

int main(){
    /*
    LZespolona lz;
    Wektor<LZespolona, 2> wek;
    cin >> wek;   
    cin >> lz;

    cout << wek * lz;

    *//*
    Macierz<double, 5> mac;
    cin >> mac;
    cout << mac.WyznacznikMGaussa();
    */
   UkladRownanLiniowych<double, 3> uk;
    cin>>uk;
    uk.obliczCramer();
    cout<<uk;
    return 0;
}