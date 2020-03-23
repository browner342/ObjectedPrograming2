#include "LZespolona.hh"
#include <iostream>
#include <cmath>


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);

  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;
  double Mianownik;

  //Licznik
  Wynik = Skl1 * sprzeznie(Skl2);

  //Mianownik
  Mianownik = pow(2, Modul(Skl2));

  //Dzielenie cześci liczby zespolonej
  Wynik.re = Wynik.re / Mianownik;
  Wynik.im = Wynik.im / Mianownik;

  return Wynik;
}

bool operator == (LZespolona Arg1, LZespolona Arg2){
  double epsilon = 0.00001;
  if(fabs(Arg1.re - Arg2.re) < epsilon && fabs(Arg1.im - Arg2.im) < epsilon ){
    return true;
  }
  return false;
}

LZespolona  sprzeznie (LZespolona  Lz){
  LZespolona  Wynik;

  Wynik.re = Lz.re;
  Wynik.im = (-1) * Lz.im;
  return Wynik;
}

double Modul (LZespolona Lz){
  double Wynik;

  Wynik = sqrt((Lz.re * Lz.re) + (Lz.im * Lz.im));
  return Wynik;
}

std::ostream& operator<<(std::ostream& StrmWy, LZespolona& Lz){
  return StrmWy<<'('<<Lz.re<<std::showpos<<Lz.im<<std::noshowpos<<'i'<<")";
}

std::istream& operator>>(std::istream& StrmWe, LZespolona& Lz){
  int Licznik = 1;
  char Inne;
  
  StrmWe.clear();
  std::cout<<"Twoja odpowiedz: ";

  StrmWe >> Inne;
  if(Inne != '('){StrmWe.setstate(std::ios::failbit);}
  StrmWe >> Lz.re >> Lz.im;
  StrmWe >> Inne;
  if(Inne != 'i'){StrmWe.setstate(std::ios::failbit);}
  StrmWe >> Inne;
  if(Inne != ')'){StrmWe.setstate(std::ios::failbit);}
  StrmWe.ignore();

  std::cout<<std::endl;

  while(StrmWe.fail()){
    std::cerr<<"Blad formatu liczby zespolonej"<<std::endl;
    if(Licznik == 3){
      return StrmWe;
    }

    StrmWe.clear();
    StrmWe.ignore(1000, '\n');

    std::cout<<"Twoja odpowiedz: ";

    StrmWe >> Inne;
    if(Inne != '('){StrmWe.setstate(std::ios::failbit);}
    StrmWe >> Lz.re >> Lz.im;
    StrmWe >> Inne;
    if(Inne != 'i'){StrmWe.setstate(std::ios::failbit);}
    StrmWe >> Inne;
    if(Inne != ')'){StrmWe.setstate(std::ios::failbit);}
    StrmWe.ignore();

    std::cout<<std::endl;

    Licznik++;
  }
  return StrmWe;
}
