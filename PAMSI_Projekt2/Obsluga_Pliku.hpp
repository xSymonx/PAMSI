//
//  Obsluga_Pliku.hpp
//  Pamsi projekt 2
//
//  Created by Szymon Sztymar on 07/05/2021.
//

#ifndef Obsluga_Pliku_hpp
#define Obsluga_Pliku_hpp
#include <iostream>
#include <fstream>
#include <stdio.h>
void zapisz_do_pliku(int wierzcholki, int liczba_krawedzi, std::fstream &Plik);
void generuj_graf(std::fstream &Plik);
#endif /* Obsluga_Pliku_hpp */
