#pragma once
#include "Roslina.h"

class Guarana:public Roslina{
public:
	Guarana(Swiat *p);
	~Guarana(){};
	void rozsianie(int i, int j);
};