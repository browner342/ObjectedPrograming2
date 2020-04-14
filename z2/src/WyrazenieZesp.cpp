#include "WyrazenieZesp.hh"
#include <iostream>
#include <cstring>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

std::ostream& operator<<(std::ostream& StrmWy, WyrazenieZesp& WyrZ){
    const char *TabOp = "+-*/";

    return StrmWy<<WyrZ.Arg1<<' '<<TabOp[WyrZ.Op]<<' '<<WyrZ.Arg2;
}

LZespolona Oblicz(WyrazenieZesp WyrZ){
    LZespolona Wynik;
    switch (WyrZ.Op){
    case Op_Dodaj:
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;
    case Op_Odejmij:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;
    case Op_Mnoz:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;
    case Op_Dziel:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    default:
        break;
    }
    return Wynik;
}

