#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main()
{
  UkladRownanLiniowych ukl;

  cin>>ukl;
  if(cin.fail()){
    cerr<<"Wczytywanie bledne!"<<endl;
    return BLAD;
  }
  ukl.obliczCramer();
  ukl.obliczWektorBledu();

  cout<<ukl;

  return 0;
}
