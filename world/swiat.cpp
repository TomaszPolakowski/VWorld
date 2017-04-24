#include "Swiat.h"
#include "iostream"
#include "windows.h"

using namespace std;

Swiat::Swiat(){
	
}

void Swiat::rysujSwiat(){
	system("cls");
	for (int j = 0; j < ROZMIAR_SWIAT + 2; j++){
		for (int i = 0; i < ROZMIAR_SWIAT + 2; i++){
			if (i == 0 && j == 0) cout << (char)201;
			else if (i == ROZMIAR_SWIAT + 1 && j == 0) cout << (char)187;
			else if (i == ROZMIAR_SWIAT+1 && j == ROZMIAR_SWIAT+1) cout << (char)188;
			else if (i == 0 && j == ROZMIAR_SWIAT+1) cout << (char)200;
			else if (i>0 && i < ROZMIAR_SWIAT + 1 && (j == 0 || j == ROZMIAR_SWIAT + 1)) cout << (char)205;
			else if (j>0 && j < ROZMIAR_SWIAT + 1 && (i == 0 || i == ROZMIAR_SWIAT + 1)) cout << (char)186;
			else cout << teren[j-1][i-1];
		}
		cout << endl;
	}
}

void Swiat::start(){

	Organizm *czlowiek = new Czlowiek(this);
	czlowiek->setXY(9, 9);
	tablica.push_back(czlowiek);

	Organizm *wilk = new Wilk(this);
	wilk->setXY(2, 8);
	tablica.push_back(wilk);

	Organizm *wilk1 = new Wilk(this);
	wilk1->setXY(4, 10);
	tablica.push_back(wilk1);

	Organizm *owca = new Owca(this);
	owca->setXY(13, 5);
	tablica.push_back(owca);

	/*Organizm *owca1 = new Owca(this);
	owca1->setXY(19, 8);
	tablica.push_back(owca1);*/

	Organizm *lis = new Lis(this);
	lis->setXY(15, 16);
	tablica.push_back(lis);

	Organizm *lis1 = new Lis(this);
	lis1->setXY(0, 10);
	tablica.push_back(lis1);

	Organizm *zolw = new Zolw(this);
	zolw->setXY(12, 18);
	tablica.push_back(zolw);

	Organizm *zolw1 = new Zolw(this);
	zolw1->setXY(16, 18);
	tablica.push_back(zolw1);

	Organizm *antylopa = new Antylopa(this);
	antylopa->setXY(4, 4);
	tablica.push_back(antylopa);

	Organizm *trawa = new Trawa(this);
	trawa->setXY(12, 12);
	tablica.push_back(trawa);

	Organizm *trawa1 = new Trawa(this);
	trawa1->setXY(17, 9);
	tablica.push_back(trawa1);

	Organizm *mlecz = new Mlecz(this);
	mlecz->setXY(2, 5);
	tablica.push_back(mlecz);

	Organizm *guarana = new Guarana(this);
	guarana->setXY(19, 10);
	tablica.push_back(guarana);

	Organizm *guarana1 = new Guarana(this);
	guarana1->setXY(10, 3);
	tablica.push_back(guarana1);

	Organizm *jagody = new WilczeJagody(this);
	jagody->setXY(2, 18);
	tablica.push_back(jagody);
}

void Swiat::dodajOrganizm(Organizm* nowy)
{
	tablica.push_back(nowy);
}

void Swiat::usunOrganizm(int i)
{
	tablica.erase(tablica.begin() + i);
}

void Swiat::wypelnijTeren()
{
	for (int i = 0; i < ROZMIAR_SWIAT; i++)
	{
		for (int j = 0; j < ROZMIAR_SWIAT; j++)
		{
			teren[i][j] = ' ';
		}
	}

	for (int i = 0; i < tablica.size(); i++)
	{
		teren[tablica[i]->getX()][tablica[i]->getY()] = tablica[i]->getPionek();
	}
}

bool Swiat::wolnePole(int x, int y){
	if (teren[x][y] == ' ') return true;
	else return false;
}

void Swiat::wykonajTure(){

	wypelnijTeren();
	for (int i = 0; i <tablica.size(); i++)
	{
		tablica[i]->setUczestniczyl(false);
	}
	rysujSwiat();
	for (int i = 0; i < MAX_INICJATYWA+1; i++){
		for (int j = 0; j < tablica.size(); j++){
			if (tablica[j]->getInicjatywa() == i) {
				if (tablica[j]->getUczestniczyl() == false && tablica[j]!=NULL) 
					tablica[j]->akcja();
					tablica[j]->setUczestniczyl(true);
			}
		}
	}
	
}

Organizm* Swiat::znajdz(int x, int y, int &i)
{

	i = 0;
	while (i < tablica.size())
	{
		if (tablica[i]->getX() == x && tablica[i]->getY() == y)
		{
			return tablica[i];
		}
		i++;
	}
}

bool Swiat::czyZolw(int x, int y){
		for (int i = 0; i <tablica.size(); i++)
		{
			if (tablica[i]->getX() != x && tablica[i]->getY() != y)
			{
				if (tablica[i]->getPionek() == 'Z')
				{
					return true;
				}
				else
				{
					return false;
				}
			}

		}
}

bool Swiat::czyGuarana(int x, int y){
	for (int i = 0; i <tablica.size(); i++)
	{
		if (tablica[i]->getX() != x && tablica[i]->getY() != y)
		{
			if (tablica[i]->getPionek() == '@')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}