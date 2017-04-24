#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(Swiat *p) :Roslina(p){
	sila = 0;
	inicjatywa = 0;
	pionek = '*';
}

void Mlecz::rozsianie(int i, int j)
{
	Organizm *nowy = new Mlecz(p);
	nowy->setXY(i, j);
	p->dodajOrganizm(nowy);
}

void Mlecz::akcja(){
	for (int i = 0; i<3; i++){
		if (prawdopodobienstwo(SZANSA) > 0)
		{
			int i = x;
			int j = y;
			losowanie(i, j);
			if (p->wolnePole(i, j) == true)
			{
				cout << "Mlecz sie rozsiewa"<<endl;
				
				rozsianie(i, j);
			}
		}
	}
}