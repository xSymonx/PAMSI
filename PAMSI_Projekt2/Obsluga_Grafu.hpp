//
//  Obsluga_Grafu.hpp
//  Pamsi projekt 2 final
//
//  Created by Szymon Sztymar on 07/05/2021.
//

#ifndef Obsluga_Grafu_hpp
#define Obsluga_Grafu_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Pomiar_Czasu.cpp"
#include "Lista_Sasiedztwa.cpp"
#include "Obsluga_Pliku.hpp"
void przeszukaj_graf(std::ifstream &Plik);
void Bellman_Ford_Lista(int wierzcholki, int krawedzie, int poczatkowy, Lista_Sasiedztwa **Tab);
void wyswietl_liste(Lista_Sasiedztwa **Tab, int wierzcholki);
void wczytaj_graf_forma_listy(int &wierzcholki, int &krawedzie, int &poczatek, int **graf, Lista_Sasiedztwa **tablica_list, Lista_Sasiedztwa *list);
void lista_znajdz_droge(int **graf, int &wierzcholki, int &krawedzie, int &poczatek, std::fstream &Plik_wyj);
void Bellman_Ford_Macierz(int wierzcholki, int krawedzie, int poczatkowy, int **graf_macierz);
void wyswietl_macierz(int **graf_maceirz, int wierzcholki);
void** wczytaj_graf_forma_macierz(int &wierzcholki, int &krawedzie, int &poczatek, int **graf, int **graf_macierz);
void macierz_znajdz_droge(int **graf, int &wierzcholki, int &krawedzie, int &poczatek, std::fstream &Plik_wyj);
void wyswietl_droge(int wierzcholek, int *poprzedni, int *koszt);
void **pobierz_graf(int **graf, int &wierzch, int &kraw, int &pocz, std::ifstream &Plik_wej);
void znajdz_droge(std::ifstream &Plik_wej);
#endif /* Obsluga_Grafu_hpp */
