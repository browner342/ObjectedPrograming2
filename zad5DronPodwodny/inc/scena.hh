#ifndef SCENA_HH
#define SCENA_HH
#include "woda.hh"
#include "dno.hh"
#include <string>
#include <fstream>
#include <cstdlib>

class Scena{
    /**
     * Pole zawierajace wskaznik na element graficzny dna.
     */
    Dno *dno;

    /**
     * Pole zawierajace wskaznik na element graficzny wody.
     */
    Woda *woda;

    /**
     * Pole zawierajace string utworzonej sceny.
     */
    std::string _napis = "";
public:
    /**
    * Konstruktor Sceny, tworzy scene o zakresach od zakresP do zakresZ,
    * ktore sa danymi punktami
    * 
    * @param[in] poczatek - wektorowy poczatek zakresu
    * @param[in] koniec - wektorowy koniec zakresu 
    */
    Scena(Wektor3D zakresP, Wektor3D zakresK){woda = new Woda(zakresP, zakresK);dno = new Dno(zakresP, zakresK);}
    
    /**
    * Destruktor sceny
    */
    ~Scena(){delete woda; delete dno;}

    /**
    * Funkcja generujuje wartosci dna oraz wody, po czym zwraca je do pliku
    * 
    * @param[in] nazwaPliku
    */
    bool generujSceneDoPliku(const char *nazwaPliku);

    /**
     * Funkcja zwracajaca napis sceny.
     * 
     * @return string.
     */
    std::string napis() const {return _napis;}
};

#endif