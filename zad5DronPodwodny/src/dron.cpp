#include "dron.hh"

Dron::Dron(){
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny.push_back(elem);
    }
}
void Dron::powrotDoUkladuLok(){
    int i = 0;
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny[i] = elem;
        i++;
    }
}

void Dron::obrotWokolOZ(const double& kat){
    katZmianyUkladu += kat;
    double katRad = katZmianyUkladu;
    katRad *= M_PI / 180;
    Wektor3D wekDoMacierzy[3];
    wekDoMacierzy[0] = Wektor3D(cos(katRad), sin(katRad), 0);
    wekDoMacierzy[1] = Wektor3D(-sin(katRad), cos(katRad), 0);
    wekDoMacierzy[2] = Wektor3D(0, 0, 1);
    Macierz3D macierzZmian = Macierz3D(wekDoMacierzy[0], wekDoMacierzy[1], wekDoMacierzy[2]);

    
    //wraca do poczatkowego ukladu wspolzednych
    (*this).powrotDoUkladuLok();
    for(Wektor3D& elem : _ukladGlobalny){
        elem = macierzZmian * elem + wektorPrzesunieciaUkladu;
    }
}

void Dron::ruchNaWprost(const double& katGoraDol, const double& odleglosc){
    double katPoziomRAD = katZmianyUkladu * M_PI / 180;
    double katPionRAD = katGoraDol * M_PI / 180;

    wektorPrzesunieciaUkladu = Wektor3D(odleglosc*cos(katPoziomRAD), odleglosc*(-sin(katPoziomRAD)), odleglosc*sin(katPionRAD));
    std::cout<<wektorPrzesunieciaUkladu;

    for(Wektor3D& elem : _ukladGlobalny){
        elem = elem + wektorPrzesunieciaUkladu;
    }
}

void Dron::dronPozaMapa(Wektor3D& po, Wektor3D& ko){
    
}

std::string Dron::generujDronaDoPliku(){
    int i = 0;
    _napis = "";
    std::ofstream Strm(DRON);
    if (Strm.fail()) std::cerr<<"Zapis Drona do pliku nie powiodl sie!"<<std::endl;

    for(Wektor3D& elem : _ukladGlobalny){
        i++;
        _napis += elem.napis();
        if(i % 4 == 0){
            _napis += "\n";
        }
    }_napis += "#\n\n";

    Strm<<_napis;
    return _napis;
}