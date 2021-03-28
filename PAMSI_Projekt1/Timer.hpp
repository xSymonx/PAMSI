//
//  Timer.hpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 24/03/2021.
//

#ifndef Timer_hpp
#define Timer_hpp
#include <time.h>

#include <stdio.h>

/* Klasa czas sluzaca do liczenia czasu trwania algorytmu, przechowuje czas w ms */
/* obiekt przechowuje wartosc dwoch wywolan start i stop oraz liczy ich roznice */
class Czas{
    clock_t start;
    clock_t stop;
public:
    void Start()
    {
        start = clock();
    }
    void Stop()
    {
        stop = clock();
    }
    void Pokaz_Czas()
    {
        std::cout << "Czas wykonywania wybranego sortowania: ";
        std::cout << ((stop - start)/(CLOCKS_PER_SEC / 1000));
        std::cout << " milisekund" << std::endl;
    }
};

#endif /* Timer_hpp */
