#include "lzesp.hh"
#include <iomanip>

using namespace std;


/*!
 * Podstawia do liczby zespolonej liczbę rzeczywistą.
 * Powoduje to, że w części urojonej zostanie automatycznie podstawiona
 * wartość 0.
 */
LZespolona &LZespolona::operator = (double  Liczba)
{
  this->re = Liczba; this->im = 0;
  return *this;
}




/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Odjemna  - pierwszy argument operacji odejmownia,
 *    Odjemnik - drugi argument operacji odejmowania.
 * Zwraca:
 *    Różnica dwoch argumentów przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Odjemna,  LZespolona  Odjemnik)
{
  LZespolona  Wynik;

  Wynik.re = Odjemna.re - Odjemnik.re;
  Wynik.im = Odjemna.im - Odjemnik.im;
  return Wynik;
}



/*!
 * Realizuje mnozenie liczby zespolonej przez liczbę rzeczywistą (typ double)
 * Argumenty:
 *    Mnozna         - pierwszy argument operacji mnozenia (liczba zespolona),
 *    Mnoznik_Liczba - drugi argument operacji mnozenia (liczba rzeczywista).
 * Zwraca:
 *    Iloczyn dwoch argumentów przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba)
{
  LZespolona  Wynik;

  Wynik.re = Mnozna.re * Mnoznik_Liczba;
  Wynik.im = Mnozna.im * Mnoznik_Liczba;
  return Wynik;
}


/*!
 * Umożliwia wyświetlenie liczby zespolonej w formacie:
 *             (4.5+5.6i)
 * Parametry:
 *    StrmWyj - strumień wyjściowy, do którego ma być wpisany napis
 *              reprezentujący liczbę zespoloną,
 *       Zesp - liczba zespolona, której wartość ma być zapisana w postaci
 *              znakowej w danym strumieniu.
 * Zwraca: Strumień wyjściowy przekazany jako pierwszy parametr.
 */
ostream &operator << (ostream &StrmWyj, LZespolona  Zesp)
{
  return StrmWyj << '(' << Zesp.re << showpos << Zesp.im << "i)" << noshowpos;
}
