#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>

/*
 * Modeluje pojecie odpowiedzi udzielonych przez uzytkownika
 */
struct Odpowiedzi{
    int Dobre = 0, Zle = 0;
    float Procent;
};

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac Odpowiedzi
 * 
 * @param[in] StrmWy - strumien wypisania
 * @param[in] Odp - odpowiedzi
 * @return Strumien do wypisania
 */
std::ostream& operator<<(std::ostream& StrmWy, Odpowiedzi &Odp);

#endif
