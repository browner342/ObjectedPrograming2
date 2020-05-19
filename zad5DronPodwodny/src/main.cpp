#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "wektor.hh"
#include "wektor3D.hh"
#include "macierz.hh"
#include <fstream>

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor3D wek[4];
  fstream plik;
  char c;
  /*
  plik.open("bryly/test.dat", ios::out);
  for(Wektor3D& elem:wek){
    cin>>elem;
    if(!cin.fail()){plik << elem << endl;}
  }
  plik.close();*/
  
  
  Lacze.DodajNazwePliku("bryly/prostopadloscian1.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-40, 100);
  Lacze.UstawZakresY(-90, 90);
  Lacze.UstawZakresZ(-20, 90);

  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  
  cin >> noskipws >> c;
  cin >> noskipws >> c;
}
