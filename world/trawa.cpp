#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat *p) :Roslina(p){
	sila = 0;
	inicjatywa = 0;
	pionek = '#';
}

void Trawa::rozsianie(int i, int j)
{
	cout << "Trawa sie rozsiewa"<<endl;
	
	Organizm *nowy = new Trawa(p);
	nowy->setXY(i, j);
	p->dodajOrganizm(nowy);
}