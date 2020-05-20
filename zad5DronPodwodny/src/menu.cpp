#include "menu.hh"
void wypiszOpcje(){
    std::cout<<"r - zadaj ruch na wprost"<<std::endl;
    std::cout<<"o - zadaj zmiane orientacji"<<std::endl;
    std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
    std::cout<<"k - koniec dzialania programu"<<std::endl;
}
void otworzMenu(Dron& dron){
    char wpisanyZnak = 'm';

    wypiszOpcje();
    while(wpisanyZnak != 'k'){
        std::cin>>wpisanyZnak;
        if(std::cin.fail()){
            std::cerr<<"Wczytywanie litery nie powiodlo sie!"<<std::endl;
        }

        switch (wpisanyZnak){
        case 'r':

            break;
        case 'o':

            break;

        case 'm':
            wypiszOpcje();
            break;

        case 'k':
            std::cout<<"Koniec programu"<<std::endl;
            break;

        default:
            std::cout<<"Nie ma takiej opcji!"<<std::endl;
            std::cout<<"Sprobuj ponownie."<<std::endl;
            break;
        }
        std::cout<<std::endl<<std::endl;
    }
}

void obslugaGNUplota(const Wektor3D& wektorP, const Wektor3D& wektorK){
    PzG::LaczeDoGNUPlota  Lacze;

    Lacze.DodajNazwePliku(DNOIWODA);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    
    Lacze.UstawZakresX(wektorP(0), wektorK(0));
    Lacze.UstawZakresY(wektorP(1), wektorK(1));
    Lacze.UstawZakresZ(POZ_DNA-10, POZ_WODY+10);

    Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
    Lacze.Rysuj(); 
}