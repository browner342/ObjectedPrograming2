//#include "wektor.hh"
#include "macierz.hh"
#include "rozmiar.h"
#include "lzespolona.hh"

using namespace std;



void Test_SzablonWektor_double()
{
  cout << endl
       << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<double,ROZMIAR>    W, W_wynik;
  
  cin>>W;

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W/2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
}




void Test_SzablonWektor_LZespolona()
{
  cout << endl
       << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;


  SWektor<LZespolona,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W(Ind).re = Ind;      W(Ind).im = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
}



int main()
{
  //Test_SzablonWektor_double();
  //Test_SzablonWektor_LZespolona();
  Macierz<double,ROZMIAR> m;
  cin>>m;
  cout<<m.WyznacznikMGaussa();
}
