#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(Swiat *p) :Organizm(p){}

int Roslina::prawdopodobienstwo(double wspolczynnik_prawdopodobienstwa)		//wylicza prawdopodobienstwo
{
	double losowa_liczba_z_przedzialu = ((rand() % 100) + 1);			//wylosowanie liczby z przedzialu [1;100]
	double prawdopodobienstwo = losowa_liczba_z_przedzialu / 100;		//wyliczenie prawdopodobienstwa
	if (prawdopodobienstwo <= wspolczynnik_prawdopodobienstwa)
	{
		return 1;		
	}
	else
	{
		return -1;	
	}
}

void Roslina::akcja()
{
	if (prawdopodobienstwo(SZANSA) > 0)
	{
		int i = x;
		int j = y;
		losowanie(i, j);
		if (p->wolnePole(i, j) == true)
		{
			rozsianie(i, j);
		}
	}
}
