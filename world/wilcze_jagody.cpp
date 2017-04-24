#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(Swiat *p) :Roslina(p){
	sila = 99;
	inicjatywa = 0;
	pionek = 'x';
}

void WilczeJagody::rozsianie(int i, int j)
{
	cout << "Wilcze jagody sie rozsiewaja"<<endl;
	
	Organizm *nowy = new WilczeJagody(p);
	nowy->setXY(i, j);
	p->dodajOrganizm(nowy);
}