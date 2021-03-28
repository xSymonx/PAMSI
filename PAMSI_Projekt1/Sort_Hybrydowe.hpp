//
//  Sort_Hybrydowe.hpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#ifndef Sort_Hybrydowe_hpp
#define Sort_Hybrydowe_hpp

#include <stdio.h>

/* Deklaracje funkcji */

/* Funkcja obliczajaca logaytm o podanej podstawie  */
double log_2(double x, double y){return (log(x) / log(y));}

template <typename Typ>
void Sortowanie_Hybrydowe(Typ tab[], int rozmiar);

template <typename Typ>
int Partition(Typ tab[], int poczatek, int koniec);

template <typename Typ>
void Sortowanie_Przez_Wstawianie(Typ tab[], int rozmiar);

#endif /* Sort_Hybrydowe_hpp */
