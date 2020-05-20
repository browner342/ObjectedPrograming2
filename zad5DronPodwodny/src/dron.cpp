#include "dron.hh"

Dron::Dron(){
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny.push_back(elem);
    }
}

void Dron::ukladWokolOZ(const double& kat){
    
}