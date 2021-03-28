//
//  main.cpp
//  PAMSI_Projekt1
//
//  Created by Szymon Sztymar on 24/03/2021.
//

#include <iostream>
#include "Sortowanie.cpp"

int main()
{
    // Menudy w ktorym uzytkownika wybiera sposob sortowania
    std::cout << "WYBIERZ RODZAJ SORTOWANIA" << std::endl;
    std::cout << "a. Sortowanie hybrydowe " << std::endl;
    std::cout << "b. Sortowanie przez scalanie " << std::endl;
    std::cout << "c. Sortowanie Szybkie " << std::endl;
    char Wybor;
    std::cin >> Wybor;
    
    switch(Wybor)
    {
        case 'a':
        {
        Wykonaj_Sortowanie_Hybrydowe();
        break;
        }
        case 'b':
        {
            Wykonaj_Sortowanie_Przez_Scalanie();
            break;
        }
        case 'c':
        {
            Wykonaj_Sortowanie_Szybkie();
            break;
        }
    }
}
