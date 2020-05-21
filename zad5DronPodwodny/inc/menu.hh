#ifndef MENU_HH
#define MENU_HH

#include <fstream>
#include <string>
#include <unistd.h>
#include <time.h>
#include "dron.hh"
#include "scena.hh"
#include "wektor3D.hh"
#include "lacze_do_gnuplota.hh"

void wypiszOpcje();
bool otworzMenu(PzG::LaczeDoGNUPlota  Lacze);
void generujPlikGNU(const Dron& dron, const Scena& scena);
void obslugaGNUplota(const Wektor3D& wektorP, const Wektor3D& wektorK, PzG::LaczeDoGNUPlota  Lacze);


#endif