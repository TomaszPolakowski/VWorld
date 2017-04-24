#pragma once
#include "Zwierze.h"

class Wilk:public Zwierze{
public:
	Wilk(Swiat* p);
	~Wilk(){};
	void rozmnazanie();
	void kolizja(int a, int b);
};