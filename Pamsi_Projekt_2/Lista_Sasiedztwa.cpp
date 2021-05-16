//
//  Lista_Sasiedztwa.cpp
//  Pamsi projekt 2 final
//
//  Created by Szymon Sztymar on 14/05/2021.
//

#include <stdio.h>
static int max = 2147483647;

struct Lista_Sasiedztwa {       // struktura przechowywujaca sasiedni wierzcholek
    int wierz;                  // zmienna wierz przechowuje sasiednie wierzcholki
    int waga;                  // zmienna waga przechowuje wage krawedzi miedzy wierzcholkami
    Lista_Sasiedztwa *next;     // wskaznik na nastepny element listy
};
