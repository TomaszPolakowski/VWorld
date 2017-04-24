#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(Swiat* p):Zwierze(p){
	sila = 4;
	inicjatywa = 4;
	setPionek('A');
}

void Antylopa::akcja(){

	int tmpX = x;
	int tmpY = y;

	srand(time(NULL));

	int xy = rand() % 2;
	int kierunek = rand() % 2;

	if (xy == 0) // poruszaj sie po x
	{
		if (kierunek == 0 && tmpX >1) tmpX-=2;
		else if (kierunek == 0 && tmpX==1) tmpX -= 1;
		else if (kierunek == 0 && tmpX == 0) tmpX += 2;// lewo
		else if (kierunek == 1 && tmpX < 18) tmpX+=2;
		else if (kierunek == 1 && tmpX == 18) tmpX += 1;//prawo
		else if (kierunek == 1 && tmpX == 19) tmpX -= 2;
	}
	if (xy == 1) // poruszaj sie po y
	{
		if (kierunek == 0 && tmpY > 1) tmpY-=2;//gora
		else if (kierunek == 0 && tmpY == 1) tmpY -= 1;
		else if (kierunek == 0 && tmpY == 0) tmpY += 2;
		else if (kierunek == 1 && tmpY < 18) tmpY+=2; //dol
		else if (kierunek == 1 && tmpY == 18) tmpY += 1;
		else if (kierunek == 1 && tmpY == 19) tmpY -= 2;
	}
	else if (p->czyGuarana(tmpX, tmpY) == true){
		cout << "Antylopa zjada guarane, sila +3"<<endl;
		
		this->setSila(sila + 3);
		kolizja(tmpX, tmpY);
	}
	if (p->wolnePole(tmpX, tmpY) == false && this->sila>4) kolizja(tmpX, tmpY);
	else if (p->wolnePole(tmpX, tmpY) == false && p->czyZolw(tmpX, tmpY) == false) kolizja(tmpX, tmpY);
	else if (p->wolnePole(tmpX, tmpY) == false && p->czyZolw(tmpX, tmpY) == true && this->sila < 5);
	else {
		x = tmpX;
		y = tmpY;
	}
}

void Antylopa::rozmnazanie(){
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
		Organizm *nowy = new Antylopa(p);
		nowy->setXY(a, b);
		p->dodajOrganizm(nowy);
	}
}

void Antylopa::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* antylopa = p->znajdz(x, y, m);
	antylopa->setUczestniczyl(true);

	if (napotkany->getPionek() == 'A')
	{
		//rozmnazanie();
	}
	else if (napotkany->getPionek() != 'A'){
		if (napotkany->getSila() > sila && x % 2 == 0)
		{
			cout << "Antylopa ginie" << endl;;
			
			p->usunOrganizm(m);
			delete antylopa;
		}
		else if (napotkany->getSila() > sila && x % 2 == 1) {
			cout << "Antylopie udaje sie uciec"<<endl;
			
			antylopa->akcja();
		}
		else if (napotkany->getSila() <= sila)
		{
			cout << "Antylopa zabija przeciwnika"<<endl;
			
			p->usunOrganizm(n);
			delete napotkany;
			x = i;
			y = i;
		}
	}
}