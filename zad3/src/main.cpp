#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main()
{
  UkladRownanLiniowych u;

  cin>>u;
  u.obliczCramer();
  cout<<u;

  return 0;
}
