#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "wektor.hh"
#include "wektor3D.hh"
#include "macierz.hh"
#include "scena.hh"
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
  cin>>wek[0];
  cin>>wek[1];
  Scena scena = Scena(wek[0], wek[1]);
  scena.generujSceneDoPliku("bryly/test.dat");
  
  Lacze.DodajNazwePliku("bryly/test.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 100);
  Lacze.UstawZakresY(0, 90);
  Lacze.UstawZakresZ(-90, 10);

  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  
  cin >> noskipws >> c;
  cin >> noskipws >> c;
}
