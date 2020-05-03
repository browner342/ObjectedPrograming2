#include "lzespolona.hh"
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
bool LZespolona::operator != (double Liczba){
    if(re != Liczba && im != Liczba){return true;}
    return false;
}
LZespolona &LZespolona::operator = (double  Liczba)
{
  this->re = Liczba; this->im = 0;
  return *this;
}

LZespolona LZespolona::operator + (LZespolona  Z2) const{
  Z2.re += this->re;  Z2.im += this->im;
  return Z2;
}

LZespolona LZespolona::operator - (LZespolona  Z2) const{
  Z2.re = this->re - Z2.re; Z2.im = this->im - Z2.im;
  return Z2;
}

LZespolona  LZespolona::operator * (LZespolona  Z2) const{
  LZespolona Wynik;

  Wynik.re = (this->re * Z2.re) - (this->im * Z2.im);
  Wynik.im = (this->im * Z2.re) + (this->re * Z2.im);
  
  return Wynik;
}

LZespolona  operator * (float liczba, LZespolona &Z){
  Z.re *= liczba; Z.im *= liczba;
  return Z;
}

LZespolona  operator * (LZespolona &Z, float liczba){
  Z.re *= liczba; Z.im *= liczba;
  return Z;
}

LZespolona LZespolona::operator / (LZespolona Z2) const{
  double Mianownik;

  //Mianownik
  Mianownik = Z2.Modul() * Z2.Modul();

  Z2.Sprzezenie();
  //Licznik
  Z2 = *this * Z2;

  //Dzielenie cześci liczby zespolonej
  Z2.re = Z2.re / Mianownik;
  Z2.im = Z2.im / Mianownik;

  return Z2;
}

bool operator == (LZespolona Arg1, LZespolona Arg2){
  double epsilon = 0.055;
  if(fabs(Arg1.re - Arg2.re) < epsilon && fabs(Arg1.im - Arg2.im) < epsilon ){
    return true;
  }
  return false;
}

void LZespolona::Sprzezenie (){

  this->im = -this->im;

}

double LZespolona::Modul (){
  double Wynik;

  Wynik = sqrt((this->re * this->re) + (this->im * this->im));
  return Wynik;
}

std::ostream& operator<<(std::ostream& StrmWy, const LZespolona& Lz){
  return StrmWy<<'('<<Lz.re<<std::showpos<<Lz.im<<std::noshowpos<<'i'<<')';
}

std::istream& operator>>(std::istream& StrmWe, LZespolona& Lz){
    char znak1, znak2, znak3;
    StrmWe>>znak1;
    if(znak1 != '('){return StrmWe;}
    StrmWe>>Lz.re;
    if(StrmWe.fail()){return StrmWe;}
    StrmWe>>Lz.im;
    StrmWe>>znak2;
    StrmWe>>znak3;
    //StrmWe.ignore();
    return StrmWe;
}
