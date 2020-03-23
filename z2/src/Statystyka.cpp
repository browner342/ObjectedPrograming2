#include <iostream>

#include "Statystyka.hh"

std::ostream& operator<<(std::ostream& StrmWy, Odpowiedzi &Odp){
    Odp.Procent = Odp.Dobre;
    Odp.Procent /= (Odp.Dobre + Odp.Zle);
    Odp.Procent *= 100;

    StrmWy<<"Ilosc dobrych  odpowiedzi: "<<Odp.Dobre<<std::endl;
    StrmWy<<"Ilosc blednych odpowiedzi: "<<Odp.Zle<<std::endl;
    StrmWy<<"Wynik procentowy poprawnych odpowiedzi: "<<Odp.Procent<<"%"<<std::endl;

    return StrmWy;
}