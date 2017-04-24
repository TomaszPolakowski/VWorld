#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(Swiat* p):Zwierze(p){
	sila = 2;
	inicjatywa = 1;
	pionek = 'Z';
}

void Zolw::akcja(){

	int szansa = (rand() % 4);
	if(szansa==2){
		int i = x;
		int j = y;
		losowanie(i, j);
		if (p->wolnePole(i, j) == true)
		{
			x = i;
			y = j;
		}
		else if (p->czyGuarana(i, j) == true){
			cout << "Zolw zjada guarane, sila +3"<<endl;
			
			this->setSila(sila + 3);
			kolizja(i, j);
		}
		else
		{
			kolizja(i, j);
		}
	}
}

void Zolw::rozmnazanie(){
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
		Organizm *nowy = new Zolw(p);
		nowy->setXY(a, b);
		p->dodajOrganizm(nowy);
	}
}

void Zolw::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* zolw = p->znajdz(x, y, m);
	zolw->setUczestniczyl(true);

	if (napotkany->getPionek() == 'Z')
	{
		//rozmnazanie();
	}
	else if (napotkany->getPionek() != 'Z'){
		if (napotkany->getSila() >= 5)
		{
			cout << "Zolw ginie"<<endl;
			
			p->usunOrganizm(m);
			delete zolw;
		}
		else if (napotkany->getSila() < sila)
		{
			cout << "Zolw zabija przeciwnika"<<endl;
			
			p->usunOrganizm(n);
			delete napotkany;
			x = i;
			y = j;
		}
	}
}