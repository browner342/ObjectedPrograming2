#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main()
{
  UkladRownanLiniowych ukl;
  Wektor wekBledu;
  TYP dlBledu;

  cin >> ukl;
  if(cin.fail()){
    cerr<<"Wczytywanie bledne!"<<endl;
    return BLAD;
  }
  ukl.obliczCramer();
  cout << ukl;

  wekBledu = ukl.obliczWektorBledu();
  dlBledu = wekBledu.dlugoscWektora();

  cout << "Wektor bledu:   Ax-b  = " <<wekBledu << endl;
  cout << "Dlugosc wektora bledu: ||Ax-b|| = " <<dlBledu << endl;
  return 0;
}
