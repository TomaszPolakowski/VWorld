#include "Organizm.h"

Organizm::Organizm(Swiat* p){
	this->p = p;
}

void Organizm::setXY(int x, int y){
	this->x = x;
	this->y = y;
}

void Organizm::setPionek(char pionek){
	this->pionek = pionek;
}

void Organizm::setUczestniczyl(bool n){
	uczestniczyl = n;
}

bool Organizm::getUczestniczyl(){
	return uczestniczyl;
}

int Organizm::getX(){
	return this->x;
}

int Organizm::getY(){
	return this->y;
}

char Organizm::getPionek(){
	return this->pionek;
}

int Organizm::getInicjatywa(){
	return this->inicjatywa;
}

int Organizm::getSila(){
	return this->sila;
}

int Organizm::losowanie(int &i, int &j)				//losuje liczbe
{
	int sasiednie_pola[8][2];
	sasiednie_pola[0][0] = (i - 1);
	sasiednie_pola[0][1] = (j - 1);
	sasiednie_pola[1][0] = i;
	sasiednie_pola[1][1] = (j - 1);
	sasiednie_pola[2][0] = (i + 1);
	sasiednie_pola[2][1] = (j - 1);
	sasiednie_pola[3][0] = (i - 1);
	sasiednie_pola[3][1] = j;
	sasiednie_pola[4][0] = (i + 1);
	sasiednie_pola[4][1] = j;
	sasiednie_pola[5][0] = (i - 1);
	sasiednie_pola[5][1] = (j + 1);
	sasiednie_pola[6][0] = i;
	sasiednie_pola[6][1] = (j + 1);
	sasiednie_pola[7][0] = (i + 1);
	sasiednie_pola[7][1] = (j + 1);

	int liczba_z_przedzialu = (rand() % 2);
	if (liczba_z_przedzialu == 0){
		while ((liczba_z_przedzialu = (rand() % (7 + 1))) >= 0)	//wylosowanie liczby z przedzialu [sasiednie pole na mapie]
		{
			if (sasiednie_pola[liczba_z_przedzialu][0] >= 0 && sasiednie_pola[liczba_z_przedzialu][0] < 20)
			{
				i = sasiednie_pola[liczba_z_przedzialu][0];
				return 0;
			}
		}
	}
	else if (liczba_z_przedzialu == 1){
		while ((liczba_z_przedzialu = (rand() % (7 + 1))) >= 0)
		{
			if (sasiednie_pola[liczba_z_przedzialu][1] >= 0 && sasiednie_pola[liczba_z_przedzialu][1] < 20)
			{
				j = sasiednie_pola[liczba_z_przedzialu][1];
				return 0;
			}
		}
	}
}

