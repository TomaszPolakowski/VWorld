#pragma once
#include "Zwierze.h"

class Zolw:public Zwierze{
public:
	Zolw(Swiat*p);
	~Zolw(){};
	void akcja();
	void rozmnazanie();
	void kolizja(int a, int b);
};