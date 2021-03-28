//
//  Sort_Hybrydowe.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#include "Sort_Hybrydowe.hpp"

/* Sortowanie przez wstawianie */
/* ustawiamy wskaznik na 2 el tablicy, porownujemy wczesniejszymi w poszukiwaniu
   wiekszego jesli taki wystepuje zamieniamy je miejscami, w momencie dotarcia
   do poczatku tablicy przesuwamy wskaznik tablicy na nastepny element */
template <typename Typ>
void Sortowanie_Przez_Wstawianie(Typ tab[], int rozmiar)
{

    for(int i = 1; i < rozmiar; i++) // wskaznik na drugi elemnt i przesuwanie
    {
        // funkcja przechodzaca i porownujaca poprzednie elementy z obecnym
        for(int j = i; j >= 0; j--)
        {
            if(tab[j-1] > tab[j])
                Zamien_Miejscami(tab[j-1], tab[j]);
        }
    }
}

/* funkcja dzieli tablice na dwie czesci elemnty wieksze od zmiennej podzialu
   na prawo od niej a mniejsze na lewo*/
template <typename Typ>
int Partition(Typ tab[], int poczatek, int koniec)
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
        return j;
}


    
/* Polaczenie tzrzech algorytmow sortowania:
   szybkiego, poprzez wstawainie oraz przez kopcowanie
   kazdy z algorytmow jest uzywany w przedziale swojej najwiekszej wydatnosci
   funkcja dzieli tablice na podtablice rozlaczne pozniej wybiera najszybszy
   algorytm do ich posortowania */

template <typename Typ>
void Sortowanie_Hybrydowe(Typ tab[], int rozmiar)
{
    int podzial = Partition(tab, 0, rozmiar - 1);
    
    if(podzial > 2 * (log_2(rozmiar, 2)))
    {
        Sortowanie_Przez_Kopcowanie(tab, rozmiar);
    }
    else if(podzial < 9)
    {
        Sortowanie_Szybkie(tab, 0, rozmiar - 1);
    }
    else
        Sortowanie_Przez_Wstawianie(tab, rozmiar);
}

