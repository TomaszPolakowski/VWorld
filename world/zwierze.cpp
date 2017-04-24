#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(Swiat *p):Organizm(p){}

void Zwierze::setSila(int sila){
	this->sila = sila;
}

void Zwierze::akcja()
{
	int i = x;
	int j = y;
	losowanie(i, j);
	if (p->wolnePole(i, j) == true)
	{
		x = i;
		y = j;
	}
	else if (p->czyZolw(i, j) && sila < 5) {
		cout << "zolw odpiera atak"<<endl;
		
	}
	else if (p->czyGuarana(i, j) == true){	
		this->setSila(sila + 3);
		kolizja(i, j);
		cout << "Zwierze zjadlo guarane, sila +3" << endl;
	}
	else
	{
		kolizja(i, j);
	}
	setUczestniczyl(true);
}


