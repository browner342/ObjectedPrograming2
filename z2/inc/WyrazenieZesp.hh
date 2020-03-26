#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

/**
 * Pozwala operatorowi przesuniecia bitowego w prawo wypisac wyrazenie zespolone
 * 
 * @param[in] StrmWy - strumien wypisania
 * @param[in] WyrZ - liczba zespolona
 * @return Strumien do wypisania
 */
std::ostream& operator<<(std::ostream& StrmWy, WyrazenieZesp& WyrZ);

/**
 * Oblicza wyrazenie zespolone
 * 
 * @param[in] WyrZ - wyrazenie zepolone do oblicznia
 * @return liczba zespolona
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ);


#endif
