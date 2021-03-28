//
//  Sort_Szybkie.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 24/03/2021.
//

#include "Sort_Szybkie.hpp"
#include "Obsluga_Tablic.hpp"



/* Sortowanie poprzez wyzanczenie punktu odniesienia i porownywanie z nim
   od konca i od poczatku kolejnych elementow tablicy oraz zamieniaie ich miejscami,
   jesli sa po niewlasciwych stronach funkcja wywoluje sama siebie do momentu
   utworzenia tablic jednoelementowych */
template<typename Typ>
void Sortowanie_Szybkie(Typ *tab, int poczatek, int koniec)
{
    int i = poczatek;   // zmienna indeksujaca tablice od poczatku
    int j = koniec;     // zmienna indeksujaca tablice od konca
    int srodek = tab[(poczatek + koniec) / 2];  // wyznaczenie pkt odniesienia
    do
    {
        for(i; tab[i] < srodek;)    // jesli elemnty sa mniejsze od pkt odniesiania
            i++;                //  bierzemy nastepny element tablicy i porownujemy
        
        for(j; tab[j] > srodek;)    // jesli elemnty sa wieksze od pkt odniesiania
            j--;                //  bierzemy nastepny element tablicy i porownujemy
        
        if(i <= j)      // jesli zmienne indeksujace sie nie minely zamieniamy miejsca
        {
            Zamien_Miejscami(tab[i], tab[j]);
            i++;            // po zmianie miejsc przejscie jeden element dalej
            j--;            // oraz jeden element wczesniej
        }
        
    }
    while(i < j);
    
    if(i < koniec)    // jesli tablice nie sa jednoelementowe wywolujemy ponownie funkcje
        Sortowanie_Szybkie(tab, i, koniec);
    if(j > poczatek)
        Sortowanie_Szybkie(tab, poczatek, j);
}
