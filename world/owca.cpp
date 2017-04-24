#include "Owca.h"
#include "Swiat.h"

Owca::Owca(Swiat* p):Zwierze(p){
	sila = 4;
	inicjatywa = 4;
	pionek = 'O';
}

void Owca::rozmnazanie(){
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
		Organizm *nowy = new Owca(p);
		nowy->setXY(a, b);
		p->dodajOrganizm(nowy);
	}
}

void Owca::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* owca = p->znajdz(x, y, m);
	owca->setUczestniczyl(true);

	if (napotkany->getPionek() == 'O')
	{
		//rozmnazanie();
	}
	else if (napotkany->getPionek() != 'O'){
		if (napotkany->getSila() > sila)
		{
			cout << "Owca ginie"<<endl;
			getch();
			p->usunOrganizm(m);
			delete owca;
		}
		else if (napotkany->getSila() <= sila)
		{
			cout << "Owca zabija przeciwnika"<<endl;
			getch();
			p->usunOrganizm(n);
			delete napotkany;
			x = i;
			y = j;
		}
	}
}