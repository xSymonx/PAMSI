//
//  ruch_komputera.cpp
//  Pamsi projekt 3
//
//  Created by Szymon Sztymar on 21/05/2021.
//

#include "ruch_komputera.hpp"
#include <iostream>

/*  Funkcja odpowiada za ruch atakujacy  */
void ruch_kom_atakujacy(char tab[], int rozmiar_rzedu, int m_ostat_X, int licznik)
{
    int n = 0;
    int pom = 0;
    int y;
    int rozmiar = rozmiar_rzedu * rozmiar_rzedu; // obliczamy rozmiar planszy
    if(tab[pom+1] == 0 && (pom + 1) < rozmiar)
    { // sprawdzamy czy pole obok poprzedniego znaku jest puste oraz czy
        std::cout << "T1";
        y = pom + 1;        // nie wychodzi poza zakres planszy
        tab[y] = 'O';   // wstawiamy znak
    }
    else if(tab[pom+2] == 0 && (pom + 2) < rozmiar)
    { // sprawdzamy czy pole obok poprzedniego znaku jest puste oraz czy
        std::cout << "T2";
        y = pom + 2;        // nie wychodzi poza zakres planszy
        tab[y] = 'O';   // wstawiamy znak
    }
    else if(tab[pom-1] == 0 && (pom - 1) > 0)
    { // sprawdzamy czy pole przed poprzednim znakiem jest puste oraz czy
        y = pom - 1;    // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }
    else if(tab[pom-2] == 0 && (pom - 2) > 0)
    { // sprawdzamy czy pole przed poprzednim znakiem jest puste oraz czy
        y = pom - 2;    // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }
    else if(tab[pom-rozmiar_rzedu] == 0 && (pom - rozmiar_rzedu) > 0)
    {   // sprawdzamy czy pole pod poprzednim znakiem jest puste oraz czy
        y = pom - rozmiar_rzedu;    // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }
    else if(tab[pom-(2*rozmiar_rzedu)] == 0 && (pom - (2*rozmiar_rzedu)) > 0)
    {   // sprawdzamy czy pole pod poprzednim znakiem jest puste oraz czy
        y = pom - (2*rozmiar_rzedu);    // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }

    else if(tab[pom+rozmiar_rzedu] == 0 && (pom + rozmiar_rzedu) < rozmiar)
    {   // sprawdzamy czy pole nad poprzednim znakiem jest puste oraz czy
        y = pom + rozmiar_rzedu;       // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }
    else if(tab[pom+(2*rozmiar_rzedu)] == 0 && (pom + (2 * rozmiar_rzedu)) < rozmiar)
    {   // sprawdzamy czy pole nad poprzednim znakiem jest puste oraz czy
        y = pom + (2*rozmiar_rzedu);   // nie wychodzi poza zakres planszy
        tab[y] = 'O';    // wstawiamy znak
    }
    else        // jesli nie mamy wolnego pola wstawiamy znak w olne dowolne pole
    {
        m_ostat_X = rand() % rozmiar_rzedu;
        n = tab[m_ostat_X];
        while( n != 0)
        {
            m_ostat_X = rand() % rozmiar_rzedu;
            n = tab[m_ostat_X];
        }
        tab[m_ostat_X]= 'O';
        pom = m_ostat_X;
    }
}
/*  Funkcja odpowiada za ruch broniacy */
void ruch_kom_broniący(char tab[], int rozmiar_rzedu, int m_ostat_X, int a)
{
    int miejsce = (rozmiar_rzedu / 2) + 1; // obliczamy srodek kazdego wiersza
    int rzad = ((m_ostat_X - 1) / 5);
    int tym = 0;
    int n = 0;
    int rozmiar = rozmiar_rzedu * rozmiar_rzedu; // obliczamy rozmiar planszy
    tym = (rzad * rozmiar_rzedu) + miejsce; // wstawiamy znak w sordek wiersza w ktorym gracz wstawil znak
    
    /*if(tab[tym] == 0)
    {
        //std::cout << "T1";
        tab[tym] = 'O';
        
    }
     else*/ if(tab[m_ostat_X+rozmiar_rzedu] == 0 && (m_ostat_X + rozmiar_rzedu) < rozmiar && (a++ % 2) == 0)
     {           // wstawiamy znak nad znakiem gracza
         std::cout << a % 2;
         tab[m_ostat_X+rozmiar_rzedu] = 'O';
     }
    else if(tab[m_ostat_X+1] == 0  && (m_ostat_X + 1) < rozmiar)    // wstwaimy znak za znakiem gracza
    {
        //std::cout << m_ostat_X + rozmiar_rzedu;
        tab[m_ostat_X+1] = 'O';
    }
    else if(tab[m_ostat_X-1] == 0 && (m_ostat_X - 1) > 0) // wstawiamy znak przed znakiem gracza
    {
        tab[m_ostat_X-1] = 'O';
    }
    else if(tab[m_ostat_X-rozmiar_rzedu] == 0 && (m_ostat_X - rozmiar_rzedu) > 0)
    {       // wstawiamy znak pod znakiem gracza
        tab[m_ostat_X-rozmiar_rzedu] = 'O';
    }
    else if(tab[m_ostat_X+rozmiar_rzedu] == 0 && (m_ostat_X + rozmiar_rzedu) > rozmiar)
    {       // jesli pole nad znakiem jest zajete poza plansza
        if(tab[m_ostat_X-(2*rozmiar_rzedu)] == 0) // wstawiamy znak dwa wiersze pod
            tab[m_ostat_X-(2*rozmiar_rzedu)] = 'O';
        else
        {   // pole dwa wiersze pod zjate wstawiamy dowolnie
            m_ostat_X = rand() % rozmiar_rzedu;
            n = tab[m_ostat_X];
            while( n != 0)
            {
                m_ostat_X = rand() % rozmiar_rzedu;
                n = tab[m_ostat_X];
            }
            tab[m_ostat_X]= 'O';
        }
    }
    else if(tab[m_ostat_X-rozmiar_rzedu] == 0 && (m_ostat_X - rozmiar_rzedu) < 0)
    {   // jesli pole pod znakiem jest zajete poza plansza
        if(tab[m_ostat_X+(2*rozmiar_rzedu)] == 0) // wstawiamy znak dwa wiersze nad
            tab[m_ostat_X+(2*rozmiar_rzedu)] = 'O';
        else
        {   // pole dwa wiersze nad zjate wstawiamy dowolnie
            m_ostat_X = rand() % rozmiar_rzedu;
            n = tab[m_ostat_X];
            while( n != 0)
            {
                m_ostat_X = rand() % rozmiar_rzedu;
                n = tab[m_ostat_X];
            }
            tab[m_ostat_X]= 'O';
        }
    }
    else
    {
        // brak mozliowsci wtedy dowolnie
        m_ostat_X = rand() % rozmiar_rzedu;
        n = tab[m_ostat_X];
        while( n != 0)
        {
            m_ostat_X = rand() % rozmiar_rzedu;
            n = tab[m_ostat_X];
        }
        tab[m_ostat_X]= 'O';
    }
    
}
    
/* Komputer wykonuje ruch na dwa sposoby raz atakujac raz sie broniac */
void ruch_komputera(char tab[], int rozmiar_rzedu, int m_ostat_X, int licznik, int b)
{
    if(licznik > 4 && (licznik % 2) == 0)
    ruch_kom_atakujacy(tab, rozmiar_rzedu, m_ostat_X, licznik);
    else
    ruch_kom_broniący(tab, rozmiar_rzedu, m_ostat_X, b);
}

