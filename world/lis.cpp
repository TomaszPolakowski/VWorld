#include "Lis.h"
#include "Swiat.h"

Lis::Lis(Swiat* p):Zwierze(p){
	sila = 3;
	inicjatywa = 7;
	pionek = 'L';
}

void Lis::rozmnazanie(){
	int a = -1, b = -1;

	if (p->wolnePole(x++, y) && x != 19) {
		a = x++; b = y;
	}
	if (p->wolnePole(x, y++) && y != 19) {
		a = x; b = y++;
	}
	if (p->wolnePole(x--, y) && x != 0) {
		a = x--; b = y;
	}
	if (p->wolnePole(x, y--) && y != 0) {
		a = x; b = y--;
	}
	if (a != -1 && b != -1){
		Organizm *nowy = new Lis(p);
		nowy->setXY(a, b);
		p->dodajOrganizm(nowy);
	}
}

void Lis::akcja(){
	int i = x;
	int j = y;
	losowanie(i, j);
	if (p->wolnePole(i, j) == true)
	{
		x = i;
		y = j;
	}
	else if (p->czyGuarana(i, j) == true){
		cout << "Lis zjada guarane, sila +3" << endl;
		
		setSila(sila + 3);
		kolizja(i, j);
	}
}

void Lis::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* lis = p->znajdz(x, y, m);
	lis->setUczestniczyl(true);

	if (napotkany->getPionek() == 'L')
	{
		//rozmnazanie();
	}
	else if (napotkany->getPionek() != 'L'){
		if (napotkany->getSila() > sila)
		{
			cout << "Lis ginie"<<endl;
			
			p->usunOrganizm(m);
			delete lis;
		}
		else if (napotkany->getSila() <= sila)
		{
			cout << "Lis zabija przeciwnika"<<endl;
			
			p->usunOrganizm(n);
			delete napotkany;
			x = i;
			y = j;
		}
	}
}