#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "wektor.hh"
#include "wektor3D.hh"
#include "macierz.hh"
#include "scena.hh"
#include <fstream>
#include <string>

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor3D wektorP = Wektor3D(0, 0, 0);
  Wektor3D wektorK = Wektor3D(70, 70, 70);
  char c;

  Scena *scena = new Scena(wektorP, wektorK);
  scena->generujSceneDoPliku("bryly/test.dat");
  
  
  Lacze.DodajNazwePliku("bryly/test.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  
  Lacze.UstawZakresX(wektorP(0), wektorK(0));
  Lacze.UstawZakresY(wektorP(1), wektorK(1));
  Lacze.UstawZakresZ(-90, 10);

  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  

  delete scena;
  cin >> noskipws >> c;
}
