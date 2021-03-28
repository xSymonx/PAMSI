//
//  Sort_Scalanie.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 24/03/2021.
//

#include "Sort_Scalanie.hpp"

/* Sortowanie przez scalanie funkcja wywoluje sama siebie rekurencyjnie dzielac tablice
   na mniejsze nastepnie sortuje i laczy elementy */
template <typename Typ>
void Sortowanie_Przez_Scalanie(Typ *tablica, int poczatek, int koniec)
{
    if(poczatek < koniec)
    {
        long int srodek = poczatek + (koniec - poczatek) / 2;
        Sortowanie_Przez_Scalanie(tablica, poczatek, srodek);
        Sortowanie_Przez_Scalanie(tablica, srodek + 1, koniec);
        Polacz(tablica, poczatek, srodek, koniec);
    }
}

/* Funkcja  */
template <typename Typ>
void Polacz(Typ *tablica, int pocz_tab, int sr_tab, int kon_tab)
{
    // obliczenie wielkosci dwoch podtablic i ich dynamiczna alokacja
    Typ Roz_Lewa_Tab = ((sr_tab - pocz_tab) + 1);
    Typ Roz_Prawa_Tab = (kon_tab - sr_tab);
    
    Typ *lewa_tablica = new Typ[Roz_Lewa_Tab];
    Typ *prawa_tablica = new Typ[Roz_Prawa_Tab];
    // Rozdzielenie oryginalnej tablicy na dwie tymczasowe
    for(int i = 0; i < Roz_Lewa_Tab; i++)
        lewa_tablica[i] = tablica[pocz_tab + i];
    
    for(int j = 0; j < Roz_Prawa_Tab; j++)
        prawa_tablica[j] = tablica[sr_tab + 1 + j];
    
    // zmienne pomocnicze do sortowania i wstawiania do tablic
    int z = pocz_tab;
    int p = 0;
    int s = 0;
    
    // sortowanie podzielonych tablic i wstawianie ich do oryginalnej
    // tablicy w odpowiedniej kolejnosci
    while (p < Roz_Lewa_Tab && s < Roz_Prawa_Tab)
    {
        if( lewa_tablica[p] <= prawa_tablica[s])
        {
            tablica[z] = lewa_tablica[p];
            p++;
        }
        else
        {
            tablica[z] = prawa_tablica[s];
            s++;
        }
        z++;
    }
    
    // jesli jedna z tablic zosatnie pusta uzupelniamy oryginalna
    // tablice do konca druga tablica
    for(p; p < Roz_Lewa_Tab; p++)
    {
        tablica[z] = lewa_tablica[p];
        z++;
    }
    
    for(s; s < Roz_Prawa_Tab; s++)
    {
        tablica[z] = prawa_tablica[s];
        z++;
    }
    
    delete[] lewa_tablica;
    delete[] prawa_tablica;
}
