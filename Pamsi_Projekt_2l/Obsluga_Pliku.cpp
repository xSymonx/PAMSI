//
//  Obsluga_Pliku.cpp
//  Pamsi projekt 2 final
//
//  Created by Szymon Sztymar on 14/05/2021.
//

#include "Obsluga_Pliku.hpp"

void zapisz_do_pliku(int wierzcholki, int liczba_krawedzi, int gestosc, std::fstream &Plik)
{
    int liczba_krawedzi_dod = liczba_krawedzi - wierzcholki + 1;        // liczba krawedzi pozostalych po połączeniu kazdego wierzcholka
    
    int tymczas = 0;
    int akt_wierzch = wierzcholki;              // Po utworzeniu krawedzi miedzy nastepnymi wierzcholkami aktualnym wierzcholkiem jest ostatni
    int il_wyk = 0;
    
    Plik.open("Graf.txt", std::ios_base::app);
    
    Plik << wierzcholki << " " << liczba_krawedzi << " " << rand() % wierzcholki << std::endl; //Wypisujemy ilosc wszystkich wierzcholków, krawedzi oraz wage krawedzi
    for(int i = 0; i < wierzcholki - 1 && i < liczba_krawedzi - 1; i++)  // wypisujemy wierz pocz oraz koncowy krawedzi oraz jego wage z przeddziału od 0 do 30
    {
        Plik << i << " " << i+1 << " " << rand() % 30 <<std::endl;
    }


    while(il_wyk < liczba_krawedzi_dod)          // petla wypisuje wierzcholki ododatkowe po utworzeniu krawedzi miedzy nastepnymi zaczynajac od ostatniego
    {
        tymczas = 0;

        while(il_wyk < liczba_krawedzi_dod && tymczas < akt_wierzch - 2) // Petla laczy wierzcholki od ostaniego z kazdym poprzednim
        {
            Plik << akt_wierzch - 1 << " " << tymczas << " " << rand() % 30 << std::endl;

            il_wyk++;
            tymczas++;
        }
        akt_wierzch--;
    }
    Plik.close();
}


void generuj_graf(std::fstream &Plik)
{
    int wierzcholki[5] = {10, 20, 30, 40, 50};
    int max_krawedzi[5]; // ilosc krawedzi w kazdym grafie
    int krawedzie[5][4];                              // tablica wszystkich krawedzi o roznych gestosciach
    int gestosc[4] = {25, 50, 75, 100};               // tablica z gestosciami grafu
    
    Plik.open("Graf.txt", std::ios_base::out);
    Plik.close();
    for(int i = 0; i < 5; i++)  // petle generujace grafy o okreslonej liczbie krawedzi i gestosci i zapisuje do pliku
    {
        max_krawedzi[i] = wierzcholki[i] * (wierzcholki[i] - 1) / 2;
        for(int j = 0; j < 4; j++)
        {
            krawedzie[i][j] = gestosc[j] * max_krawedzi[i] / 100;
            for(int m = 0; m < 100; m++)
            {
                zapisz_do_pliku(wierzcholki[i], krawedzie[i][j], gestosc[j], Plik);
            }
        }
    }
}
