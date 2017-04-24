#pragma once
#include "Zwierze.h"

class Antylopa:public Zwierze{
public:
	Antylopa(Swiat*p);
	~Antylopa(){};
	void akcja();
	void rozmnazanie();
	void kolizja(int a, int b);
};

