//
//  Sort_Kopcowanie.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#include "Sort_Kopcowanie.hpp"

/* Funkcja wywoluje sama siebie aby rozbic kopce na mniejsze drzewa oraz sprawdzjaca
   czy najwieksza wartosc znajduje sie w korzeniu kopca jesli nie to znajduje
   wieksza wartosc i przenosi do korzenia a nastepnie na koniec tablicy */
template <typename Typ>
void Sprawdz_Najwiekszy(Typ tab[], int rozmiar, int korzen)
{
    int roz_kopca = rozmiar;
    int l_galaz = (((korzen + 1) * 2) - 1);  // rozbicie na lewa galaz
    int p_galaz = ((korzen + 1) * 2);       // rozbicie na prawa
    int najwiekszy = korzen;      // zmienna do poszukiwania wartosci najwiekszej
    
    if(l_galaz < rozmiar && tab[l_galaz] > tab[korzen]) // sprawdzenie czy korzen
        najwiekszy = l_galaz;                           // jest wiekszy od wezlow
    if(p_galaz < rozmiar && tab[p_galaz] > tab[najwiekszy]) // jesli tak zamien
        najwiekszy = p_galaz;                               // najwieksza wartosc
    
    // jesli najwieksza wartosc zostala znaleziona poza korzeniem
    if (najwiekszy != korzen)
    {
        // przeniesienie wartosci najwiekszej do korzenia
        Zamien_Miejscami(tab[najwiekszy], tab[korzen]);
        Sprawdz_Najwiekszy(tab, roz_kopca, najwiekszy); // rozbicie na miejsze kopce
    }
}


/* sortowanie przez kopcowanie, tworzony jest kopiec majacy w korzeniu
   najwieksza wartosc jesli wartosc ta zostanie znaleziona w innym miejscu
   to zostaje przeniesiona do korzenia i zostaje zamieniony z pierwszym */
template< typename Typ>
void Sortowanie_Przez_Kopcowanie(Typ tab[], int rozmiar)
{
    int roz_kopca = rozmiar;
    
    // Budowanie kopca oraz szukanie najwiekszych wartosci
    for(int j =  ((roz_kopca - 1) / 2); j >= 0; --j)
        Sprawdz_Najwiekszy(tab, rozmiar, j);
    
    //  zmiana kopca w posortowana tablice
    for(int i = rozmiar - 1; i > 0; --i)
    {
        Zamien_Miejscami(tab[i], tab[0]);
        --roz_kopca;
        Sprawdz_Najwiekszy(tab, roz_kopca, 0);
    }
}
