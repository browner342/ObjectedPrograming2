#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "wektor.hh"
#include "wektor3D.hh"
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
  Wektor3D wektorP = Wektor3D(0, 0, 0);
  Wektor3D wektorK = Wektor3D(70, 70, 70);
  char c;
  string wszystko = "";
  std::ofstream Strm("bryly/powierzchnie.dat");

  Scena *scena = new Scena(wektorP, wektorK);
  scena->generujSceneDoPliku("bryly/powierzchnie.dat");

  Dron *x = new Dron();

  //otworzMenu(*x);
  
  obslugaGNUplota(wektorP, wektorK);

  delete scena;
  delete x;
  cout<<wektorK.ileTeraz();
  cin >> noskipws >> c;
}
