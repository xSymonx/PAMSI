//
//  Sortowanie.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 27/03/2021.
//

#include <stdio.h>
#include <ctime>
#include "Sort_Szybkie.cpp"
#include "Sort_Kopcowanie.cpp"
#include "Sort_Hybrydowe.cpp"
#include "Obsluga_Tablic.cpp"
#include "Timer.cpp"
#include "Sort_Scalanie.cpp"

/* Deklaracje funkcji*/
void Wykonaj_Sortowanie_Hybrydowe();
void Wykonaj_Sortowanie_Przez_Scalanie();
void Wykonaj_Sortowanie_Szybkie();



void Wykonaj_Sortowanie_Hybrydowe()
{
// pobranie od uzytkownika wielkosci tablic oraz uzupelnienie ich liczbami losowymi
    int Rozmiar;
    std::cout << "Podaj ilosc elementów do posortowania: ";
    std::cin >> Rozmiar;
    int **Tablice = new int *[ilosc_t];
    
    for (int i = 0; i < ilosc_t; i++)
    {
        Tablice[i] = new int[Rozmiar];
    }
    
    srand( time( NULL));
    for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j < Rozmiar; j++)
        {
            Tablice[i][j] = rand() % 1000;
        }
    }
    
    // Menu w ktorym uzytkownik wybierta opcje sortowania
    char wybor;
    std::cout << "WYBIERZ OPCEJ SORTOWANIA" << std::endl;
    std::cout << "a. Tablica nieposortowana. " << std::endl;
    std::cout << "b. Tablica posortowana w pewnym stopniu. " << std::endl;
    std::cout << "c. Odwrotna kolejnosc liczb w posortowanej tablicy. " << std::endl;
    std::cin >> wybor;
    
    switch(wybor)
    {
        case 'a':
        {
            break;
        }
        case 'b':
        {
    // menu w ktorym uzytkownik wybiera procent wstepnego posortowania
            char wybor2;
            std::cout << "WYBIERZ PROCENT SORTOWANIA" << std::endl;
            std::cout << "a. 25% " << std::endl;
            std::cout << "b. 50% " << std::endl;
            std::cout << "c. 75% " << std::endl;
            std::cout << "d. 95% " << std::endl;
            std::cout << "e. 99% " << std::endl;
            std::cout << "f. 99.7% " << std::endl;
            std::cin >> wybor2;
            
            switch(wybor2)
            {
                case 'a':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 25);
                    }
                    break;
                }
                case 'b':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 50);
                    }
                    break;
                }
                case 'c':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 70);
                    }
                    break;
                }
                case 'd':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 95);
                    }
                    break;
                }
                case 'e':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99);
                    }
                    break;
                }
                case 'f':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99.7);
                    }
                    break;
                }
                default:
                {
                    std::cout << "Niepoprawna opcja!" << std::endl;
                }
                    break;
            }
        case 'c':
            {
                for (int i = 0; i < ilosc_t; i++)
                {
                    Odwroc(Tablice, Rozmiar);
                }
                break;
            }
        default:
            {
                std::cout << "Niepoprawna opcja!" << std::endl;
            }
        }
    }
    
    // inicjalizacja zmiennych uzywanych do liczenia czasu
    Czas sort_hybryd;
    std::cout << "*************************************" << std::endl;
    std::cout << "** ROZPOCZETO SORTOWANIE HYBRYDOWE **" << std::endl;
    // rozpoczecie liczenia czasu oraz sortowania
    sort_hybryd.Start();
    for (int i = 0; i < ilosc_t; i++)
    {
        Sortowanie_Hybrydowe(Tablice[i], Rozmiar);
    }
    sort_hybryd.Stop();
    sort_hybryd.Pokaz_Czas();
    // funkcja sluzaca do wyswietlania posortowanych tablic
    
    /*for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j <Rozmiar; j++)
            std::cout << j+1 << "-" << Tablice[i][j] << std::endl;
        std::cout << std::endl;
    }*/
    for (int i = 0; i < ilosc_t; i++)
    {
        delete[] Tablice[i];
    }
    delete[] Tablice;
}

void Wykonaj_Sortowanie_Przez_Scalanie()
{
// pobranie od uzytkownika wielkosci tablic oraz uzupelnienie ich liczbami losowymi
    int Rozmiar;
    std::cout << "Podaj ilosc elementów do posortowania: ";
    std::cin >> Rozmiar;
    int **Tablice = new int *[ilosc_t];
    
    for (int i = 0; i < ilosc_t; i++)
    {
        Tablice[i] = new int[Rozmiar];
    }
    
    srand( time( NULL));
    for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j < Rozmiar; j++)
        {
            Tablice[i][j] = rand() % 1000;
        }
    }
    // Menu w ktorym uzytkownik wybierta opcje sortowania
    char wybor;
    std::cout << "WYBIERZ OPCEJ SORTOWANIA" << std::endl;
    std::cout << "a. Tablica nieposortowana. " << std::endl;
    std::cout << "b. Tablica posortowana w pewnym stopniu. " << std::endl;
    std::cout << "c. Odwrotna kolejnosc liczb w posortowanej tablicy. " << std::endl;
    std::cin >> wybor;
    
    switch(wybor)
    {
        case 'a':
        {
            break;
        }
        case 'b':
        {
            // menu w ktorym uzytkownik wybiera procent wstepnego posortowania
            char wybor2;
            std::cout << "WYBIERZ PROCENT SORTOWANIA" << std::endl;
            std::cout << "a. 25% " << std::endl;
            std::cout << "b. 50% " << std::endl;
            std::cout << "c. 75% " << std::endl;
            std::cout << "d. 95% " << std::endl;
            std::cout << "e. 99% " << std::endl;
            std::cout << "f. 99.7% " << std::endl;
            std::cin >> wybor2;
            
            switch(wybor2)
            {
                case 'a':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 25);
                    }
                    break;
                }
                case 'b':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 50);
                    }
                    break;
                }
                case 'c':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 70);
                    }
                    break;
                }
                case 'd':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 95);
                    }
                    break;
                }
                case 'e':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99);
                    }
                    break;
                }
                case 'f':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99.7);
                    }
                    break;
                }
                default:
                {
                    std::cout << "Niepoprawna opcja!" << std::endl;
                }
                    break;
            }
        case 'c':
            {
                for (int i = 0; i < ilosc_t; i++)
                {
                    Odwroc(Tablice, Rozmiar);
                }
                break;
            }
        default:
            {
                std::cout << "Niepoprawna opcja!" << std::endl;
            }
        }
    }
    // inicjalizacja zmiennych uzywanych do liczenia czasu
    Czas sort_scal;
    std::cout << "******************************************" << std::endl;
    std::cout << "** ROZPOCZETO SORTOWANIE PRZEZ SCALANIE **" << std::endl;
    // rozpoczecie liczenia czasu oraz sortowania
    sort_scal.Start();
    for (int i = 0; i < ilosc_t; i++)
    {
        Sortowanie_Przez_Scalanie(Tablice[i], 0, Rozmiar);
    }
    sort_scal.Stop();
    sort_scal.Pokaz_Czas();
    // funkcja sluzaca do wyswietlania posortowanych tablic
    
    /*for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j <Rozmiar; j++)
            std::cout << j+1 << "-" << Tablice[i][j] << std::endl;
        std::cout << std::endl;
    }*/
    for (int i = 0; i < ilosc_t; i++)
    {
        delete[] Tablice[i];
    }
    delete[] Tablice;
}


void Wykonaj_Sortowanie_Szybkie()
{
// pobranie od uzytkownika wielkosci tablic oraz uzupelnienie ich liczbami losowymi
    int Rozmiar;
    std::cout << "Podaj ilosc elementów do posortowania: ";
    std::cin >> Rozmiar;
    int **Tablice = new int *[ilosc_t];
    
    for (int i = 0; i < ilosc_t; i++)
    {
        Tablice[i] = new int[Rozmiar];
    }
    
    srand( time( NULL));
    for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j < Rozmiar; j++)
        {
            Tablice[i][j] = rand() % 1000;
        }
    }
    // Menu w ktorym uzytkownik wybierta opcje sortowania
    char wybor;
    std::cout << "WYBIERZ OPCEJ SORTOWANIA" << std::endl;
    std::cout << "a. Tablica nieposortowana. " << std::endl;
    std::cout << "b. Tablica posortowana w pewnym stopniu. " << std::endl;
    std::cout << "c. Odwrotna kolejnosc liczb w posortowanej tablicy. " << std::endl;
    std::cin >> wybor;
    
    switch(wybor)
    {
        case 'a':
        {
            break;
        }
        case 'b':
        {
            // menu w ktorym uzytkownik wybiera procent wstepnego posortowania
            char wybor2;
            std::cout << "WYBIERZ PROCENT SORTOWANIA" << std::endl;
            std::cout << "a. 25% " << std::endl;
            std::cout << "b. 50% " << std::endl;
            std::cout << "c. 75% " << std::endl;
            std::cout << "d. 95% " << std::endl;
            std::cout << "e. 99% " << std::endl;
            std::cout << "f. 99.7% " << std::endl;
            std::cin >> wybor2;
            
            switch(wybor2)
            {
                case 'a':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 25);
                    }
                    break;
                }
                case 'b':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 50);
                    }
                    break;
                }
                case 'c':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 70);
                    }
                    break;
                }
                case 'd':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 95);
                    }
                    break;
                }
                case 'e':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99);
                    }
                    break;
                }
                case 'f':
                {
                    for (int i = 0; i < ilosc_t; i++)
                    {
                        Procent_Posortowania(Tablice[i], Rozmiar, 99.7);
                    }
                    break;
                }
                default:
                {
                    std::cout << "Niepoprawna opcja!" << std::endl;
                }
                    break;
            }
        case 'c':
            {
                for (int i = 0; i < ilosc_t; i++)
                {
                    Odwroc(Tablice, Rozmiar);
                }
                break;
            }
        default:
            {
                std::cout << "Niepoprawna opcja!" << std::endl;
            }
        }
    }
    // inicjalizacja zmiennych uzywanych do liczenia czasu
    Czas sort_szyb;
    std::cout << "***********************************" << std::endl;
    std::cout << "** ROZPOCZETO SORTOWANIE SZYBKIE **" << std::endl;
    // rozpoczecie liczenia czasu oraz sortowania
    sort_szyb.Start();
    for (int i = 0; i < ilosc_t; i++)
    {
        Sortowanie_Szybkie(Tablice[i], 0, Rozmiar - 1);
    }
    sort_szyb.Stop();
    sort_szyb.Pokaz_Czas();
    // funkcja sluzaca do wyswietlania posortowanych tablic
    
    /*for (int i = 0; i < ilosc_t; i++)
    {
        for(int j = 0; j <Rozmiar; j++)
            std::cout << j+1 << "-" << Tablice[i][j] << std::endl;
        std::cout << std::endl;
    }*/
    for (int i = 0; i < ilosc_t; i++)
    {
        delete[] Tablice[i];
    }
    delete[] Tablice;
}
