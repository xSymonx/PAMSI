//
//  Interfejs.cpp
//  Pamsi projekt 3
//
//  Created by Szymon Sztymar on 25/05/2021.
//

#include "Interfejs.hpp"
#include <iostream>

/* `Funkcja interfejs pobiera rozmiar pola do gry oraz ilosc znaków wygryw. */
/*  natsepnie wypelnia tablice "0" aby łatwiej było sprawdzić czy pole */
/*  jest puste pobiera od użytkownika miejsce wstawienia znaku nastepnie  */
/* sprawdza wygrana oraz wykonuje ruch komputera */
int interfejs()
{
    // Wczytanie wielkosci pola
    int ilosc_wygrywajacych;
    int rozmiar, rozm; // rozmiar calej planszy, rozm rzedu
    std::cout << "Podaj rozmiar pola: ";
    std::cin >> rozm;
    rozmiar = (rozm * rozm) + 1; // okreslenie ilosci znakow indeksujac od 1
    char tab[rozmiar];      // tablica przechowujaca znaki
    wypelnij_0(tab, rozmiar);           // wypelnienie tablicy zerami
    std::cout << "Podaj ilosc znakow potrzebnych do wygrania: ";
    std::cin >> ilosc_wygrywajacych;
    int wygrana;
    
    int z = 0;
    int a = 1;
    int x = 0, m = 0;
    int licznik = 1;
    int b = 0;
    
    while(z < rozmiar - 1)    // petla wstawiajaca znaki w podane miejsca
    {
        // gdy a = 1 ruch gracza gdy a = 2 komputera
        if(a == 1)
        {       // gracz podaje gdzie wstawic znak
            std::cout << "Gracz " << a << std::endl;
            std::cout << "Podaj numer pola w które chcesz wstawic X " << std::endl;
            std::cin >> x;
            m = tab[x];
            while( m != 0)      // funkcja sprawdza czy podane przez gracza pole jest puste
            {
                std::cout << "Pole zajęte!" << std::endl;
                std::cout << "Wprowadz ponownie numer pola:" << std::endl;
                std::cin >> x;
                m = tab[x];
            }
            tab[x] = 'X';  // wyswietlenie planszy oraz sprawdzenie wygranej
            wyswietl_plansze(tab, rozmiar);
            z++;
            a++;
            wygrana = sprawdz_wygrana(tab, rozmiar, ilosc_wygrywajacych, 'X');
            if(wygrana == 1)
            {
                std::cout << "Gratulacje pokonales komputer!!!" << std::endl;
                return 0;
            }
            else
                continue;
        }
        else
        {
            std::cout << "Komputer " << a << std::endl;
            ruch_komputera(tab, rozm, x, licznik, b); // wywoalnie funkcji
            b++;
            licznik++;                  // odpowiadajcej za ruch komputera
            std::cout << std::endl;
            wyswietl_plansze(tab, rozmiar);
            z++;
            a--;
            wygrana = sprawdz_wygrana(tab, rozmiar, ilosc_wygrywajacych, 'O');
            if(wygrana == 1)
            {
                std::cout << "Komputer wygrał!!!" << std::endl;
                return 0;
            }
            else
                continue;
        }
        std::cout << "Brak rozsztrzygnięcia." << std::endl;
    }
    return 0;
}
