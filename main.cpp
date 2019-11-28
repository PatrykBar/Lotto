#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#define numbersOfData 6334

int NumberOfNumbers[49];

struct LineOfFile
{
    std::string Lp;
    std::string Data;
    int Numbers[6];
};

LineOfFile Line[numbersOfData];

void OdczytPliku();
void WyswietlDane();
void ZliczanieWystapien();
void OdczytDanych();

int main()
{

    OdczytPliku();
    //WyswietlDane();
    OdczytDanych();

    //plik.tellg(); //funkcja odczytuj¹ca w jakiej pozycji w plkiku jest znacznik
    //plik.seekg(0); //Funkcja ustawiaj¹ca znacznik na pocz¹tku pliku
    //plik.seekg(0, plik.end); //Funkcja ustawiaj¹ca znacznik na koñcu pliku

    return 0;
}

void OdczytPliku()
{
    std::ifstream plik;
    std::string nazwa;
    std::cout << "Nazwa pliku: ";
    std::cin >> nazwa;

    plik.open(nazwa.c_str() , std::ios_base::in | std::ios_base::app);

    if (plik.is_open())
    {
        int i=0;
        while (i<numbersOfData)
        {
            plik >> Line[i].Lp;
            plik >> Line[i].Data;

            for (int j=0; j<6; j++)
            {
                plik >> Line[i].Numbers[j];
                plik.ignore(1,','); // Ignoruje max 10 znaków do napotkania odpowiedniego znaku
            }

            i++;
        }
        plik.close();
    }
    else
        std::cout << "Plik nie istnieje :( " << std::endl;
}

void WyswietlDane()
{
    /*for (int i=0; i<numbersOfData; i++)
    {
        std::cout << Line[i].Lp << " " << Line[i].Data << std::endl;
    }*/

    for (int i=0; i<numbersOfData; i++)
    {
        for (int j=0; j<6; j++)
        {
            std::cout << Line[i].Numbers[j] << " ";
        }
        std::cout << std::endl;
    }
}

void ZliczanieWystapien()
{
    for (int i=0; i<49; i++)
    {
        NumberOfNumbers[i]=0;
    }

    for (int i=0; i<numbersOfData; i++)
    {
        for (int j=0; j<6; j++)
        {
            for (int k=0; k<49; k++)
            {
                if (Line[i].Numbers[j]==k+1)
                {
                    NumberOfNumbers[k]++;
                    break;
                }
                else
                    break;
            }
        }
    }
}

void OdczytDanych()
{
    for (int i=0; i<49; i++)
    {
        std::cout << "Ilosc elementu " << i+1 << " : " << NumberOfNumbers[i] << std::endl;
    }
}
