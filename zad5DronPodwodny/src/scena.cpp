#include <scena.hh>
bool Scena::generujSceneDoPliku(const char *nazwaPliku){
    //generowanie wartosci wektorow wody oraz dna
    Woda w = Woda(zakresP, zakresK);
    Dno d = Dno(zakresP, zakresK);

    std::ofstream Strm(nazwaPliku);
    if (Strm.fail()) return false;

    int tmp = int(zakresK(0)) / KROK_SIATKI;
    for( int i = 0; i < w.ilosc(); i++ ){
        if(i % tmp == 0){
            Strm<<std::endl;
        }

        Strm<<w[i]<<std::endl;
    }Strm<<"#"<<std::endl<<std::endl;

    for( int i = 0; i < d.ilosc(); i++ ){
        if(i % tmp == 0){
            Strm<<std::endl;
        }
        
        Strm<<d[i]<<std::endl;
    }Strm<<"#"<<std::endl<<std::endl;
    
    return true;
}