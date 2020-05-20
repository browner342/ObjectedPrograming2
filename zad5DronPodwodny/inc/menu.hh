#ifndef MENU_HH
#define MENU_HH

#include <fstream>
#include <string>
#include "dron.hh"
#include "scena.hh"
#include "wektor3D.hh"
#include "lacze_do_gnuplota.hh"

void wypiszOpcje();
void otworzMenu(Dron& dron);
//void polaczPliki(){}
void obslugaGNUplota(const Wektor3D& wektorP, const Wektor3D& wektorK);


#endif