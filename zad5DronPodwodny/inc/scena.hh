#ifndef SCENA_HH
#define SCENA_HH
#include <woda.hh>
#include <dno.hh>
#include <string>
#include <fstream>
#include <cstdlib>

class Scena{
    /**
    * Trzyma wartosci zakresu poczatkowego sceny
    */
    Wektor3D zakresP;
    /**
    * Trzyma wartosci zakresu koncowego sceny
    */
    Wektor3D zakresK;

    std::string _napis = "";
public:
    /**
    * Konstruktor Sceny, tworzy scene o zakresach od zakresP do zakresZ,
    * ktore sa danymi punktami
    * 
    * @param[in] poczatek - wektorowy poczatek zakresu
    * @param[in] koniec - wektorowy koniec zakresu 
    */
    Scena(Wektor3D poczatek, Wektor3D koniec){zakresP = poczatek; zakresK = koniec;}
    
    /**
    * Destruktor sceny
    */
    ~Scena(){}

    /**
    * Funkcja generujuje wartosci dna oraz wody, po czym zwraca je do pliku
    * 
    * @param[in] nazwaPliku
    */
    bool generujSceneDoPliku(const char *nazwaPliku);
};

#endif