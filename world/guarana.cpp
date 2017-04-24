#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(Swiat *p) :Roslina(p){
	sila = 0;
	inicjatywa = 0;
	pionek = '@';
}

void Guarana::rozsianie(int i, int j)
{
	cout << "Guarana sie rozsiewa" << endl;
	
	Organizm *nowy = new Guarana(p);
	nowy->setXY(i, j);
	p->dodajOrganizm(nowy);
}