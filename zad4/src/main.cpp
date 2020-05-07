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
        
        cout<<uk;
    }
    else if(typZnakow == 'z'){
        UkladRownanLiniowych<LZespolona, ROZMIAR> uk;
        Wektor<LZespolona, ROZMIAR> wek;
        cin>>uk;
        if(cin.fail()){
            cerr<<"Wczytywanie bledne!"<<endl;
            return BLAD;
        }

        cout<<uk;
    }
    else{
        cerr<<"Wprowadzono niepoprawny format ukladu rownan!"<<endl;
        return BLAD;
    }
    return 0;
}