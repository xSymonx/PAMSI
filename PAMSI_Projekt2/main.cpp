#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Obsluga_Grafu.cpp"

int main()
{
    char wybor;          

    std::fstream Graf;
    std::ifstream Plik_wej;      

    srand(time(NULL));      

    
    while(1)
    {
        std::cout << "\tGraf" <<std::endl;
        std::cout << "Wybierz  czynnosc:" <<std::endl;
        std::cout << "a) Utworz graf" <<std::endl;
        std::cout << "b) Szukaj drogi" <<std::endl;
        std::cout << "k) Koniec " <<std::endl;
        std::cin >> wybor;
        
        switch(wybor)
        {
            case 'a':
            {
                generuj_graf(Graf);
                break;
            }
            case 'b':
            {
                przeszukaj_graf(Plik_wej);
                break;
            }
            case 'k':
                break;
            default:
            {
                std::cout << "BLEDNA OPCJA!" << std::endl;
                break;
            }
        }
        if(wybor == 'k')
            break;
    }
    return 0;
}
