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

std::istream& operator>>(std::istream& StrmWe, Operator& Op){
    char Ch = 'x';
    char const *OperChars = "+-*/", *pOperCh;
    Operator OperTab[] = { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

    if(StrmWe.fail()) return StrmWe;
    StrmWe >> Ch;
    if(StrmWe.fail()) return StrmWe;
    if ((pOperCh = strchr(OperChars, Ch))){Op = OperTab[pOperCh-OperChars]; }
        else {StrmWe.setstate(std::ios::failbit); }
    return StrmWe;
}

std::istream& operator>>(std::istream& StrmWe, WyrazenieZesp& WyrZ){
    StrmWe>>WyrZ.Arg1>>WyrZ.Op>>WyrZ.Arg2;
    return StrmWe;
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

