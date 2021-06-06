//
//  Obsluga_planszy.cpp
//  Pamsi projekt 3
//
//  Created by Szymon Sztymar on 19/05/2021.
//

#include "Obsluga_planszy.hpp"
#include <iostream>


// funkcja wyswietla plansze z dostosowaniem do rozmiaru
void wyswietl_plansze(char tab[], int rozmiar)
{
    for(int i = 1; i <= rozmiar - 1; i++)
    {
        
        int r = sqrt(rozmiar - 1); // obliczamy ilosc znakow ywswietlanych w jednym rzedzie
        std::cout << " " << tab[i] << " ";
        if(i % r) // wyswietlamy wszystkie znaki z 1 rzedu
            std::cout << "|";
        else if(i != (rozmiar - 1))
        {
            std::cout << std::endl;
            for(int j = 0; j < r; j++)
                std::cout << "----"; // przerwa miedzy rzedami
            std::cout << std::endl;
        }
        else std::cout << std::endl;
    }
}
// funkcja wypelnia tablice zerami aby latwiej bylo sprawdzac czy pola sa puste
void wypelnij_0(char tab[], int rozmiar)
{
    for(int i = 1; i < rozmiar; i++)
    {
            tab[i] = 0;
    }
}
