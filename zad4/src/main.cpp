#include <type_traits>
#include "wektor.hh"
#include "lzespolona.hh"
#include "macierz.hh"
#include "rozmiar.h"
#include "uklrownan.hh"
#include "uklconst.h"

using namespace std;
int main(){
    char typZnakow;
    cin>>typZnakow;
    if(typZnakow == 'r'){
        UkladRownanLiniowych<double, ROZMIAR> uk;
        cin>>uk;
        uk.obliczCramer();
        cout<<uk;
        cout << "Wektor bledu: Ax-b = ("<< uk.obliczWektorBledu()<<")"<<endl;
    }
    else if(typZnakow == 'z'){
        UkladRownanLiniowych<LZespolona, ROZMIAR> uk;
        cin>>uk;
        uk.obliczCramer();
        cout<<uk;
        cout << "Wektor bledu: Ax-b = ("<< uk.obliczWektorBledu()<<")"<<endl;
        //cout<<uk[WYRAZWOLNY].dlugoscWektora();
    }
    else{
        cerr<<"Wprowadzono niepoprawny format ukladu rownan!"<<endl;
        return -1;
    }
    return 0;
}