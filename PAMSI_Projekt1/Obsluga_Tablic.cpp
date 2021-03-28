//
//  Obsluga_Tablic.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#include "Obsluga_Tablic.hpp"

/* Funkcja zmieniajaca miejscami 2 elementy tablicy */
template <typename Typ>
void Zamien_Miejscami(Typ &i, Typ &j)
{
    Typ tymczas = i;
    i = j;
    j = tymczas;
}

/* Funkcja odwracajaca tablice wartosc ostatnia robie sie pierwsza*/
template <typename Tablica>
void Odwroc(Tablica *Tab, int rozmiar)
{
    Tablica Tymczas[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        Tymczas[i] = Tab[i];
    }
    for (int i = 0; i < rozmiar; i++)
    {
        Tab[i] = Tymczas[rozmiar-1-i];
    }
}

/* Funkcja przygotowuje tablice sortujac ja w okreslonym przez uzytkownika stopniu */
/* zmienna wybbor przekazuje procent w jakim tablica ma byc posortowana */
template <typename Typ>
void Procent_Posortowania(Typ tab[], int rozmiar, double wybor)
{
    double Procent =  wybor;
    
    int idx_podzielenia = ((rozmiar + 1) * Procent) / 100;
    // obliczenie wielkosci dwoch podtablic i ich dynamiczna alokacja
    int roz_pos = idx_podzielenia;
    int roz_npos = rozmiar - idx_podzielenia + 1;
    Typ *tablica_posortowana = new int [roz_pos];
    Typ *tablica_nieposortowana = new int [roz_npos];
    
    // uzupelnienie tablic wartosciami
    int i = 0;
    for(i = 0; i < idx_podzielenia; i++)
    {
        tablica_posortowana[i] = tab[i];
    }
    
    int j = 0;
    for( i; i <= rozmiar; i++)
    {
        tablica_nieposortowana[j] = tab[i];
        j++;
    }
    // wstepne posortowanie tablicy w danym stopniuza pomoca najszybszego sortowania
    Sortowanie_Szybkie(tablica_posortowana, 0, idx_podzielenia);
    // zlaczenie posortowanej czesci tablicy i nieposortowwanej
    int z = 0;
    for(z = 0; z < idx_podzielenia; z++)
    {
        tab[z] = tablica_posortowana[z];
    }
    
    int k = 0;
    for( z; z <= rozmiar; z++)
    {
        tab[z] = tablica_nieposortowana[k];
        k++;
    }
}
