#pragma once
#include "Zwierze.h"

class Owca:public Zwierze{
public:
	Owca(Swiat* p);
	~Owca(){};
	void rozmnazanie();
	void kolizja(int a, int b);
};