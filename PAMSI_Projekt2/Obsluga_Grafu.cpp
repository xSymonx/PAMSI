//
//  Obsluga_Grafu.cpp
//  Pamsi projekt 2 final
//
//  Created by Szymon Sztymar on 07/05/2021.
//

#include "Obsluga_Grafu.hpp"
void przeszukaj_graf(std::ifstream &Plik)
{
    Plik.open("Graf.txt");
    znajdz_droge(Plik);
    Plik.close();
}



void Bellman_Ford_Lista(int wierzcholki, int krawedzie, int poczatkowy, Lista_Sasiedztwa **tablica_list)
{
    Lista_Sasiedztwa *Tablica_sasiadow;
    
    int* koszt;                     // tablica dynamiczna przechowujaca koszty dosjcia do danego wierzcholka
    koszt = new int [wierzcholki];
    int *poprzedni;                    // tablica dynamiczna przechowywujaca poprzednie wierzcholki
    poprzedni = new int [wierzcholki];
    
    for(int i = 0; i < wierzcholki; i++)  // Petla ustawia tablice poprzednich wierzcholkow na -1
    {                                     // czyli wierzcholek poprzedzajcy zerowy
        poprzedni[i] = -1;               // ustawienie kosztu dojscia na maksymalny int aby mozna go bylo zmiejszac
        koszt[i] = max;
    }
    
    koszt[poczatkowy] = 0;     // koszt dojscia do wierzcholka 0 z wierzcholka poczatkowego (0) jest równy 0
    for(int i = 1; i < wierzcholki; i++)    // Pętla relaksacji
    {
        for(int j = 0; j < wierzcholki; j++) // przechodzimy przez wierzcholki grafu
        {
            for(Tablica_sasiadow = tablica_list[j]; Tablica_sasiadow; Tablica_sasiadow = Tablica_sasiadow->next)    // przegladamy liste sasiadow
            {
                if(koszt[j] != max && koszt[Tablica_sasiadow->wierz] > koszt[j] + Tablica_sasiadow->waga) // sprawdzamy czy aktualny koszt dotarcia do wiezrcholka jest mniejszy od tego znalezionego dotychczs
                {
                    koszt[Tablica_sasiadow->wierz] = koszt[j] + Tablica_sasiadow->waga;
                    poprzedni[Tablica_sasiadow->wierz] = j;
                }
            }
        }
    }
    
    std::cout << "Lista sasiedztwa: " << std::endl;
    wyswietl_droge(wierzcholki, poprzedni, koszt);
}



  
void wyswietl_liste(Lista_Sasiedztwa **tablica_list, int wierzcholki)
{
    Lista_Sasiedztwa *lista_pom;        // tablica pomocnicza przechowujaca wartosc oryginalnej tablicy
    std::cout << "Lista Sasiedztwa: " << std::endl;
    for(int i = 0; i < wierzcholki; i++)  // funkcja wyswietla liste wierzcholkow
    {
        std::cout << "Lista[" << i << "] = ";
        lista_pom = tablica_list[i];
        while(lista_pom)
        {
            std::cout << lista_pom->wierz << " ";
            lista_pom = lista_pom->next;
        }
        std::cout << std::endl;
    }
    delete [] lista_pom;
}

void wczytaj_graf_forma_listy(int &wierzcholki, int &krawedzie, int &poczatek, int **graf, Lista_Sasiedztwa **tablica_list, Lista_Sasiedztwa *lista)
{
    int wierz_pocz;  // inicjuemy trzy zmienne oznaczajce wierzcholki tworzace krawedz oraz wage
    int wierz_kon;
    int waga;
            // funkcja uzupelnia tablice nullami
    for(int i = 0; i < wierzcholki; i++)
    {
        tablica_list[i] = NULL;
    }
    
    for(int i = 0; i < krawedzie; i++)
    {
        wierz_pocz = graf[i][0];
        wierz_kon = graf[i][1];
        waga = graf[i][2];
        
        lista = new Lista_Sasiedztwa;
        lista->wierz = wierz_kon;
        lista->waga = waga;
        lista->next = tablica_list[wierz_pocz];
        tablica_list[wierz_pocz] = lista;
    }
    
        // tworzenie grafu nieskierowanego
    for(int i = 0; i < krawedzie; i++)
    {
        wierz_kon = graf[i][0]; // wczytujemy wartosci do listy z grafu
        wierz_pocz = graf[i][1];  // wczytanego z pliku
        waga = graf[i][2];
        
        lista = new Lista_Sasiedztwa;
        lista->wierz = wierz_kon;
        lista->waga = waga;
        lista->next = tablica_list[wierz_pocz];
        tablica_list[wierz_pocz] = lista;
    }
   // wyswietl_liste(tablica_list, wierzcholki);
}


void lista_znajdz_droge(int **graf, int &wierzcholki, int &krawedzie, int &poczatek, std::fstream &Plik_wyj)
{
    Czas BFL;
    Lista_Sasiedztwa **tablica_list;        // struktury reprezentujace graf
    Lista_Sasiedztwa *lista;
    Lista_Sasiedztwa *wyczysc;
    
    tablica_list = new Lista_Sasiedztwa * [wierzcholki];   // alokacja pamieci dla listy saiedztwa
    wczytaj_graf_forma_listy(wierzcholki, krawedzie, poczatek, graf, tablica_list, lista);
    
    BFL.Start();                    // pomiar czasu oraz uruchomienie algorytmu Bellmana-Forda
    Bellman_Ford_Lista(wierzcholki, krawedzie, poczatek, tablica_list);
    BFL.Stop();
    for(int i = 0; i < wierzcholki; i++)  // funkcja wyswietla liste wierzcholkow
    {
        lista = tablica_list[i];
        while(lista)
        {
            wyczysc = lista;
            lista = lista->next;
            delete wyczysc;
        }
    }
    delete [] tablica_list;
    double czas = BFL.Oblicz_Czas();
    Plik_wyj << "Czas trwania dla listy przy wierzcholku: " << wierzcholki << " i: " << (int) ((krawedzie * 100) / (wierzcholki * (wierzcholki - 1.25) / 2)) << "% gestosci: " << czas << "ms";

}

void Bellman_Ford_Macierz(int wierzcholki, int krawedzie, int poczatkowy, int **graf_macierz)
{
    int* koszt;                     // tablica dynamiczna przechowujaca koszty dosjcia do danego wierzcholka
    koszt = new int [wierzcholki];
    int *poprzedni;                    // tablica dynamiczna przechowywujaca poprzednie wierzcholki
    poprzedni = new int [wierzcholki];
    
    for(int i = 0; i < wierzcholki; i++)  // Petla ustawia tablice poprzednich wierzcholkow na -1
    {                                     // czyli wierzcholek poprzedzajcy zerowy
        poprzedni[i] = -1;               // ustawienie kosztu dojscia na maksymalny int aby mozna go bylo zmiejszac
        koszt[i] = max;
    }
    
    koszt[poczatkowy] = 0;     // koszt dojscia do wierzcholka 0 z wierzcholka poczatkowego (0) jest równy 0

    for(int i = 1; i < wierzcholki; i++)    // Pętla relaksacji
    {
        for(int j = 0; j < wierzcholki; j++) // przechodzimy przez wierzcholki grafu

        {
            for(int m = 0; m < wierzcholki; m++)    // przegladamy macierz sasiadow
            {
                if(koszt[j] != max && graf_macierz[m][j] != 0 && koszt[m] > koszt[j] + graf_macierz[m][j]) // sprawdzamy czy aktualny koszt dotarcia do wiezrcholka jest mniejszy od tego znalezionego dotychczs
                {
                    koszt[m] = koszt[j] + graf_macierz[m][j];
                    poprzedni[m] = j;
                }
            }
        }
    }
    
    std::cout << "Macierz sasiedztwa: " << std::endl;
    wyswietl_droge(wierzcholki, poprzedni, koszt);
}


void wyswietl_macierz(int **graf_macierz, int wierzcholki)
{
    std::cout << "Macierz Sasiedztwa: " << std::endl;
    for(int i = 0; i < wierzcholki; i++)  // funkcja wyswietla macierz sasiedztwa
    {
        for(int j = 0; j < wierzcholki; j++)
        {
            std::cout << graf_macierz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void** wczytaj_graf_forma_macierz(int &wierzcholki, int &krawedzie, int &poczatek, int **graf, int **graf_macierz)
{
    int wierz_pocz;  // inicjuemy trzy zmienne oznaczajce wierzcholki tworzace krawedz oraz wage
    int wierz_kon;
    int waga;
    int pom = 0;
    
    
            // funkcja uzupelnia tablice zerami
    for(int i = 0; i < wierzcholki; ++i)
    {
        for(int j = pom; j < wierzcholki; ++j)
        {
            graf_macierz[i][j] = 0;
            graf_macierz[j][i] = 0;
        }
        pom++;
    }
    
    for(int i = 0; i < wierzcholki; ++i)
    {
        wierz_pocz = graf[i][0]; // wczytujemy wartosci do macierzy z grafu
        wierz_kon = graf[i][1];  // wczytanego z pliku
        waga = graf[i][2];
        
        graf_macierz[wierz_pocz][wierz_kon] = waga; // wczytujemy dane do macierzy sasiedztwa dla grafu skierowanego
        graf_macierz[wierz_kon][wierz_pocz] = waga;
    }
  //  wyswietl_macierz(graf_macierz, wierzcholki);
    return 0;
}


void macierz_znajdz_droge(int **graf, int &wierzcholki, int &krawedzie, int &poczatek, std::fstream &Plik_wyj)
{
    Czas BFL;
    
    int **graf_macierz;
    graf_macierz = new int *[wierzcholki];   // alokacja pamieci dla macierzy saiedztwa
    for(int i = 0; i < wierzcholki; i++)
    {
        graf_macierz[i] = new int [wierzcholki];
    }
    
    wczytaj_graf_forma_macierz(wierzcholki, krawedzie, poczatek, graf, graf_macierz); // tworzymy macierz sasiedztwa
    
    BFL.Start();                    // pomiar czasu oraz uruchomienie algorytmu Bellmana-Forda
    Bellman_Ford_Macierz(wierzcholki, krawedzie, poczatek, graf_macierz);
    BFL.Stop();
    
    for(int i = 0; i < wierzcholki; i++)  // funkcja wyswietla liste wierzcholkow
    {
        delete [] graf_macierz[i];
    }
    delete [] graf_macierz;
    
   double czas = BFL.Oblicz_Czas();
  /*  Plik_wyj << "Czas trwania dla macierzy przy wierzcholku: " << wierzcholki << " i: " << ((krawedzie * 100) / (wierzcholki * (wierzcholki - 1) / 2)) << "% gestosci: " << czas << "ms" << std::endl; */
   Plik_wyj << " ,dla macierzy: "  << czas << "ms" << std::endl;

}


void wyswietl_droge(int wierzcholki, int *poprzedni, int *koszt)
{
    int *tab_wysw = new int [wierzcholki];       // alokacja pamieci dla tablicy do wyswietlania dorgi
    int x = 0;
    int j;
    
    for(int i = 0; i < wierzcholki; i++)
    {
       // std::cout << "Droga dojscia do wierzcholka: " << i;
        std::cout  << i << " droga: ";
        for(j = i; j != -1 && x < wierzcholki; j = poprzedni[j])
        {
                tab_wysw[x++] = j;
        }
        while(x)
        {
            std::cout << tab_wysw[--x] << '\t';
        }
       // if(i == tab_wysw[x+1])
         //   std::cout << "$ " << 0 << std::endl;
       // else
            std::cout << "Koszt: " << koszt[i] << std::endl;
    }
    delete [] tab_wysw;
}


void **pobierz_graf(int **graf, int &kraw, std::ifstream &Plik_wej)
{
    for(int i = 0; i < kraw; i++)   // Wczytanie grafu z pliku wejsciowego do tablicy dwu wymiarowej
    {
        Plik_wej >> graf[i][0];
        Plik_wej >> graf[i][1];
        Plik_wej >> graf[i][2];
        /*std::cout<<graf[i][0]<<" ";
        std::cout<<graf[i][1]<<" ";
        std::cout<<graf[i][2]<<std::endl;*/
    }
    return 0;
}



void znajdz_droge(std::ifstream &Plik_wej)
{
    int wierzcholki;        // zmienne przechowujace ilosc wierzcholkow krawedzi i wierzolek startowy ktore zostana wczytane z pliku
    int krawedzie;
    int w_pierwszy;
    int **graf;
    
    
    std::fstream Plik_wyj;
    Plik_wyj.open("Wyniki.txt", std::ios_base::app);
    
    for(int i = 0; i < 2000; i++)           // Petla wczytujaca dane z pliku
    {
        Plik_wej >> wierzcholki;
        Plik_wej >> krawedzie;
        Plik_wej >> w_pierwszy;
        
        graf = new int *[krawedzie];
        for(int j = 0; j < krawedzie; j++)          // petla tworzaca tablice 3 wymiarowych tablic przechowujacych poczatek, koniec i wage krawedzi kraweddzi
        {
            graf[j] = new int [3];
        }
        pobierz_graf(graf, krawedzie, Plik_wej);
        lista_znajdz_droge(graf, wierzcholki, krawedzie, w_pierwszy, Plik_wyj);
        //macierz_znajdz_droge(graf, wierzcholki, krawedzie, w_pierwszy, Plik_wyj);
        for(int j = 0; j < krawedzie; j++)          // usuwanie zaalokowanych dynamicznie tablic
        {
            delete [] graf[j];
        }
        delete [] graf;
    }
    Plik_wyj.close();
}
