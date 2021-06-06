//
//  Wygrana.cpp
//  Pamsi projekt 3
//
//  Created by Szymon Sztymar on 20/05/2021.
//

#include "Wygrana.hpp"

/*  Funkcja sprawdza wygrana w pionie poziomie oraz na ukos zwracajac true jesli */
/*  jest odpowidnia ilosc znakow w lini oraz false jesli nie ma */
bool sprawdz_wygrana(char tab[], int rozmiar, int ilosc_wygranych, char znak)
{
        int kontrolna = 0; // zmienna słuzaca do zliczania znakow w lini
        int rozm = sqrt((rozmiar-1)); // zmienna sluzaca do urywania zliczania znakow
        int stop = rozm - ilosc_wygranych + 1; // jesli wychodza poza jeden rzad
        char **pomocnicza = new char *[rozm];  // zainicjalizowanie tablicy 2D
        for(int i = 0; i < rozm; i++)       // oraz przepisanie jej wartosci z tablicy
        {                                   // z wartosciami planszy, tablica uzywana
            pomocnicza[i] = new char [rozm];    // do sprawdzania wygranej w
        }                                       //piuonie i poziomie
        
        int k = 1;
        for(int i = 0; i < rozm; i++)
        {
            for(int j = 0; j < rozm; j++)
            {
                pomocnicza[i][j] = tab[k];
                k++;
            }
        }
        
                /* Poziom */
        /* Sprawdzamy czy w lini poziomej wystepuje odpowiednia ilosc znakowdo wygranej  */
        for(int i = 0; i < rozm; i++)
        {
            for(int j = 0; j < rozm; j++)
            {
                int war = stop;  // zmienna pilnuje aby wyzerowac ilosc znakow gdy
                if(kontrolna < ilosc_wygranych && pomocnicza[i][j] == znak)
                {                      // czesc z nich wychodzi poza wiersz planszy
                    if(kontrolna == 0 && j < war)  // okresalmy ilosc miejsc w ktorych
                    {               //molziwe jest postawienie nzaku gdy jest on pierwszym
                        kontrolna += 1; // jesli warunek spelniony kontrolna rosnie o 1
                    }                   // poniewaz jest to pierwszy znak
                    else if(kontrolna == 1 && j < (war + 1))
                    {           // sprawdzamy czy znak znajduje sie obok poprzedniego
                        kontrolna += 1;     // oraz czy ciag znakow nie wyjdzie poza rzad
                    }
                    else if(kontrolna == 2 && j < (war + 2))
                    {               // sprawdzamy czy znak znajduje sie obok poprzedniego
                        kontrolna += 1;     // oraz czy ciag znakow nie wyjdzie poza rzad
                    }
                    else
                    {
                        break;
                    }
                }       // sprawdzamy czy gracz wygral 
                else if(kontrolna == ilosc_wygranych)
                {
                    return true;
                }
                else
                    kontrolna = 0;
            }
        }
        kontrolna = 0;  
        /* Pion */
    /* Sprawdzamy czy w lini pionowej wystepuje odpowiednia ilosc znakowdo wygranej  */
        for(int i = 0; i < rozm; i++)
        {
            for(int j = 0; j < rozm; j++)
            {       // sprawdzamy czy pole jest znakiem
                if(kontrolna < ilosc_wygranych && pomocnicza[j][i] == znak)
                {           // jesli jest znakiem zwiekszamy kontrolna i przechodzimy
                    kontrolna += 1; // w to samo pole wiersz nizej i sprawdzamy vczy jest takie same
                } // sprawdzamy czy ilosc znakow jest wystarczjaca do wygranej
                else if(kontrolna == ilosc_wygranych)
                {
                    return true;
                }
                else
                    kontrolna = 0;
            }
        }
        int pom = 0;
        kontrolna = 0;
        /* Ukos od lewej do prawej */
        /* Sprawdzamy czy na ukos od lewej do prawej  wystepuje odpowiednia ilosc */
        /* znakowd o wygranej  */
        for(int j = 1; j <= rozmiar; j++)
        {
            pom = stop;
            for(int i = j; i <= rozmiar;)
            {
                int tym = ((i - 1) / rozm);
                int war = ((tym * rozm) + pom);
                // sprawdzamy czy pole jest zankiem czy zerem
                if(kontrolna < ilosc_wygranych && tab[i] == znak)
                {
                    if(kontrolna == 0 && i <= war)
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm + 1); // przechodzimy na kolejny zank
                    }
                    else if(kontrolna == 1 && i <= (war + 1))
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm + 1); // przechodzimy na kolejny zank
                    }
                    else if(kontrolna == 2 && i <= (war + 2))
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm + 1); // przechodzimy na kolejny zank
                    }
                    else
                    {
                        kontrolna = 0;
                        i += (rozm + 1);
                    }
                }
                else if(kontrolna == ilosc_wygranych)
                {
                    return true;
                }
                else
                {
                    i += rozm + 1; // przechodzimy na kolejny zank
                    kontrolna = 0;
                }
            }
        }
        
        pom = 0;
        kontrolna = 0;
        /* Ukos od prawej do lewej*/
        /* Sprawdzamy czy na ukos od prawej do lewej wystepuje odpowiednia ilosc */
        /* znakowd o wygranej  */
        for(int j = 1; j <= rozmiar; j++)
        {
            pom = stop;
            for(int i = j; i <= rozmiar;)
            {
                int tym = ((i - 1) / rozm);
                int war = ((tym * rozm) + pom);
                // sprawdzamy czy pole jest zankiem czy zerem
                if(kontrolna < ilosc_wygranych && tab[i] == znak)
                {
                    if(kontrolna == 0 && i >= war)
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm - 1); // przechodzimy na kolejny zank
                    }
                    else if(kontrolna == 1 && i >= (war - 1))
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm - 1); // przechodzimy na kolejny zank
                    }
                    else if(kontrolna == 2 && i >= (war - 2))
                    { // sprawdzamy czy to pierwszy znak i czy nie wyjdzie poza plansze
                        kontrolna += 1;
                        i += (rozm - 1); // przechodzimy na kolejny zank
                    }
                    else
                    {
                        i += rozm + 1; // przechodzimy na kolejny zank
                        kontrolna = 0;
                    }
                }
                else if(kontrolna == ilosc_wygranych)
                {
                    return true;
                }
                else
                {
                    kontrolna = 0;
                    i += (rozm - 1); // przechodzimy na kolejny zank
                }
            }
        }
        
     // usuwamy zaalokowane dynamicznie tablice
        for(int i = 0; i < rozm; i++)
        {
            delete [] pomocnicza[i];
        }
        delete [] pomocnicza;
        return false;
}
