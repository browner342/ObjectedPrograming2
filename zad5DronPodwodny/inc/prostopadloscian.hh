#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include <fstream>

#include "powierzchnia.hh"

class Prostopadloscian:public Powierzchnia{

public:
    /**
     * Kreator prostopadloscianu, podczas tworzenia pobiera dane
     * o nim z pliku przypisanym do stalej PROSTOPADLOSCIAN.
     */
    Prostopadloscian();
};
#endif