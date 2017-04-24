#pragma once
#include "Organizm.h"
#include "time.h"
#include "stdlib.h"

class Zwierze:public Organizm{
public:
	Zwierze(Swiat *p);
	~Zwierze(){};
	virtual void akcja();
	virtual void kolizja(int a, int b){};
	virtual void rozmnazanie(){};
	void setSila(int sila);
};

