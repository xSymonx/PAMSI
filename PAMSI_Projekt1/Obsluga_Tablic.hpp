//
//  Obsluga_Tablic.hpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#ifndef Obsluga_Tablic_hpp
#define Obsluga_Tablic_hpp
static int const ilosc_t = 100; // Zmienna uzyta do okreslenia ilosci tablic

#include <stdio.h>

/* Deklaracje */

/* Funkcja zmieniajaca miejscami 2 elementy tablicy */
template<typename Typ>
void Zamien_Miejscami(Typ &i, Typ &j);

template <typename Tablica>
void Odwroc(Tablica *Tab, int rozmiar);

template <typename Typ>
void Procent_Posortowania(Typ tab[], int rozmiar, double wybor);

#endif /* Obsluga_Tablic_hpp */
