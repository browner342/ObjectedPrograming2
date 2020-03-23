#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona LZespOdpowiedz, LZPoprawnaOdp;
  Odpowiedzi Odp;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout<<endl<<"Podaj wynik operacji: "<<WyrZ_PytanieTestowe<<endl;
    cin>>LZespOdpowiedz;

    LZPoprawnaOdp = Oblicz(WyrZ_PytanieTestowe);

    if(cin.fail()){
      Odp.Zle++;
      cout<<"Blad. Prawidlowym wynikiem jest:"<<LZPoprawnaOdp<<endl;
    }else{
      if( LZespOdpowiedz == LZPoprawnaOdp){
        Odp.Dobre++;
        cout<<"Odpowiedz poprawna"<<endl;
      }else{
        Odp.Zle++;
        cout<<"Blad. Prawidlowym wynikiem jest:"<<LZPoprawnaOdp<<endl;
      }
    }
  }

  
  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;

  cout<<Odp<<endl;
}
