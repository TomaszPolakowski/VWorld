#pragma once
#include "Zwierze.h"

class Lis:public Zwierze{
public:
	Lis(Swiat *p);
	~Lis(){};
	void akcja();
	void rozmnazanie();
	void kolizja(int a, int b);
};