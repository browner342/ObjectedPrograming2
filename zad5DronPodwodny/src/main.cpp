#include <iostream>
#include <iomanip>
#include <cmath>
#include "lacze_do_gnuplota.hh"
#include "wektor.hh"
#include "wektor3D.hh"
//#include "macierz3D.hh"
#include "macierz.hh"
#include "scena.hh"
#include "dron.hh"
#include "menu.hh"
#include <fstream>
#include <string>

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  //Wektor3D wektorP = Wektor3D(-50, -50, 0);
  //Wektor3D wektorK = Wektor3D(70, 70, 70);
  char c;

  //Scena *scena = new Scena(wektorP, wektorK);
  //Dron *x = new Dron();

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  otworzMenu(Lacze);

  //delete scena;
  //delete x;
  //cout<<"Aktualna ilosc obiektow Wektor3D> "<<wektorK.ileTeraz()<<endl;
  //cout<<"Laczna ilosc obiektow> "<<wektorK.ileWszystkie()<<endl<<endl;
  cin >> noskipws >> c;
}
