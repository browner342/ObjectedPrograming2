#include "wektor.hh"
#include "lzespolona.hh"
#include "macierz.hh"
#include "rozmiar.h"
#include "uklrownan.hh"


using namespace std;

int main(){
    char typZnakow;
    cin >> typZnakow;

    if(typZnakow == 'r'){
        UkladRownanLiniowych<double, ROZMIAR> uk;
        Wektor<double, ROZMIAR> wek;
        cin>>uk;
        if(cin.fail()){
            cerr<<"Wczytywanie bledne!"<<endl;
            return BLAD;
        }
        uk.obliczCramer();
        
        cout<<uk;
        wek = uk.obliczWektorBledu();
        cout << "Wektor bledu: Ax-b = ("<< wek <<")"<<endl;
        cout << "Dlugosc wektora bledu: "<<wek.dlugoscWektora() << endl;
    }
    else if(typZnakow == 'z'){
        UkladRownanLiniowych<LZespolona, ROZMIAR> uk;
        Wektor<LZespolona, ROZMIAR> wek;
        cin>>uk;
        if(cin.fail()){
            cerr<<"Wczytywanie bledne!"<<endl;
            return BLAD;
        }
        uk.obliczCramer();

        cout<<uk;
        wek = uk.obliczWektorBledu();
        cout << "Wektor bledu: Ax-b = ("<< wek <<")"<<endl;
        cout << "Dlugosc wektora bledu: "<<wek.dlugoscWektora() << endl;
    }
    else{
        cerr<<"Wprowadzono niepoprawny format ukladu rownan!"<<endl;
        return BLAD;
    }
    return 0;
}