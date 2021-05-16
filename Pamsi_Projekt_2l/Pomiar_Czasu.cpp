//
//  Pomiar_Czasu.cpp
//  Pamsi projekt 2 final
//
//  Created by Szymon Sztymar on 14/05/2021.
//

#include <stdio.h>

/* Klasa czas sluzaca do liczenia czasu trwania algorytmu, przechowuje czas w ms */
/* obiekt przechowuje wartosc dwoch wywolan start i stop oraz liczy ich roznice */
class Czas{
    clock_t start;
    clock_t stop;
    double czas;
public:
    void Start()
    {
        start = clock();
    }
    void Stop()
    {
        stop = clock();
    }
    double Oblicz_Czas()
    {
        czas = (double) (stop - start) / CLOCKS_PER_SEC * 1000;
        return czas;
    }
};
