#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(Swiat* p):Zwierze(p){
	sila = 5;
	inicjatywa = 4;
	x = 9;
	y = 9;
	czasMocy = 0;
	pionek = 'C';
}

void Czlowiek::akcja(){
	int zn;
	int tmpX = x;
	int tmpY = y;
	if (getSila() > 5)cout << "Twoja sila: " << getSila() << endl;
	zn = getch();
	if (zn == 0) {
		zmniejszStat();
		zn = getch();
		if (zn == 0x48 && tmpX != 0) tmpX--;
		else if (zn == 0x50 && tmpX != 19) tmpX++;
		else if (zn == 0x4b && tmpY != 0) tmpY--;
		else if (zn == 0x4d && tmpY != 19) tmpY++;
	}
	else if (zn == ' ' && this->czasMocy == 0) {
		cout << "Supermoc aktywna"<<endl;
		getch();
		setSila();
	}
	if (p->wolnePole(tmpX, tmpY) == true)
	{
		x = tmpX;
		y = tmpY;
	}
	else
	{
		kolizja(tmpX, tmpY);
	}
	
}

void Czlowiek::kolizja(int i, int j)
{
	int n = 0;
	Organizm* napotkany = p->znajdz(i, j, n);
	napotkany->setUczestniczyl(true);
	int m = 0;
	Organizm* czlowiek = p->znajdz(x, y, m);
	czlowiek->setUczestniczyl(true);

	if (napotkany->getSila() > sila)
	{
		cout << "Giniesz" << endl;
		getch();
		p->usunOrganizm(m);
		delete czlowiek;
	}
	else if (napotkany->getSila() < sila)
	{
		cout << "Zabijasz przeciwnika"<<endl;
		getch();
		p->usunOrganizm(n);
		delete napotkany;
		x = i;
		y = j;
	}
}

void Czlowiek::setSila(){
	this->sila = 20;
	this->czasMocy = 20;
}

void Czlowiek::zmniejszStat(){
	if (this->sila>5) this->sila--;
	if (this->czasMocy>0) this->czasMocy--;
}