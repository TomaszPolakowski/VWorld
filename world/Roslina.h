#pragma once
#include "Organizm.h"

class Roslina:public Organizm{
public:
	Roslina(Swiat *p);
	~Roslina(){};
	virtual void akcja();
	virtual void rozsianie(int i, int j){};
	int prawdopodobienstwo(double wspolczynnik_prawdopodobienstwa);	
};