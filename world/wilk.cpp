#include "Wilk.h"
#include "Swiat.h"

Wilk::Wilk(Swiat* p):Zwierze(p){
		sila = 9;
		inicjatywa = 5;
		pionek = 'W';
}

void Wilk::rozmnazanie(){

	int i = x;
	int j = y;
	losowanie(i, j);
	if (p->wolnePole(i, j) == true)
	{
		Organizm *nowy = new Wilk(p);
		nowy->setXY(i, j);
		p->dodajOrganizm(nowy);
	}
}

void Wilk::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* wilk = p->znajdz(x, y, m);
	wilk->setUczestniczyl(true);

	if (napotkany->getPionek() == 'W')
	{
		//rozmnazanie();
	}
	else if (napotkany->getPionek() != 'W'){
		if (napotkany->getSila() > sila)
		{
			cout << "Wilk ginie"<<endl;
			
			p->usunOrganizm(m);
			delete wilk;
		}
		else if (napotkany->getSila() <= sila)
		{
			cout << "Wilk zjada przeciwnika"<<endl;
			
			p->usunOrganizm(n);
			delete napotkany;
			x = i;
			y = j;
		}
	}
}